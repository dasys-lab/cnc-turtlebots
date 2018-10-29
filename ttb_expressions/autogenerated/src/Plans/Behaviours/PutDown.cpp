#include "Plans/Behaviours/PutDown.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1520850797525) ENABLED START*/
// Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <alica/reasoner/DummyVariable.h>
#include <geometry_msgs/Point.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1520850797525) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

PutDown::PutDown()
    : DomainBehaviour("PutDown")
{
    /*PROTECTED REGION ID(con1520850797525) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    this->isPuttingDown = false;
    /*PROTECTED REGION END*/
}
PutDown::~PutDown()
{
    /*PROTECTED REGION ID(dcon1520850797525) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void PutDown::run(void *msg)
{
    /*PROTECTED REGION ID(run1520850797525) ENABLED START*/
    // Add additional options here
    result.clear();
    if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "PutDown: Unable to get solution for variables: "
                  << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " "
                  << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << " "
                  << this->query->getUniqueVariableStore()->getAllRep()[2]->getName() << " "
                  << this->query->getUniqueVariableStore()->getAllRep()[3]->getName() << std::endl;
        return;
    }

    //    std::cout << "PutDown: Solution for variable: " <<
    //    this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
    //              << " for variable " << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << " is: "
    //              << result[1] << " for variable "
    //              << this->query->getUniqueVariableStore()->getAllRep()[2]->getName() << " is: " << result[2] << " for
    //              variable "
    //              << this->query->getUniqueVariableStore()->getAllRep()[3]->getName() << " is: " << result[3] <<
    //              std::endl;

    auto object = this->wm->logicalCameraData.getObject(result[3]);
    if (!object || result[3].compare(alica::reasoner::DummyVariable::NO_VALUE) == 0)
    {
        this->setFailure(true);
        return;
    }
    if (!this->isPuttingDown)
    {
        geometry_msgs::Point point;
        point.x = stod(result[0]);
        point.y = stod(result[1]);
        point.z = stod(result[2]);
        this->isPuttingDown = this->turtleBot->simulatedArm->dropObject(result[3], point);
    }
    if (!this->isPuttingDown)
    {
        this->setFailure(true);
        return;
    }
    auto armState = this->turtleBot->simulatedArm->getArmState();
    if (armState == ttb::robot::SimulatedArm::ArmState::waiting)
    {
        return;
    }
    else if (armState == ttb::robot::SimulatedArm::ArmState::failed)
    {
        this->setFailure(true);
    }
    else
    {
        this->setSuccess(true);
    }
    /*PROTECTED REGION END*/
}
void PutDown::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1520850797525) ENABLED START*/
    // Add additional options here
    this->isPuttingDown = false;
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariable("x"));
    this->query->addStaticVariable(getVariable("y"));
    this->query->addStaticVariable(getVariable("z"));
    this->query->addStaticVariable(getVariable("entity"));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1520850797525) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
