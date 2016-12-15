#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>
#include "wumpus_simulator/SettingsDialog.h"
#include "model/Simulator.h"
#include <qgridlayout.h>
#include <qrect.h>
#include <QtWebKitWidgets/QWebView>

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0)
	{
		cout <<"test" << endl;
		setObjectName("WumpusSimulator");
	}

	WumpusSimulator::~WumpusSimulator()
	{
	}

	void WumpusSimulator::initPlugin(qt_gui_cpp::PluginContext& context)
	{

		cout <<"test" << endl;
		this->widget_ = new QWidget();
		this->widget_->setAttribute(Qt::WA_AlwaysShowToolTips, true);
		this->mainwindow.setupUi(this->widget_);


		if (context.serialNumber() > 1)
		{
			this->widget_->setWindowTitle(
					this->widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
		}
		context.addWidget(this->widget_);
		//TODO: Add a modal to the ui
//		connect(this->mainwindow.settingsBtn, SIGNAL(released()), SLOT(settingsBtn()));
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

//	void WumpusSimulator::settingsBtn()
//	{
//		auto settingsDialog = new SettingsDialog(this->widget_, this);
//		settingsDialog->exec();
//	}

	void WumpusSimulator::createWorld(bool arrow, string size, string traps, string wumpus)
	{

		//Init the playground
		Simulator::get()->init(stoi(size), stoi(wumpus), stoi(traps), arrow);

		//Load grid



	}
}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)
