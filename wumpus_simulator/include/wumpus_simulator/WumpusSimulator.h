/**
 * Handles interactions with agent and wumpus.
 *
 */
#ifndef WUMPUSSIMULATOR_H
#define WUMPUSSIMULATOR_H

#include <rqt_gui_cpp/plugin.h>

#include <iostream>

#include "ros/ros.h"
#include <ros/macros.h>

#include "wumpus_simulator/InitialPoseRequest.h"
#include "wumpus_simulator/ActionResponse.h"
#include "wumpus_simulator/InitialPoseResponse.h"
#include "wumpus_simulator/ActionRequest.h"

#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QTimer>
#include <QtWebKitWidgets/qwebview.h>
#include <QtNetwork/qnetworkreply.h>

#include <ui_mainwindow_webview.h>

using namespace std;

namespace wumpus_simulator
{
#define timeOut 5000

	class Model;
	class GroundTile;
	class Agent;
	class Wumpus;

	class WumpusSimulator : public rqt_gui_cpp::Plugin
	{
	Q_OBJECT

	public:
		WumpusSimulator();
		~WumpusSimulator();

		// Methods required by rqt plugin
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

		/**
		 * Save current model from JavaScript in Json
		 */
		Q_INVOKABLE	void saveWorld();

		/**
		 * Loads a wwf file from JavaScript
		 */
		Q_INVOKABLE	void loadWorld();

		Model* getModel();

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
		/**
		 * Exposes the simulator to JavaScript
		 */
		void addSimToJS();

		/**
		 * Redraw playground
		 */
		void callUpdatePlayground();

		/**
		 * Timeout callback
		 */
		void handleTimeOut();

		/**
		 * Start/Restart timer
		 */
		void handleStart();

		/**
		 * Stop timer
		 */
		void handleStop();

	private:
		Model* model;
		QTimer* timer;
		bool ready;
		int turnIndex;
		vector<int> turns;

		/**
		 * Colors playground according to model
		 */
		void updatePlayground();

		/**
		 * Handles incoming spawn request
		 */
		void onSpawnAgent(InitialPoseRequestPtr msg);

		/**
		 * Handles incoming action request and calls corresponding handle method
		 */
		void onAction(ActionRequestPtr msg);

		/**
		 * Places agent randomly on a free field
		 * @param agentId int positive id for agent
		 */
		void placeAgent(int agentId, bool hasArrow);

		/**
		 * Enables steering of already placed wumpus
		 * @param wumpusId int negative id for wumpus
		 */
		void possessWumpus(int wumpusId);

		/**
		 * Delegates mesg to corresponding method
		 */
		void handleAction(ActionRequestPtr msg);

		/**
		 * Call method according to given message
		 */
		void handleWumpusAction(ActionRequestPtr msg);

		/**
		 * Turns the agent right by 90 degrees
		 */
		void handleTurnRight(ActionRequestPtr msg);

		/**
		 * Turns the agent left by 90 degrees
		 */
		void handleTurnLeft(ActionRequestPtr msg);

		/**
		 * Shoots an arrow in the direction of the agent's current heading
		 */
		void handleShoot(ActionRequestPtr msg);

		/**
		 * Handles the request to pick up gold
		 */
		void handlePickUpGold(ActionRequestPtr msg);

		/**
		 * Handles the request to leave the playground.
		 * Agent can only leave the playground if they
		 * have collected the gold and are standing on
		 * their starting position
		 */
		void handleExit(ActionRequestPtr msg);

		/**
		 * Moves the agent reminding the outer walls
		 */
		void handleMove(ActionRequestPtr msg);

		/*
		 * Informs the next agent or wumpus
		 */
		void handleNextTurn();

		/**
		 * Informs agent about breeze, stench and glitter
		 */
		void handlePerception(ActionResponse& msg, shared_ptr<GroundTile> tile);

		/**
		 * Shoots an arrow to the left killing all wumpus on its way
		 */
		void handleShootLeft(ActionResponse& msg, shared_ptr<Agent> agent);

		/**
		 * Shoots an arrow to the right killing all wumpus on its way
		 */
		void handleShootRight(ActionResponse& msg, shared_ptr<Agent> agent);

		/**
		 * Shoots an arrow upwards killing all wumpus on its way
		 */
		void handleShootUp(ActionResponse& msg, shared_ptr<Agent> agent);

		/**
		 * Shoots an arrow downwards killing all wumpus on its way
		 */
		void handleShootDown(ActionResponse& msg, shared_ptr<Agent> agent);

		/**
		 * Kills wumpus and removes it from turns
		 */
		void killWumpus(shared_ptr<Wumpus> wumpus);

		/**
		 * Kills agent and removes it from turns
		 */
		void killAgent(shared_ptr<Agent> agent);

		/**
		 * Advances turn index
		 */
		void getNext();

	signals :
		/**
		 * Initiates redraw of playground
		 */
		void modelChanged();

		/**
		 * Request timer restart
		 */
		void timerStart();

		/**
		 * Request timer stop
		 */
		void timerStop();
	};
}

#endif // WUMPUSSIMULATOR_H
