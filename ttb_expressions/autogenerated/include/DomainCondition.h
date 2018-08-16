#pragma once

#include "engine/BasicCondition.h"
#include <robot_control/RobotCommand.h>

namespace ttb
{
class TTBWorldModel;
}
namespace alica
{
class DomainCondition : public BasicCondition
{
  public:
    DomainCondition();
    virtual ~DomainCondition();
    bool checkLastCommand(robot_control::RobotCommand::_cmd_type rc);
    bool fullyCharged();
    bool isCharging();

  protected:
    ttb::TTBWorldModel *wm;
};
} /* namespace alica */
