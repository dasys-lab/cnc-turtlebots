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
    this->requestedObject = "";
    this->armRange = 1.0;
    ros::NodeHandle n;
    this->armCmdPub = n.advertise<ttb_msgs::GrabDropObject>("/ArmCmd", 5, false);
    this->robotName = this->sc->getHostname();
    std::string ownTopic = "/" + this->robotName + "/ArmCmd";
    this->armCmdSub = n.subscribe(ownTopic.c_str(), 10, &SimulatedArm::onOwnArmCmd, (SimulatedArm *)this);
    this->interactWithObject = ObjectInteraction::waiting;
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

SimulatedArm::ObjectInteraction SimulatedArm::mayInteractWithObject()
{
    return this->interactWithObject;
}

bool SimulatedArm::grabObject(std::string objectName)
{
    if (objectName.empty() || !this->carriedObjectName.empty() || !this->requestedObject.empty())
    {
        return false;
    }
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.action = ttb_msgs::GrabDropObject::GRAB;
    this->armCmdPub.publish(msg);
    this->interactWithObject = ObjectInteraction::waiting;
    this->requestedObject = objectName;
    return true;
}

bool SimulatedArm::drobObject(std::string objectName)
{
    if (objectName.empty() || this->carriedObjectName.compare(objectName) != 0)
    {
        return false;
    }
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.action = ttb_msgs::GrabDropObject::DROP;
    this->armCmdPub.publish(msg);
    this->interactWithObject = ObjectInteraction::waiting;
    this->requestedObject = objectName;
    return true;
}

void SimulatedArm::onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg)
{
    if (msg->objectName.empty())
    {
        this->requestedObject = "";
        this->interactWithObject = ObjectInteraction::noInteractionAllowed;
        return;
    }
    if (msg->action == ttb_msgs::GrabDropObject::GRAB)
    {
        if (msg->senderName.compare(this->robotName) == 0 && msg->objectName.compare(this->requestedObject) == 0)
        {
            this->carriedObjectName = msg->objectName;
            this->requestedObject = "";
            this->interactWithObject = ObjectInteraction::interactionAllowed;
        }
    }
    else
    {
        if (msg->senderName.compare(this->robotName) == 0 && msg->objectName.compare(this->requestedObject) == 0)
        {
            this->carriedObjectName = "";
            this->requestedObject = "";
            this->interactWithObject = ObjectInteraction::interactionAllowed;
        }
    }
}

} /* namespace robot */
} /* namespace ttb */
