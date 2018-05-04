#include "Plans/Behaviours/DriveCloseToObject.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1520521852939) ENABLED START*/
// Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1520521852939) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

DriveCloseToObject::DriveCloseToObject()
    : DomainBehaviour("DriveCloseToObject")
{
    /*PROTECTED REGION ID(con1520521852939) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
DriveCloseToObject::~DriveCloseToObject()
{
    /*PROTECTED REGION ID(dcon1520521852939) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void DriveCloseToObject::run(void *msg)
{
    /*PROTECTED REGION ID(run1520521852939) ENABLED START*/
    // Add additional options here
    result.clear();
    if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "DriveCloseToObject: Unable to get solution for variable: "
                  << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << std::endl;
        return;
    }

    //        std::cout << "DriveCloseToObject: Solution for variable: "
    //                << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
    //                << std::endl;

    auto object = this->wm->logicalCameraData.getObject(result[0]);
    if (!object)
    {
        std::cout << "DriveCloseToObject: Object not available" << std::endl;
        this->setFailure(true);
        return;
    }
    auto objectPosition = object->getPoseBuffer()->getLastValidContent();
    if (!objectPosition)
    {
        std::cout << "DriveCloseToObject: Position for object " << result[0] << " is not available" << std::endl;
        this->setFailure(true);
        return;
    }
    if (this->wm->robot.isCloseTo(objectPosition, this->turtleBot->simulatedArm->getArmRange() * (3.0 / 4.0)))
    {
        this->goalHandle.reset();
        this->turtleBot->movement->cancelAllGoals();
        this->setSuccess(true);
        return;
    }
    // MoveBase to DriveCloseToObject
    if (isMoveBaseDone())
    {
        std::cout << "DriveCloseToObject: Drive to object: " << result[0] << std::endl;
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = objectPosition->x;
        mbg.target_pose.pose.position.y = objectPosition->y;
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.header.frame_id = "/map";
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
        this->goalHandle = this->turtleBot->movement->send(mbg);
    }
    /*PROTECTED REGION END*/
}
void DriveCloseToObject::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1520521852939) ENABLED START*/
    // Add additional options here
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariableByName("entity"));
    this->goalHandle.reset();

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1520521852939) ENABLED START*/
// Add additional methods here
bool DriveCloseToObject::isMoveBaseDone()
{
    if (!this->goalHandle.isExpired() && this->goalHandle.getCommState() == actionlib::CommState::DONE)
    {
        if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::ABORTED)
        {
            this->setFailure(true);
        }
        this->goalHandle.reset();
        return true;
    }
    else if (this->goalHandle.isExpired())
    {
        return true;
    }

    return false;
}
/*PROTECTED REGION END*/

} /* namespace alica */
