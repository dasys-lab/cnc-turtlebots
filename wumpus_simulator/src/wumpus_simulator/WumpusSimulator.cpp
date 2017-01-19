#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>
#include "model/Simulator.h"
#include <qgridlayout.h>
#include <QUrl>
#include <QtNetwork/qnetworkproxy.h>
#include <QtWebKitWidgets/qwebinspector.h>
#include <QtWebKitWidgets/qwebframe.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include "model/GroundTile.h"
#include "model/Agent.h"

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0)
	{
		setObjectName("WumpusSimulator");
		this->sim = nullptr;

		spawnAgentSub = n.subscribe("/wumpus_simulator/SpawnAgentRequest", 10, &WumpusSimulator::onSpawnAgent,
									(WumpusSimulator*)this);
		actionSub = n.subscribe("/wumpus_simulator/ActionRequest", 10, &WumpusSimulator::onAction, (WumpusSimulator*)this);

		spawnAgentPub = n.advertise<wumpus_simulator::InitialPose>("/wumpus_simulator/SpawnAgentResponse", 10);
		actionPub = n.advertise<wumpus_simulator::Action>("/wumpus_simulator/ActionResponse", 10);

		spinner = new ros::AsyncSpinner(4);
		spinner->start();
		this->ready = false;
	}

	WumpusSimulator::~WumpusSimulator()
	{
	}

	void WumpusSimulator::initPlugin(qt_gui_cpp::PluginContext& context)
	{

		this->widget_ = new QWidget();
		this->widget_->setAttribute(Qt::WA_AlwaysShowToolTips, true);
		this->mainwindow.setupUi(this->widget_);

		if (context.serialNumber() > 1)
		{
			this->widget_->setWindowTitle(
					this->widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
		}
		context.addWidget(this->widget_);

		//Allow to show a inspector in the web view, nice inline debugging of javascript
		this->mainwindow.webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
		QWebInspector inspector;
		inspector.setPage(this->mainwindow.webView->page());
		inspector.setVisible(true);

		//Initialize web view
		connect(this->mainwindow.webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this,
				SLOT(addSimToJS()));
		this->mainwindow.webView->load(QUrl("qrc:///www/index.html"));
		connect(this, SIGNAL(modelChanged()), this, SLOT(callUpdatePlayground()));
		ready = false;
	}

	void WumpusSimulator::shutdownPlugin()
	{
	}

	void WumpusSimulator::saveSettings(qt_gui_cpp::Settings& plugin_settings,
										qt_gui_cpp::Settings& instance_settings) const
	{
	}

	void WumpusSimulator::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
											const qt_gui_cpp::Settings& instance_settings)
	{
	}

	Simulator* WumpusSimulator::getSim()
	{
		return this->sim;
	}

	void WumpusSimulator::addSimToJS()
	{
		this->mainwindow.webView->page()->mainFrame()->addToJavaScriptWindowObject("wumpus_simulator", this);
	}

	void WumpusSimulator::createWorld(bool arrow, int wumpus, int traps, int size)
	{

		cout << "WumpusSimulator: Creating world with: arrow: " << (arrow ? "true" : "false") << " wumpus count: "
				<< wumpus << " trap count: " << traps << " field size: " << size << endl;
		//Init the playground
		this->sim = Simulator::get();
		this->sim->init(arrow, wumpus, traps, size);
		updatePlayground();
		ready = true;

	}

	void WumpusSimulator::saveWorld()
	{

		//Open save file dialog to select a pregenerated wumpus world
		QString filename = QFileDialog::getSaveFileName(this->widget_, tr("Save World"), QDir::currentPath(),
														tr("Wumpus World File (*.wwf)"), 0,
														QFileDialog::DontUseNativeDialog);

		if (!filename.endsWith(".wwf"))
		{
			filename += ".wwf";
		}

		//Check if the user selected a correct file
		if (!filename.isNull())
		{

			//Create file
			QFile file(filename);

			if (!file.open(QIODevice::WriteOnly))
			{
				qWarning("Couldn't open save file.");
				return;
			}

			//Serialize the world as JSON
			auto worldJson = this->sim->toJSON();

			//Write to file
			QJsonDocument saveDoc(worldJson);
			file.write(saveDoc.toJson());

		}
	}

	void WumpusSimulator::loadWorld()
	{
		this->sim = Simulator::get();
		//Open load file dialog to select a pregenerated wumpus world
		QString filename = QFileDialog::getOpenFileName(this->widget_, tr("Load World"), QDir::currentPath(),
														tr("Wumpus World File (*.wwf)"), 0,
														QFileDialog::DontUseNativeDialog);

		//Check if the user selected a correct file
		if (!filename.isNull())
		{
			//Open file
			QFile file(filename);
			if (!file.open(QIODevice::ReadOnly))
			{
				qWarning("Couldn't open save file.");
				return;
			}

			QByteArray saveData = file.readAll();
			QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
			this->sim->fromJSON(loadDoc.object());
			this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(
					QString("setInitialValues(%1, %2, %3, %4);").arg(this->sim->getWumpusCount()).arg(
							this->sim->getTrapCount()).arg(this->sim->getPlayGroundSize()).arg(
							this->sim->isAgentHasArrow()));
			this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(QString("drawPlayground();"));
			updatePlayground();

		}
	}

	void WumpusSimulator::updatePlayground()
	{
		QString clear = QString("clearTiles();");
		auto playGround = this->sim->getPlayGround();
		this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(clear);
		for (int i = 0; i < this->sim->getPlayGroundSize(); i++)
		{
			for (int j = 0; j < this->sim->getPlayGroundSize(); j++)
			{
				QString f = QString("addDirtImage(%1,%2);").arg(i).arg(j);
				this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(f);
				if (playGround.at(i).at(j)->getStench())
				{
					QString func = QString("addStenchImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
				if (playGround.at(i).at(j)->getBreeze())
				{
					QString func = QString("addBreezeImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}

				if (playGround.at(i).at(j)->getTrap())
				{
					QString func = QString("addTrapImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
				if (playGround.at(i).at(j)->hasMovable())
				{
					if (playGround.at(i).at(j)->getMovable()->getType().contains("wumpus"))
					{
						QString func = QString("addWumpusImage(%1,%2);").arg(i).arg(j);
						this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
					}
					if (playGround.at(i).at(j)->getMovable()->getType().contains("agent"))
					{
						if (playGround.at(i).at(j)->getMovable()->getId() % 2 == 0)
						{
							QString func = QString("addFemaleAgent(%1,%2,%3);").arg(i).arg(j).arg(
									playGround.at(i).at(j)->getMovable()->getId());
							this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
						}
						else
						{
							QString func = QString("addMaleAgent(%1,%2,%3);").arg(i).arg(j).arg(
									playGround.at(i).at(j)->getMovable()->getId());
							this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
						}
					}
				}
				if (playGround.at(i).at(j)->getGold())
				{
					QString func = QString("addGoldImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
				if (playGround.at(i).at(j)->getStartpoint())
				{
					QString func = QString("addEntryPoint(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
			}
		}
	}

	void WumpusSimulator::onSpawnAgent(InitialPosePtr msg)
	{
		if(!ready)
		{
			return;
		}
		placeAgent(msg->agentId, msg->hasArrow);
	}

	void WumpusSimulator::callUpdatePlayground()
	{
		updatePlayground();
	}

	void WumpusSimulator::onAction(ActionPtr msg)
	{
		if(!ready)
		{
			return;
		}

	}

	void WumpusSimulator::placeAgent(int agentId, bool hasArrow)
	{
		for (int i = 0; i < sim->movables.size(); i++)
		{
			if (this->sim->movables.at(i)->getId() == agentId)
			{
				cout << "WumpusSimulator: Agent with this id already placed!" << endl;
				return;
			}
		}
		/* initialize random seed: */
		srand(time(NULL));
		bool placed = false;
		InitialPose msg;
		while (!placed)
		{
			int randx = rand() % (this->sim->getPlayGroundSize() - 1);
			int randy = rand() % (this->sim->getPlayGroundSize() - 1);

			auto tile = this->sim->getPlayGround().at(randx).at(randy);
			if (!tile->getTrap() && !tile->hasMovable() && !tile->getGold() && !tile->getBreeze() && !tile->getStench()
					&& !tile->getStartpoint())
			{
				this->sim->getPlayGround().at(randx).at(randy)->setStartAgentID(agentId);
				auto agent = make_shared<Agent>(this->sim->getPlayGround().at(randx).at(randy));
				agent->setId(agentId);
				agent->setArrow(hasArrow);
				this->sim->getPlayGround().at(randx).at(randy)->setMovable(agent);
				this->sim->movables.push_back(agent);
				tile->setStartAgentID(agentId);
				tile->setStartpoint(true);
				placed = true;
				msg.x = randx;
				msg.y = randy;
				msg.agentId = agentId;
				msg.fieldSize = this->sim->getPlayGroundSize();
				msg.hasArrow = hasArrow;
				this->spawnAgentPub.publish(msg);
			}
		}
		emit modelChanged();
	}

}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)
