#include <ttb_control/Robot.h>

#include <process_manager/RobotExecutableRegistry.h>
#include <ros/ros.h>

#include "ui_ControlledTTBRobot.h"
#include <QFrame>

#include <chrono>
#include <limits.h>
#include <ttb_control/TTBControl.h>
#include <sstream>

using std::string;

namespace ttb_control
{
Robot::Robot(string robotName, const supplementary::AgentID* robotId, TTBControl *parentTTBControl)
    : RobotMetaData(robotName, robotId)
    , parentTTBControl(parentTTBControl)
    , widget(new QFrame())
    , uiTTBRobot(new Ui::TTBRobotWidget())
    , shown(true)
{
    this->uiTTBRobot->setupUi(this);
    std::stringstream ss;
    ss << *robotId;
    // manual configuration of widgets
    this->uiTTBRobot->robotNameLbl->setText(
        QString(std::string(this->name + " (" + ss.str() + ")").c_str()));

    this->parentTTBControl->robotControlWidget_.robotControlLayout->addWidget(this);
}

Robot::~Robot()
{
}

QSize Robot::sizeHint()
{
    return QSize(500, 500);
}

void Robot::updateGUI(std::chrono::system_clock::time_point now)
{
	if ((now - this->timeLastMsgReceived) > std::chrono::milliseconds(1000))
	{
		this->uiTTBRobot->RoomValue->setText(QString(""));
	}
}

void Robot::handleTopologicalInfo(
    std::pair<std::chrono::system_clock::time_point, ttb_msgs::TopologicalInfoPtr> timeTopologicalInfoPair)
{
	this->timeLastMsgReceived = timeTopologicalInfoPair.first;
	this->uiTTBRobot->RoomValue->setText(QString(timeTopologicalInfoPair.second->ownRoom.c_str()));
}

void Robot::toggle()
{
    if (shown)
    {
        this->hide();
    }
    else
    {
        this->show();
    }
}

void Robot::show()
{
    this->shown = true;
    QFrame::show();
}

void Robot::hide()
{
    this->shown = false;
    QFrame::hide();
}

} /* namespace ttb_control */
