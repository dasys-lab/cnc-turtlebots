#include "ServiceRobots/Behaviours/DriveCloseToObject.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1553251534505) ENABLED START*/
#include <TurtleBot.h>
#include <alica/reasoner/SimpleSolver.h>
#include <alica/reasoner/SimpleTerm.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1553251534505) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

DriveCloseToObject::DriveCloseToObject()
        : DomainBehaviour("DriveCloseToObject")
{
    /*PROTECTED REGION ID(con1553251534505) ENABLED START*/
    this->query = std::make_shared<alica::Query>();
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
DriveCloseToObject::~DriveCloseToObject()
{
    /*PROTECTED REGION ID(dcon1553251534505) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void DriveCloseToObject::run(void* msg)
{
    /*PROTECTED REGION ID(run1553251534505) ENABLED START*/
    result.clear();
    if (!this->query->getSolution<reasoner::SimpleSolver, alica::BBIdent>(this->getPlanContext(), result)) {
        VariableGrp variableGrp;
        this->query->getUniqueVariableStore().getAllRep(variableGrp);
        std::cout << "DriveCloseToObject: Unable to get solution for variable: " << variableGrp[0]->getName() << std::endl;
        return;
    }

    // read the result from the blackboard and convert it back to string
    const auto& bbValue = this->getPlanContext().getAlicaEngine()->getBlackBoard().getValue(result[0]);
    std::string objectName = std::string(reinterpret_cast<const char*>(bbValue.begin()), bbValue.size());
    auto object = this->wm->logicalCameraData.getObject(objectName);
    if (!object) {
        std::cout << "DriveCloseToObject: Object not available" << std::endl;
        this->setFailure();
        return;
    }
    auto objectPosition = object->getPoseBuffer()->getLastValidContent();
    if (!objectPosition) {
        std::cout << "DriveCloseToObject: Position for object " << objectName << " is not available" << std::endl;
        this->setFailure();
        return;
    }
    if (this->wm->robot.isCloseTo(objectPosition, this->turtleBot->simulatedArm->getArmRange() * (3.0 / 4.0))) {
        this->goalHandle.reset();
        this->turtleBot->movement->cancelAllGoals();
        this->setSuccess();
        return;
    }
    // MoveBase to DriveCloseToObject
    if (isMoveBaseDone()) {
        std::cout << "DriveCloseToObject: Drive to object: " << objectName << std::endl;
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = objectPosition->x;
        mbg.target_pose.pose.position.y = objectPosition->y;
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.header.frame_id = "/map";
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time(time.inSeconds(), time.inNanoseconds() % 1000000000UL);
        this->goalHandle = this->turtleBot->movement->send(mbg);
    }
    /*PROTECTED REGION END*/
}
void DriveCloseToObject::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1553251534505) ENABLED START*/
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariable("entity"));
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1553251534505) ENABLED START*/
bool DriveCloseToObject::isMoveBaseDone()
{
    if (!this->goalHandle.isExpired() && this->goalHandle.getCommState() == actionlib::CommState::DONE) {
        if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::ABORTED) {
            this->setFailure();
        }
        this->goalHandle.reset();
        return true;
    } else if (this->goalHandle.isExpired()) {
        return true;
    }

    return false;
}
/*PROTECTED REGION END*/

} /* namespace alica */
