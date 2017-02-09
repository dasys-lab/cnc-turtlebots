#include <model/Model.h>
#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>
#include <qgridlayout.h>
#include <QUrl>
#include <QtNetwork/qnetworkproxy.h>
#include <QtWebKitWidgets/qwebinspector.h>
#include <QtWebKitWidgets/qwebframe.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include "model/GroundTile.h"
#include "model/Agent.h"
#include <model/Wumpus.h>
#include <model/Movable.h>
#include <memory>

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0)
	{
		setObjectName("WumpusSimulator");
		this->model = nullptr;
		turnIndex = 0;

		spawnAgentSub = n.subscribe("/wumpus_simulator/SpawnAgentRequest", 10, &WumpusSimulator::onSpawnAgent,
									(WumpusSimulator*)this);
		actionSub = n.subscribe("/wumpus_simulator/ActionRequest", 10, &WumpusSimulator::onAction,
								(WumpusSimulator*)this);

		spawnAgentPub = n.advertise<wumpus_simulator::InitialPoseResponse>("/wumpus_simulator/SpawnAgentResponse", 10);
		actionPub = n.advertise<wumpus_simulator::ActionResponse>("/wumpus_simulator/ActionResponse", 10);

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

	Model* WumpusSimulator::getModel()
	{
		return this->model;
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
		this->model = Model::get();
		this->model->init(arrow, wumpus, traps, size);
		updatePlayground();
		ready = true;
	}

	void WumpusSimulator::saveWorld()
	{

		//Open save file dialog to select a pregenerated wumpus world
		QString filename = QFileDialog::getSaveFileName(this->widget_, tr("Save World"), QDir::currentPath(),
														tr("Wumpus World File (*.wwf)"), 0,
														QFileDialog::DontUseNativeDialog);

		if (!filename.isNull())
		{
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
				auto worldJson = this->model->toJSON();

				//Write to file
				QJsonDocument saveDoc(worldJson);
				file.write(saveDoc.toJson());

			}
		}
	}

	void WumpusSimulator::loadWorld()
	{
		this->model = Model::get();
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
			this->model->fromJSON(loadDoc.object());
			this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(
					QString("setInitialValues(%1, %2, %3, %4);").arg(this->model->getWumpusCount()).arg(
							this->model->getTrapCount()).arg(this->model->getPlayGroundSize()).arg(
							this->model->isAgentHasArrow()));
			this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(QString("drawPlayground();"));
			updatePlayground();
			ready = true;
		}
	}

	void WumpusSimulator::updatePlayground()
	{
		QString clear = QString("clearTiles();");
		auto playGround = this->model->getPlayGround();
		this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(clear);
		for (int i = 0; i < this->model->getPlayGroundSize(); i++)
		{
			for (int j = 0; j < this->model->getPlayGroundSize(); j++)
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
				if (playGround.at(i).at(j)->hasMovable())
				{
					if (playGround.at(i).at(j)->getMovable()->getType().contains("wumpus"))
					{
						QString func = QString("addWumpusImage(%1,%2);").arg(i).arg(j);
						this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
					}
					if (playGround.at(i).at(j)->getMovable()->getType().contains("agent"))
					{
						auto tmp = dynamic_pointer_cast<Agent>(playGround.at(i).at(j)->getMovable());
						if (tmp == nullptr)
						{
							continue;
						}

						if (playGround.at(i).at(j)->getMovable()->getId() % 2 == 0)
						{
							QString func = QString("addAgent(%1,%2,%3,%4,%5);").arg(i).arg(j).arg(
									playGround.at(i).at(j)->getMovable()->getId()).arg("\"female\"").arg(
									tmp->getHeading());
							this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
						}
						else
						{
							QString func = QString("addAgent(%1,%2,%3,%4,%5);").arg(i).arg(j).arg(
									playGround.at(i).at(j)->getMovable()->getId()).arg("\"male\"").arg(
									tmp->getHeading());
							this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
						}
					}
				}
			}
		}
	}

	void WumpusSimulator::onSpawnAgent(InitialPoseRequestPtr msg)
	{
		if (!ready)
		{
			return;
		}
		if (msg->agentId > 0)
		{
			placeAgent(msg->agentId, this->model->isAgentHasArrow());
		}
		else if (msg->agentId < 0)
		{
			possessWumpus(msg->agentId);
		}
		else
		{
			cout << "WumpusSimulator: ID = 0 not supported!" << endl;
		}
	}

	void WumpusSimulator::callUpdatePlayground()
	{
		updatePlayground();
	}

	void WumpusSimulator::onAction(ActionRequestPtr msg)
	{
		if (!ready)
		{
			return;
		}
		if(msg->agentId != this->turns.at(this->turnIndex))
		{
			cout << "WumpusSimulator: agent is not allowed to move! It's agent's " << this->turns.at(this->turnIndex) << " turn!" << endl;
			return;
		}
		bool found = false;
		for (auto mov : this->model->movables)
		{
			if (msg->agentId == mov->getId())
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			if (msg->agentId > 0)
			{
				handleAction(msg);
			}
			else
			{
				handleWumpusAction(msg);
			}
		}

	}

	void WumpusSimulator::possessWumpus(int wumpusId)
	{
		for (int i = 0; i < model->movables.size(); i++)
		{
			if (this->model->movables.at(i)->getId() == wumpusId)
			{
				cout << "WumpusSimulator: Wumpus with this id already possessed!" << endl;
				return;
			}
		}
		bool available = false;
		for (auto mov : this->model->movables)
		{
			if (mov->getId() == 0)
			{
				mov->setId(wumpusId);
				turns.push_back(wumpusId);
				available = true;
				break;
			}
		}
		if (!available)
		{
			cout << "WumpusSimulator: no Wumpus available!" << endl;
		}
	}

	void WumpusSimulator::placeAgent(int agentId, bool hasArrow)
	{
		for (int i = 0; i < model->movables.size(); i++)
		{
			if (this->model->movables.at(i)->getId() == agentId)
			{
				cout << "WumpusSimulator: Agent with this id already placed!" << endl;
				return;
			}
		}
		/* initialize random seed: */
		srand(time(NULL));
		bool placed = false;
		InitialPoseResponse msg;
		int attempts = 0;
		while (!placed)
		{
			if(attempts > (model->getPlayGroundSize() * model->getPlayGroundSize())) {
				cout << "Abort! Cannot find empty tile to place agent on." << endl;
				break;
			}
			int randx = rand() % (this->model->getPlayGroundSize() - 1);
			int randy = rand() % (this->model->getPlayGroundSize() - 1);

			auto tile = this->model->getPlayGround().at(randx).at(randy);
			if (!tile->getTrap() && !tile->hasMovable() && !tile->getGold() && !tile->getBreeze() && !tile->getStench()
					&& !tile->getStartpoint())
			{
				auto agent = make_shared<Agent>(this->model->getPlayGround().at(randx).at(randy));
				agent->setId(agentId);
				agent->setArrow(hasArrow);
				agent->setHeading(WumpusEnums::heading::up);
				this->model->getPlayGround().at(randx).at(randy)->setMovable(agent);
				this->model->movables.push_back(agent);
				tile->setStartAgentID(agentId);
				tile->setStartpoint(true);
				placed = true;
				msg.x = randx;
				msg.y = randy;
				msg.agentId = agentId;
				msg.fieldSize = this->model->getPlayGroundSize();
				msg.hasArrow = hasArrow;
				msg.heading = agent->getHeading();
				this->spawnAgentPub.publish(msg);
				turns.push_back(agent->getId());
				if(turns.size() == 1)
				{
					ActionResponse msg2;
					msg2.x = agent->getTile()->getX();
					msg2.y = agent->getTile()->getY();
					msg2.agentId = agent->getId();
					msg2.heading = agent->getHeading();
					msg2.responses.push_back(WumpusEnums::responses::yourTurn);
				}
			}
			attempts++;
		}
		emit modelChanged();
	}

	void WumpusSimulator::handleTurnRight(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		auto tmp = (((agent->getHeading() - 1) + 4) % 4);
		agent->setHeading((WumpusEnums::heading)(tmp));
		response.agentId = agent->getId();
		response.x = agent->getTile()->getX();
		response.y = agent->getTile()->getY();
		response.heading = tmp;
		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handleTurnLeft(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		auto tmp = ((agent->getHeading() + 1) % 4);
		agent->setHeading((WumpusEnums::heading)(tmp));
		response.agentId = agent->getId();
		response.x = agent->getTile()->getX();
		response.y = agent->getTile()->getY();
		response.heading = tmp;
		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handleShoot(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		response.agentId = agent->getId();
		response.x = agent->getTile()->getX();
		response.y = agent->getTile()->getY();
		response.heading = agent->getHeading();
		bool wumpusDead = false;
		if (agent->hasArrow())
		{
			if (agent->getHeading() == WumpusEnums::heading::left)
			{
				if (agent->getTile()->getY() == 0)
				{
					response.responses.push_back(WumpusEnums::responses::silence);
				}
				else
				{
					for (int i = agent->getTile()->getY() - 1; i >= 0; i--)
					{
						if (this->getModel()->getPlayGround().at(agent->getTile()->getX()).at(i)->hasWumpus())
						{
							wumpusDead = true;
							this->getModel()->removeWumpus(
									dynamic_pointer_cast<Wumpus>(
											this->getModel()->getPlayGround().at(agent->getTile()->getX()).at(i)->getMovable()));
						}
					}
					if (wumpusDead)
					{
						response.responses.push_back(WumpusEnums::responses::scream);
					}
					else
					{
						response.responses.push_back(WumpusEnums::responses::silence);
					}
				}
			}
			else if (agent->getHeading() == WumpusEnums::heading::right)
			{
				if (agent->getTile()->getY() == this->model->getPlayGroundSize() - 1)
				{
					response.responses.push_back(WumpusEnums::responses::silence);
				}
				else
				{
					for (int i = agent->getTile()->getY() + 1; i <= this->model->getPlayGroundSize() - 1; i++)
					{
						if (this->getModel()->getPlayGround().at(agent->getTile()->getX()).at(i)->hasWumpus())
						{
							wumpusDead = true;
							this->getModel()->removeWumpus(
									dynamic_pointer_cast<Wumpus>(
											this->getModel()->getPlayGround().at(agent->getTile()->getX()).at(i)->getMovable()));
						}
					}
					if (wumpusDead)
					{
						response.responses.push_back(WumpusEnums::responses::scream);
					}
					else
					{
						response.responses.push_back(WumpusEnums::responses::silence);
					}
				}
			}
			else if (agent->getHeading() == WumpusEnums::heading::up)
			{
				if (agent->getTile()->getX() == 0)
				{
					response.responses.push_back(WumpusEnums::responses::silence);
				}
				else
				{
					for (int i = agent->getTile()->getX() - 1; i >= 0; i--)
					{
						if (this->getModel()->getPlayGround().at(i).at(agent->getTile()->getY())->hasWumpus())
						{
							wumpusDead = true;
							this->getModel()->removeWumpus(
									dynamic_pointer_cast<Wumpus>(
											this->getModel()->getPlayGround().at(i).at(agent->getTile()->getY())->getMovable()));
						}
					}
					if (wumpusDead)
					{
						response.responses.push_back(WumpusEnums::responses::scream);
					}
					else
					{
						response.responses.push_back(WumpusEnums::responses::silence);
					}
				}
			}
			else
			{
				if (agent->getTile()->getX() == this->model->getPlayGroundSize() - 1)
				{
					response.responses.push_back(WumpusEnums::responses::silence);
				}
				else
				{
					for (int i = agent->getTile()->getX() + 1; i <= this->model->getPlayGroundSize() - 1; i++)
					{
						if (this->getModel()->getPlayGround().at(i).at(agent->getTile()->getY())->hasWumpus())
						{
							wumpusDead = true;
							this->getModel()->removeWumpus(
									dynamic_pointer_cast<Wumpus>(
											this->getModel()->getPlayGround().at(i).at(agent->getTile()->getY())->getMovable()));
						}
					}
					if (wumpusDead)
					{
						response.responses.push_back(WumpusEnums::responses::scream);
					}
					else
					{
						response.responses.push_back(WumpusEnums::responses::silence);
					}
				}
			}

			agent->setArrow(false);
			if (agent->getTile()->getGold())
			{
				response.responses.push_back(WumpusEnums::responses::shiny);
			}
			if (agent->getTile()->getBreeze())
			{
				response.responses.push_back(WumpusEnums::responses::drafty);
			}
			if (agent->getTile()->getStench())
			{
				response.responses.push_back(WumpusEnums::responses::stinky);
			}
		}
		else
		{
			response.responses.push_back(WumpusEnums::responses::notAllowed);
			if (agent->getTile()->getGold())
			{
				response.responses.push_back(WumpusEnums::responses::shiny);
			}
			if (agent->getTile()->getBreeze())
			{
				response.responses.push_back(WumpusEnums::responses::drafty);
			}
			if (agent->getTile()->getStench())
			{
				response.responses.push_back(WumpusEnums::responses::stinky);
			}
		}
		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handlePickUpGold(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		response.agentId = agent->getId();
		response.x = agent->getTile()->getX();
		response.y = agent->getTile()->getY();
		response.heading = agent->getHeading();
		if (agent->getTile()->getGold())
		{
			response.responses.push_back(WumpusEnums::responses::goldFound);
			agent->setHasGold(true);
		}
		else
		{
			response.responses.push_back(WumpusEnums::responses::notAllowed);
		}
		if (agent->getTile()->getBreeze())
		{
			response.responses.push_back(WumpusEnums::responses::drafty);
		}
		if (agent->getTile()->getStench())
		{
			response.responses.push_back(WumpusEnums::responses::stinky);
		}
		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handleExit(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		response.agentId = agent->getId();
		response.x = agent->getTile()->getX();
		response.y = agent->getTile()->getY();
		response.heading = agent->getHeading();
		cout << "handleExit: " << agent->getTile()->getStartAgentID() << " : " << agent->getId() << " : "
				<< agent->getHasGold() << endl;
		if (agent->getHasGold() && agent->getTile()->getStartAgentID() == agent->getId())
		{
			response.responses.push_back(WumpusEnums::responses::exited);
			this->model->exit(agent);
		}
		else
		{
			response.responses.push_back(WumpusEnums::responses::notAllowed);
		}
		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handleMove(ActionRequestPtr msg)
	{
		ActionResponse response;
		auto agent = this->model->getAgentByID(msg->agentId);
		response.agentId = agent->getId();
		int x = agent->getTile()->getX();
		int y = agent->getTile()->getY();
		if ((x == 0 && agent->getHeading() == WumpusEnums::heading::up)
				|| (x == this->model->getPlayGroundSize() - 1 && agent->getHeading() == WumpusEnums::heading::down)
				|| (y == 0 && agent->getHeading() == WumpusEnums::heading::left)
				|| (y == this->model->getPlayGroundSize() - 1 && agent->getHeading() == WumpusEnums::heading::right))
		{
			response.x = x;
			response.y = y;
			response.heading = agent->getHeading();
			response.responses.push_back(WumpusEnums::responses::bump);
		}
		else
		{
			if (agent->getHeading() == WumpusEnums::heading::up)
			{
				x -= 1;
			}
			else if (agent->getHeading() == WumpusEnums::heading::down)
			{
				x += 1;
			}
			else if (agent->getHeading() == WumpusEnums::heading::left)
			{
				y -= 1;
			}
			else
			{
				y += 1;
			}

			response.x = x;
			response.y = y;
			response.heading = agent->getHeading();

			if (this->model->getTile(x, y)->getTrap() || this->model->getTile(x, y)->hasWumpus())
			{
				cout << 1 << endl;
				response.responses.push_back(WumpusEnums::responses::dead);
				this->model->exit(agent);
			}
			else if (this->model->getTile(x, y)->hasMovable() && !this->model->getTile(x, y)->hasWumpus())
			{
				response.x = agent->getTile()->getX();
				response.y = agent->getTile()->getY();
				response.responses.push_back(WumpusEnums::responses::otherAgent);
			}
			else
			{
				this->model->removeAgent(agent);
				agent->setTile(this->model->getTile(x, y));
				agent->getTile()->setMovable(agent);
			}
		}
		auto tmp = this->model->getTile(x, y);
		if (tmp->getGold())
		{
			response.responses.push_back(WumpusEnums::responses::shiny);
		}
		if (tmp->getBreeze())
		{
			response.responses.push_back(WumpusEnums::responses::drafty);
		}
		if (tmp->getStench())
		{
			response.responses.push_back(WumpusEnums::responses::stinky);
		}

		this->actionPub.publish(response);
		emit modelChanged();
	}

	void WumpusSimulator::handleWumpusAction(ActionRequestPtr msg)
	{
		if (!(msg->action == WumpusEnums::heading::up || msg->action == WumpusEnums::heading::down
				|| msg->action == WumpusEnums::heading::left || msg->action == WumpusEnums::heading::right))
		{

			cout << "WumpusSimulator: unknown Action received" << endl;
			return;
		}

		ActionResponse response;
		auto wumpus = this->model->getWumpusByID(msg->agentId);
		response.agentId = wumpus->getId();
		int x = wumpus->getTile()->getX();
		int y = wumpus->getTile()->getY();
		if ((x == 0 && msg->action == WumpusEnums::heading::up)
				|| (x == this->model->getPlayGroundSize() - 1 && msg->action == WumpusEnums::heading::down)
				|| (y == 0 && msg->action == WumpusEnums::heading::left)
				|| (y == this->model->getPlayGroundSize() - 1 && msg->action == WumpusEnums::heading::right))
		{
			response.x = x;
			response.y = y;
			response.heading = WumpusEnums::heading::down;
			response.responses.push_back(WumpusEnums::responses::bump);
		}
		else
		{
			if (msg->action == WumpusEnums::heading::up)
			{
				x -= 1;
			}
			else if (msg->action == WumpusEnums::heading::down)
			{
				x += 1;
			}
			else if (msg->action == WumpusEnums::heading::left)
			{
				y -= 1;
			}
			else
			{
				y += 1;
			}

			response.x = x;
			response.y = y;
			response.heading = WumpusEnums::heading::down;

			if (this->model->getTile(x, y)->hasWumpus())
			{
				response.x = wumpus->getTile()->getX();
				response.y = wumpus->getTile()->getY();
				response.responses.push_back(WumpusEnums::responses::otherAgent);
			}

			if (this->model->getTile(x, y)->hasMovable() && !this->model->getTile(x, y)->hasWumpus())
			{
				auto tmp = dynamic_pointer_cast<Agent>(this->model->getTile(x, y)->getMovable());
				this->model->exit(tmp);
				//TODO tell agent
				response.responses.push_back(WumpusEnums::responses::killedAgent);
			}

			this->model->removeWumpus(wumpus);
			wumpus->setTile(this->model->getTile(x, y));
			wumpus->getTile()->setMovable(wumpus);
			this->model->setStench(x,y, wumpus);

		}
		this->actionPub.publish(response);
		//TODO call next agent
		emit modelChanged();

	}

	void WumpusSimulator::handleAction(ActionRequestPtr msg)
	{

		switch (msg->action)
		{
			case WumpusEnums::actions::move:
			{
				handleMove(msg);
				break;
			}
			case WumpusEnums::actions::leave:
			{
				handleExit(msg);
				//TODO remove from turns
				break;
			}
			case WumpusEnums::actions::pickUpGold:
			{
				handlePickUpGold(msg);
				break;
			}
			case WumpusEnums::actions::shoot:
			{
				handleShoot(msg);
				//TODO remove wumpuses from turn
				break;
			}
			case WumpusEnums::actions::turnLeft:
			{
				handleTurnLeft(msg);
				break;
			}
			case WumpusEnums::actions::turnRight:
			{
				handleTurnRight(msg);
				break;
			}

			default:
				cout << "WumpusSimulator: unknown Action received" << endl;
				break;
		}
		//TODO call next agent

	}

	void WumpusSimulator::getNext()
	{
		this->turnIndex++;
		this->turnIndex = turnIndex % this->turns.size();
	}

}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)
