#include "ServiceRobots/Behaviours/OpenDoor.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1553249804320) ENABLED START*/
#include <TurtleBot.h>
#include <alica/reasoner/SimpleSolver.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1553249804320) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

OpenDoor::OpenDoor()
        : DomainBehaviour("OpenDoor")
{
    /*PROTECTED REGION ID(con1553249804320) ENABLED START*/
    this->query = std::make_shared<alica::Query>();
    this->currentDoor = nullptr;
    /*PROTECTED REGION END*/
}
OpenDoor::~OpenDoor()
{
    /*PROTECTED REGION ID(dcon1553249804320) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void OpenDoor::run(void* msg)
{
    /*PROTECTED REGION ID(run1553249804320) ENABLED START*/
    if ((this->wm->getTime() - this->getPlanContext().getRunningPlan()->getStateStartTime()) > alica::AlicaTime::seconds(5)) // 5sec
    {
        this->setFailure();
    }

    result.clear();
    VariableGrp vars;
    this->query->getUniqueVariableStore().getAllRep(vars);
    if (!query->getSolution<reasoner::SimpleSolver, BBIdent>(this->getPlanContext(), result)) {
        std::cout << "OpenDoor: Unable to get solution for variable: " << vars[0]->getName() << std::endl;
        return;
    }

    const auto& bbValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[0]);
    string doorName = std::string(reinterpret_cast<const char *>(bbValue.begin()),bbValue.size());

    std::cout << "OpenDoor: Solution for variable: " << vars[0]->getName() << " is: " << doorName << std::endl;

    auto door = this->wm->topologicalModel.getDoor(doorName);
    if (!door) {
        std::cout << "OpenDoor: Door " << doorName << " not found in topological model!" << std::endl;
        return;
    }

    if (door->open) {
        this->setSuccess();
        this->setFailure();
        return;
    }

    if (!this->turtleBot->simulatedArm->openDoor(door)) {
        return;
    }
    /*PROTECTED REGION END*/
}
void OpenDoor::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1553249804320) ENABLED START*/
    this->currentDoor = nullptr;
    query->clearStaticVariables();
    result.clear();
    query->addStaticVariable(getVariable("door"));
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1553249804320) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

} /* namespace alica */
