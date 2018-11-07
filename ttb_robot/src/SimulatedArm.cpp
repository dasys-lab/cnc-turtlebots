#include "robot/SimulatedArm.h"

#include <ttb/TTBWorldModel.h>
#include <ttb/wm/RawSensorData.h>
#include <ttb/wm/sim/LogicalCameraData.h>
#include <ttb/wm/topology/Door.h>

#include <cnc_geometry/CNPointAllo.h>
#include <cnc_geometry/CNPositionAllo.h>

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

SimulatedArm::SimulatedArm()
{
    this->wm = ttb::TTBWorldModel::get();
    this->sc = supplementary::SystemConfig::getInstance();
    this->carriedObjectName = "";
    this->requestedObject = "";
    this->armRange = (*this->sc)["TTBRobot"]->get<double>("SimulatedArm.Range", NULL);
    ros::NodeHandle n;
    this->doorCmdPub = n.advertise<ttb_msgs::DoorCmd>("/DoorCmd", 5, false);
    this->armCmdPub = n.advertise<ttb_msgs::GrabDropObject>("/ArmCmd", 5, false);
    this->robotName = this->sc->getHostname();
    this->armCmdSub = n.subscribe("/ArmCmdResponse", 10, &SimulatedArm::onOwnArmCmd, (SimulatedArm*) this);

    this->armState = ArmState::waiting;
    spinner = new ros::AsyncSpinner(4);
    spinner->start();
}

SimulatedArm::~SimulatedArm()
{
    spinner->stop();
    delete spinner;
}

bool SimulatedArm::openDoor(std::string doorName, bool open)
{
    auto door = this->wm->topologicalModel.getDoor(doorName);
    if (!door) {
        std::cout << "SimulatedArm::openDoor: Door " << doorName << " not found in topological model!" << std::endl;
        return false;
    }
    return this->openDoor(door, open);
}

bool SimulatedArm::openDoor(std::shared_ptr<ttb::wm::Door> door, bool open)
{
    auto lastValidDoorPose = door->gazeboModel->getPoseBuffer()->getLastValidContent();
    if (!lastValidDoorPose) {
        // Do not open a door which the robot has not seen for some time
        // or has not seen at all
        std::cout << "SimulatedArm::openDoor: Door " << door->name << " has no valid position!" << std::endl;
        return false;
    }

    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValidContent();
    if (!ownPos) {
        // Do not open a door if the robot does not know its own position
        std::cout << "SimulatedArm::openDoor: Own position not valid!" << std::endl;
        return false;
    }
    geometry::CNPointAllo doorPoint = geometry::CNPointAllo(lastValidDoorPose->x, lastValidDoorPose->y);
    auto doorDistance = ownPos->distanceTo(doorPoint);
    if (doorDistance > this->armRange) {
        std::cout << "SimulatedArm::openDoor: Door " << door->name << " is out of range! Range is: " << this->armRange << " distance is: " << doorDistance
                  << " ownPos: " << ownPos->toString() << " door point: " << doorPoint.toString() << std::endl;
        // Not possible to open a door which is out of range
        return false;
    }
    ttb_msgs::DoorCmd msg;
    msg.name = door->name;
    if (open) {
        msg.state = ttb_msgs::DoorCmd::OPEN;
    } else {
        msg.state = ttb_msgs::DoorCmd::CLOSE;
    }
    this->doorCmdPub.publish(msg);
    return true;
}

const std::string& SimulatedArm::getCarriedObjectName() const
{
    return carriedObjectName;
}

SimulatedArm::ArmState SimulatedArm::getArmState()
{
    return this->armState;
}

bool SimulatedArm::grabObject(std::string objectName)
{
    if (objectName.empty() || !this->carriedObjectName.empty() || !this->requestedObject.empty()) {
        return false;
    }
    auto objectToCarry = wm->logicalCameraData.getObject(objectName);
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.action = ttb_msgs::GrabDropObject::GRAB;
    this->armCmdPub.publish(msg);
    this->armState = ArmState::waiting;
    this->requestedObject = objectName;
    return true;
}

bool SimulatedArm::dropObject(std::string objectName, geometry_msgs::Point entityPoint)
{
    std::cout << "SimulatedArm: objectname: " << objectName << "carried object: " << this->carriedObjectName << std::endl;
    if (objectName.empty() || this->carriedObjectName.compare(objectName) != 0) {
        return false;
    }
    ttb_msgs::GrabDropObject msg;
    msg.senderName = this->robotName;
    msg.objectName = objectName;
    msg.dropPoint = entityPoint;
    msg.action = ttb_msgs::GrabDropObject::DROP;
    this->armCmdPub.publish(msg);
    this->armState = ArmState::waiting;
    this->requestedObject = objectName;
    return true;
}

void SimulatedArm::onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg)
{
    if (msg->senderName.compare(this->robotName) != 0) {
        return;
    }
    if (msg->objectName.empty()) {
        this->requestedObject = "";
        this->armState = ArmState::failed;
        return;
    }
    if (msg->objectName.compare(this->requestedObject) != 0) {
        return;
    }
    if (msg->action == ttb_msgs::GrabDropObject::GRAB) {
        this->carriedObjectName = msg->objectName;
        this->requestedObject = "";
        this->armState = ArmState::successful;
    } else {
        this->carriedObjectName = "";
        this->requestedObject = "";
        this->armState = ArmState::successful;
    }
}

double SimulatedArm::getArmRange()
{
    return this->armRange;
}

} /* namespace robot */
} /* namespace ttb */
