#pragma once

#include <engine/BasicCondition.h>
/*PROTECTED REGION ID(domainHeaderAdditional) ENABLED START*/
#include <robot_control/RobotCommand.h>
namespace ttb
{
class TTBWorldModel;
}
/*PROTECTED REGION END*/

namespace alica
{
class DomainCondition : public BasicCondition
{
public:
    DomainCondition();
    virtual ~DomainCondition();

    /*PROTECTED REGION ID(domainHeader) ENABLED START*/
    bool checkLastCommand(robot_control::RobotCommand::_cmd_type rc);
    bool fullyCharged();
    bool isCharging();

    /*PROTECTED REGION END*/

protected:
    /*PROTECTED REGION ID(protectedDomainHeader) ENABLED START*/
    ttb::TTBWorldModel* wm;

    /*PROTECTED REGION END*/

private:
    /*PROTECTED REGION ID(privateDomainHeader) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
