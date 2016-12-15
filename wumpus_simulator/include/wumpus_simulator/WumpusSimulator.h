#ifndef WUMPUSSIMULATOR_H
#define WUMPUSSIMULATOR_H

#include <rqt_gui_cpp/plugin.h>

#include "ros/ros.h"
#include <ros/macros.h>
#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <iostream>

#include <ui_mainwindow.h>
#include <ui_settingsdialog.h>

using namespace std;

namespace wumpus_simulator
{
	class WumpusSimulator : public rqt_gui_cpp::Plugin
	{
	Q_OBJECT

	public:
		WumpusSimulator();
		~WumpusSimulator();

		//rqt stuff
		virtual void initPlugin(qt_gui_cpp::PluginContext& context);
		virtual void shutdownPlugin();
		virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
		virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
										const qt_gui_cpp::Settings& instance_settings);

		/**
		 * Initializes world
		 * @param arrow bool agent has arrow?
		 * @param size string fieldsize nxn
		 * @param traps string number of traps
		 * @param wumpus string number of wumpus
		 */
		void createWorld(bool arrow, string size, string traps, string wumpus);


		QWidget* widget_;
		Ui::MainWindow mainwindow;

	private slots:
		void settingsBtn();

	private:
	};
}

#endif // WUMPUSSIMULATOR_H
