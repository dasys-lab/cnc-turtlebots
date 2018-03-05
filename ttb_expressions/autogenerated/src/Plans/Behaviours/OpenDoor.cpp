using namespace std;
#include "Plans/Behaviours/OpenDoor.h"

/*PROTECTED REGION ID(inccpp1519913953735) ENABLED START*/ // Add additional includes here
#include <SolverType.h>

#include <robot/SimulatedArm.h>
#include <TurtleBot.h>
#include <TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1519913953735) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
OpenDoor::OpenDoor()
    : DomainBehaviour("OpenDoor")
{
    /*PROTECTED REGION ID(con1519913953735) ENABLED START*/ // Add additional options here
    this->query = std::make_shared<alica::Query>(this->wm->getEngine());
    this->currentDoor = nullptr;
    /*PROTECTED REGION END*/
}
OpenDoor::~OpenDoor()
{
    /*PROTECTED REGION ID(dcon1519913953735) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void OpenDoor::run(void *msg)
{
    /*PROTECTED REGION ID(run1519913953735) ENABLED START*/ // Add additional options here
    std::cout << "OpenDoor: run called" << std::endl;
    result.clear();
    if (!query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "OpenDoor: Unable to get solution for variable: " << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << std::endl;
        return;
    }

    std::cout << "OpenDoor: Solution for variable: " << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << " is: " << result[1] << std::endl;
    this->currentDoor = this->wm->topologicalModel.getDoor(result[1]);
    if(!this->currentDoor)
    {
    	std::cout << "OpenDoor: Door" << result[1] << " not found in topological model!" << std::endl;
    	return;
    }
    if(this->turtleBot->simulatedArm->openDoor(this->currentDoor->name))
    {
    	this->setSuccess(true);
    }
    else
    {
    	this->setFailure(true);
    }
    /*PROTECTED REGION END*/
}
void OpenDoor::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1519913953735) ENABLED START*/ // Add additional options here
    this->currentDoor = nullptr;
    query->clearStaticVariables();
    result.clear();
    query->addStaticVariable(getVariablesByName("door"));
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1519913953735) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
