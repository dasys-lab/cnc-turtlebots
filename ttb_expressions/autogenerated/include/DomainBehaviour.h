#pragma once

#include <engine/BasicBehaviour.h>
#include <string>
/*PROTECTED REGION ID(domainBehaviourHeaderHead) ENABLED START*/
#include <ros/ros.h>
namespace supplementary
{
class SystemConfig;
}

namespace ttb
{
class TTBWorldModel;
class TurtleBot;
}
/*PROTECTED REGION END*/

namespace alica
{
class DomainBehaviour : public BasicBehaviour
{
  public:
    DomainBehaviour(std::string name);
    virtual ~DomainBehaviour();

    /*PROTECTED REGION ID(domainBehaviourClassDecl) ENABLED START*/
    supplementary::SystemConfig *sc;
    ttb::TTBWorldModel *wm;
    ttb::TurtleBot *turtleBot;
    /*PROTECTED REGION END*/
};
} /* namespace alica */
