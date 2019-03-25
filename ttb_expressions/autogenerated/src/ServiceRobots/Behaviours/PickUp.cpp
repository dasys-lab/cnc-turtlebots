#include "ServiceRobots/Behaviours/PickUp.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1553251475582) ENABLED START*/
#include <TurtleBot.h>
#include <alica/reasoner/SimpleVariable.h>
#include <alica/reasoner/SimpleSolver.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1553251475582) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

PickUp::PickUp()
        : DomainBehaviour("PickUp")
{
    /*PROTECTED REGION ID(con1553251475582) ENABLED START*/
    this->query = std::make_shared<alica::Query>();
    this->isGrabbing = false;
    /*PROTECTED REGION END*/
}
PickUp::~PickUp()
{
    /*PROTECTED REGION ID(dcon1553251475582) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void PickUp::run(void* msg)
{
    /*PROTECTED REGION ID(run1553251475582) ENABLED START*/
    result.clear();
    if (!this->query->getSolution<reasoner::SimpleSolver, alica::BBIdent>(this->getPlanContext(), result)) {
        VariableGrp vars;
        this->query->getUniqueVariableStore().getAllRep(vars);
        std::cout << "PickUp: Unable to get solution for variable: " << vars[0]->getName() << std::endl;
        return;
    }

    //        std::cout << "PickUp: Solution for variable: "
    //                << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
    //                << std::endl;

    const auto& bbValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[0]);
    string objectName = std::string(reinterpret_cast<const char *>(bbValue.begin()),bbValue.size());

    auto object = this->wm->logicalCameraData.getObject(objectName);
    if (!object || objectName.compare(alica::reasoner::SimpleVariable::NO_VALUE) == 0) {
        this->setFailure();
        return;
    }
    if (!this->isGrabbing) {
        this->isGrabbing = this->turtleBot->simulatedArm->grabObject(objectName);
    }
    if (!this->isGrabbing) {
        std::cout << "Pickup: grabbing failed" << std::endl;
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
void PickUp::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1553251475582) ENABLED START*/
    this->isGrabbing = false;
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariable("entity"));
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1553251475582) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

} /* namespace alica */
