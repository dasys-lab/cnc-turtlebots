#include "DomainBehaviour.h"
/*PROTECTED REGION ID(domainBehaviourSrcHeaders) ENABLED START*/
#include <SystemConfig.h>
#include <TurtleBot.h>
#include <engine/AlicaEngine.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
DomainBehaviour::DomainBehaviour(std::string name)
        : BasicBehaviour(name)
{
    /*PROTECTED REGION ID(domainBehaviourConstructor) ENABLED START*/
    sc = essentials::SystemConfig::getInstance();
    wm = ttb::TTBWorldModel::get();
    turtleBot = ttb::TurtleBot::get(wm);
    /*PROTECTED REGION END*/
}

DomainBehaviour::~DomainBehaviour()
{
    /*PROTECTED REGION ID(domainBehaviourDestructor) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}

/*PROTECTED REGION ID(domainBehaviourMethods) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/
} /* namespace alica */
