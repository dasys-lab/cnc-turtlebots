#include "Plans/Behaviours/PutDown.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1520850797525) ENABLED START*/
// Add additional includes here
#include <TurtleBot.h>
#include <alica/reasoner/DummySolver.h>
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
void PutDown::run(void* msg)
{
    /*PROTECTED REGION ID(run1520850797525) ENABLED START*/
    // Add additional options here
    result.clear();
    if (!this->query->getSolution<reasoner::DummySolver, alica::BBIdent>(this->getPlanContext(), result)) {
        VariableGrp vars;
        this->query->getUniqueVariableStore().getAllRep(vars);
        std::cout << "PutDown: Unable to get solution for variables: " << vars[0]->getName() << " " << vars[1]->getName() << " " << vars[2]->getName() << " "
                  << vars[3]->getName() << std::endl;
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

    const auto& bbValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[3]);
    string objectName = std::string(reinterpret_cast<const char *>(bbValue.begin()),bbValue.size());

    auto object = this->wm->logicalCameraData.getObject(objectName);
    if (!object || objectName.compare(alica::reasoner::DummyVariable::NO_VALUE) == 0) {
        this->setFailure();
        return;
    }
    if (!this->isPuttingDown) {
        const auto& bbXValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[0]);
        string objectXStr = std::string(reinterpret_cast<const char *>(bbXValue.begin()),bbXValue.size());
        const auto& bbYValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[1]);
        string objectYStr = std::string(reinterpret_cast<const char *>(bbYValue.begin()),bbYValue.size());
        const auto& bbZValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[2]);
        string objectZStr = std::string(reinterpret_cast<const char *>(bbZValue.begin()),bbZValue.size());
        geometry_msgs::Point point;
        point.x = stod(objectXStr);
        point.y = stod(objectYStr);
        point.z = stod(objectZStr);
        this->isPuttingDown = this->turtleBot->simulatedArm->dropObject(objectName, point);
    }
    if (!this->isPuttingDown) {
        this->setFailure();
        return;
    }
    auto armState = this->turtleBot->simulatedArm->getArmState();
    if (armState == ttb::robot::SimulatedArm::ArmState::waiting) {
        return;
    } else if (armState == ttb::robot::SimulatedArm::ArmState::failed) {
        this->setFailure();
    } else {
        this->setSuccess();
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
