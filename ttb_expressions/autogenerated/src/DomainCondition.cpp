#include "DomainCondition.h"
#include "robot_control/RobotCommand.h"

namespace alica
{
	DomainCondition::DomainCondition() :
			BasicCondition()
	{
		this->wm = ttb::TTBWorldModel::get();
	}

	bool DomainCondition::checkLastCommand(robot_control::RobotCommand::_cmd_type cmd)
	{
		if ((wm->rawSensorData.getOwnRobotOnOff() != nullptr) && wm->rawSensorData.getOwnRobotOnOff()->cmd == cmd)
		{
			return true;
		}
		return false;
	}

	DomainCondition::~DomainCondition()
	{
	}
} /* namespace alica */
