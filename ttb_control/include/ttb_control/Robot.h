#pragma once

#include <chrono>
#include <process_manager/RobotMetaData.h>
#include <QFrame>
#include <ros/ros.h>
#include <alica_msgs/AlicaEngineInfo.h>
#include <process_manager/ProcessStats.h>

namespace Ui {
	class TTBRobotWidget;
}

namespace supplementary{
	class RobotExecutableRegistry;
}

namespace ttb_control
{
	class TTBControl;

	class Robot : public QFrame, public supplementary::RobotMetaData
	{
		Q_OBJECT
	public:
		Robot(std::string robotName, const supplementary::AgentID* robotId, TTBControl* parentTTBControl);

		virtual ~Robot();

		// Message processing
		std::chrono::time_point<std::chrono::system_clock> timeLastMsgReceived; /**< the last time a message was received for this robot */

		// GUI Methods and Members
		TTBControl* parentTTBControl;
		void updateGUI(std::chrono::system_clock::time_point now);
		void toggle();
		void show();
		void hide();
		virtual QSize sizeHint();
		bool shown;

	private:
		QFrame* widget;
		Ui::TTBRobotWidget* uiTTBRobot;

//		QFrame* frameForPM;
//		pm_widget::ControlledRobot* controlledRobotWidget;

	};

} /* namespace ttb_control */
