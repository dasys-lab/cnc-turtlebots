#include "Plans/Behaviours/OpenDoor.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1519913953735) ENABLED START*/
// Add additional includes here
#include <SolverType.h>

#include <TurtleBot.h>
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
void OpenDoor::run(void *msg)
{
    /*PROTECTED REGION ID(run1519913953735) ENABLED START*/
    // Add additional options here
    if ((this->wm->getTime() - this->runningPlan->getStateStartTime()) > 5000000000) // 5sec
    {
        this->setFailure(true);
    }

    result.clear();
    if (!query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "OpenDoor: Unable to get solution for variable: "
                  << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << std::endl;
        return;
    }

    std::cout << "OpenDoor: Solution for variable: " << this->query->getUniqueVariableStore()->getAllRep()[0]->getName()
              << " is: " << result[0] << std::endl;

    auto door = this->wm->topologicalModel.getDoor(result[0]);
    if (!door)
    {
        std::cout << "OpenDoor: Door " << result[0] << " not found in topological model!" << std::endl;
        return;
    }

    if (door->open)
    {
        this->setSuccess(true);
        this->setFailure(false);
        return;
    }

    if (!this->turtleBot->simulatedArm->openDoor(door))
    {
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
    query->addStaticVariable(getVariableByName("door"));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1519913953735) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
