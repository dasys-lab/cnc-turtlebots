#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>
#include "model/Simulator.h"
#include <qgridlayout.h>
#include <QUrl>
#include <QtNetwork/qnetworkproxy.h>
#include <QtWebKitWidgets/qwebinspector.h>
#include <QtWebKitWidgets/qwebframe.h>
#include "model/GroundTile.h"

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0)
	{
		setObjectName("WumpusSimulator");
		this->sim = nullptr;
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

	}

	void WumpusSimulator::updatePlayground()
	{
		QString clear = QString("clearTiles();");
		this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(clear);
		auto playGround = this->sim->getPlayGround();
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
				if (playGround.at(i).at(j)->hasWumpus())
				{
					QString func = QString("addWumpusImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
				if (playGround.at(i).at(j)->getGold())
				{
					QString func = QString("addGoldImage(%1,%2);").arg(i).arg(j);
					this->mainwindow.webView->page()->mainFrame()->evaluateJavaScript(func);
				}
			}
		}
	}
}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)
