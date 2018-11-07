#include "Plans/Behaviours/OpenDoor.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1519913953735) ENABLED START*/
// Add additional includes here
#include <TurtleBot.h>
#include <alica/reasoner/DummySolver.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1519913953735) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

OpenDoor::OpenDoor()
        : DomainBehaviour("OpenDoor")
{
    /*PROTECTED REGION ID(con1519913953735) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    this->currentDoor = nullptr;
    /*PROTECTED REGION END*/
}
OpenDoor::~OpenDoor()
{
    /*PROTECTED REGION ID(dcon1519913953735) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void OpenDoor::run(void* msg)
{
    /*PROTECTED REGION ID(run1519913953735) ENABLED START*/
    // Add additional options here
    if ((this->wm->getTime() - this->getPlanContext().getRunningPlan()->getStateStartTime()) > alica::AlicaTime::seconds(5)) // 5sec
    {
        this->setFailure();
    }

    result.clear();
    VariableGrp vars;
    this->query->getUniqueVariableStore().getAllRep(vars);
    if (!query->getSolution<reasoner::DummySolver, BBIdent>(this->getPlanContext(), result)) {
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
    /*PROTECTED REGION ID(initialiseParameters1519913953735) ENABLED START*/
    // Add additional options here
    this->currentDoor = nullptr;
    query->clearStaticVariables();
    result.clear();
    query->addStaticVariable(getVariable("door"));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1519913953735) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
