#ifndef WUMPUSSIMULATOR_H
#define WUMPUSSIMULATOR_H

#include <rqt_gui_cpp/plugin.h>

#include "ros/ros.h"
#include <ros/macros.h>
#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <iostream>
#include <QtWebKitWidgets/qwebview.h>
#include <ui_mainwindow_webview.h>
#include <QtNetwork/qnetworkreply.h>
#include "wumpus_simulator/InitialPoseRequest.h"
#include "wumpus_simulator/ActionResponse.h"
#include "wumpus_simulator/InitialPoseResponse.h"
#include "wumpus_simulator/ActionRequest.h"

using namespace std;

namespace wumpus_simulator
{
	class Simulator;
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
		Q_INVOKABLE void createWorld(bool arrow, int wumpus, int traps, int size);
		Q_INVOKABLE void saveWorld();
		Q_INVOKABLE void loadWorld();

		Simulator* getSim();

		QWidget* widget_;
		Ui::MainWindowWebView mainwindow;

		// ROS Stuff
		ros::NodeHandle n;
		ros::AsyncSpinner* spinner;

		ros::Subscriber spawnAgentSub;
		ros::Subscriber actionSub;

		ros::Publisher spawnAgentPub;
		ros::Publisher actionPub;

	public slots:
		void addSimToJS();
		void callUpdatePlayground();

	private:
		/**
		 * colors playground according to model
		 */
		void updatePlayground();
		Simulator* sim;

		void onSpawnAgent(InitialPoseRequestPtr msg);
		void onAction(ActionRequestPtr msg);
		void placeAgent(int agentId, bool hasArrow);
		void handleAction(ActionRequestPtr agentId);
		void handleTurnRight(ActionRequestPtr msg);
		void handleTurnLeft(ActionRequestPtr msg);
		void handleShoot(ActionRequestPtr msg);
		void handlePickUpGold(ActionRequestPtr msg);
		void handleExit(ActionRequestPtr msg);
		void handleMove(ActionRequestPtr msg);

		bool ready;

	signals :
		void modelChanged();
	};
}

#endif // WUMPUSSIMULATOR_H
