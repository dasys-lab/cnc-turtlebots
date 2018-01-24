#include "robot/SimulatedArm.h"

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

SimulatedArm::SimulatedArm()
{
	this->sc = supplementary::SystemConfig::getInstance();
	this->carriedObjectName = "";
	ros::NodeHandle n;
	this->armCmdPub = n.advertise<ttb_msgs::GrabDropObject>("/ArmCmd", 5, false);
	this->robotName = this->sc->getHostname();
	std::string ownTopic = "/" + this->robotName + "/ArmCmd";
	this->armCmdSub = n.subscribe(ownTopic.c_str(), 10, &SimulatedArm::onOwnArmCmd, (SimulatedArm*)this);
	this->interactWithObject = 0;
    spinner = new ros::AsyncSpinner(4);
    spinner->start();
}

SimulatedArm::~SimulatedArm()
{
	spinner->stop();
	delete spinner;
}

const std::string &SimulatedArm::getCarriedObjectName() const
{
    return carriedObjectName;
}

bool SimulatedArm::grabObject(std::string objectName)
{
	if(objectName.empty() || !this->carriedObjectName.empty())
	{
		return false;
	}
	ttb_msgs::GrabDropObject msg;
	msg.senderName = this->robotName;
	msg.objectName = objectName;
	msg.action = ttb_msgs::GrabDropObject::GRAB;
	this->armCmdPub.publish(msg);
	this->interactWithObject = 0;
	return true;
}

bool SimulatedArm::drobObject(std::string objectName)
{
	if(objectName.empty() || this->carriedObjectName.compare(objectName) != 0)
	{
		return false;
	}
	ttb_msgs::GrabDropObject msg;
	msg.senderName = this->robotName;
	msg.objectName = objectName;
	msg.action = ttb_msgs::GrabDropObject::DROP;
	this->armCmdPub.publish(msg);
	this->interactWithObject = 0;
	return true;
}


int SimulatedArm::mayInteractWithObject()
{
	return this->interactWithObject;
}

void SimulatedArm::onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg)
{
	if(msg->action == ttb_msgs::GrabDropObject::GRAB)
	{
		if(!msg->objectName.empty() && msg->senderName.compare(this->robotName) == 0)
		{
			this->carriedObjectName = msg->objectName;
			this->interactWithObject = 1;
		}
		else
		{
			this->carriedObjectName = "";
			this->interactWithObject = -1;
		}
	}
	else
	{
		if(!msg->objectName.empty() && msg->senderName.compare(this->robotName) == 0)
		{
			this->carriedObjectName = "";
			this->interactWithObject = 1;
		}
		else
		{
			this->interactWithObject = -1;
		}
	}
}

} /* namespace robot */
} /* namespace ttb */

