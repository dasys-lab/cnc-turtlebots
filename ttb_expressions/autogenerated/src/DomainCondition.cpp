#include "DomainCondition.h"

#include <kobuki_msgs/SensorState.h>
#include <robot_control/RobotCommand.h>
#include <supplementary/InfoBuffer.h>

namespace alica
{
DomainCondition::DomainCondition()
    : BasicCondition()
{
    this->wm = ttb::TTBWorldModel::get();
}

bool DomainCondition::checkLastCommand(robot_control::RobotCommand::_cmd_type cmd)
{
    auto lastCmd = wm->rawSensorData.getRobotCommandBuffer()->getLastValidContent();
    if (lastCmd && lastCmd->cmd == cmd)
    {
        return true;
    }
    return false;
}

bool DomainCondition::fullyCharged()
{
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    if ((*core)->charger == kobuki_msgs::SensorState::DOCKING_CHARGED ||
        (*core)->charger == kobuki_msgs::SensorState::ADAPTER_CHARGED)
    {
        return true;
    }
    return false;
}

bool DomainCondition::isCharging()
{
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    if ((*core)->charger == kobuki_msgs::SensorState::DOCKING_CHARGING ||
        (*core)->charger == kobuki_msgs::SensorState::ADAPTER_CHARGING)
    {
        return true;
    }
    return false;
}

DomainCondition::~DomainCondition()
{
}
} /* namespace alica */
