#include "DomainCondition.h"
/*PROTECTED REGION ID(domainSourceHeaders) ENABLED START*/
#include <kobuki_msgs/SensorState.h>
#include <robot_control/RobotCommand.h>
#include <supplementary/InfoBuffer.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
DomainCondition::DomainCondition()
        : BasicCondition()
{
    /*PROTECTED REGION ID(domainSourceConstructor) ENABLED START*/
    this->wm = ttb::TTBWorldModel::get();
    /*PROTECTED REGION END*/
}

DomainCondition::~DomainCondition()
{
    /*PROTECTED REGION ID(domainSourceDestructor) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}

/*PROTECTED REGION ID(additionalMethodsDomainCondition) ENABLED START*/
bool DomainCondition::checkLastCommand(robot_control::RobotCommand::_cmd_type cmd)
{
    auto lastCmd = wm->rawSensorData.getRobotCommandBuffer()->getLastValidContent();
    if (lastCmd && lastCmd->cmd == cmd) {
        return true;
    }
    return false;
}

bool DomainCondition::fullyCharged()
{
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    if ((*core)->charger == kobuki_msgs::SensorState::DOCKING_CHARGED || (*core)->charger == kobuki_msgs::SensorState::ADAPTER_CHARGED) {
        return true;
    }
    return false;
}

bool DomainCondition::isCharging()
{
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    if ((*core)->charger == kobuki_msgs::SensorState::DOCKING_CHARGING || (*core)->charger == kobuki_msgs::SensorState::ADAPTER_CHARGING) {
        return true;
    }
    return false;
}
/*PROTECTED REGION END*/
} /* namespace alica */
