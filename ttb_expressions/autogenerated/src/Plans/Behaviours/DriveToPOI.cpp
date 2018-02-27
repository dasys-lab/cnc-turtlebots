using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ // Add additional includes here
#include <Robot.h>
#include <robot/Movement.h>
#include <robot/TTBEnums.h>
#include <TTBWorldModel.h>
#include <TopologicalModel.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
DriveToPOI::DriveToPOI()
    : DomainBehaviour("DriveToPOI")
{
    /*PROTECTED REGION ID(con1454329856163) ENABLED START*/ // Add additional options here
    this->currentGoalPOI = nullptr;
    /*PROTECTED REGION END*/
}
DriveToPOI::~DriveToPOI()
{
    /*PROTECTED REGION ID(dcon1454329856163) ENABLED START*/ // Add additional options here
                                                             /*PROTECTED REGION END*/
}
void DriveToPOI::run(void *msg)
{
    /*PROTECTED REGION ID(run1454329856163) ENABLED START*/ // Add additional options here
    if (!this->trySetGoalPOI())
    {
        // unable to set goal poi
        this->setFailure(true);
        return;
    }

    switch (this->robot->movement->getState(this->currentGoalPOI))
    {
    case ttb::robot::MovementReturnState::OtherGoalAssigned:
    case ttb::robot::MovementReturnState::NoGoalAssigned:
        this->robot->movement->setGoalPOI(this->currentGoalPOI);
        break;
    case ttb::robot::MovementReturnState::GoalReached:
        this->setSuccess(true);
        return;
    case ttb::robot::MovementReturnState::GoalFailed:
        this->setFailure(true);
        return;
    case ttb::robot::MovementReturnState::GoalInProgress:
    default:
        return;
    }

//    if (this->goalHandle.isExpired())
//    {
//
//        // Only get a new poi if no path has been given before or nextPOI has been reached
//        if (this->nextPOI == nullptr)
//        {
//            std::cout << "DriveToPOI: Getting next POI!" << std::endl;
//            this->nextPOI = this->robot->movement->moveToPOI(ownRoom.value(), poi);
//            std::cout << "DriveToPOI: next POI is: " << this->nextPOI->toString() << std::endl;
//        }
//
//        move_base_msgs::MoveBaseGoal mbg;
//        mbg.target_pose.pose.orientation.w = 1;
//        mbg.target_pose.pose.position.x = nextPOI->x;
//        mbg.target_pose.pose.position.y = nextPOI->y;
//        mbg.target_pose.header.frame_id = "/map";
//
//        this->goalHandle = this->robot->movement->send(mbg);
//    }
//    else if (this->goalHandle.getCommState() == actionlib::CommState::DONE)
//    {
//        if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::SUCCEEDED)
//        {
//            this->nextPOI = nullptr;
//            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
//                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() << std::endl;
//            this->goalHandle.reset();
//            // this->setSuccess(true);
//        }
//        else if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::ABORTED)
//        {
//            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
//                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() << std::endl;
//            this->setFailure(true);
//        }
//    }
    /*PROTECTED REGION END*/
}
void DriveToPOI::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/ // Add additional options here
    this->currentGoalPOI = nullptr;
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/ // Add additional methods here

/**
 * This method tries to set a new Goal POI, if none is set.
 *
 * Returns false, if it was necessary so set a new Goal POI but it didn't work for some reason.
 * Returns true, otherwise.
 */
bool DriveToPOI::trySetGoalPOI()
{
    if (!this->currentGoalPOI)
    {
        auto currentTask = this->wm->taskManager.getNextTask();
        if (currentTask && currentTask->getInformation().type == ttb_msgs::ServeTask::DRIVE_TO)
        {
            this->wm->taskManager.popNextTask();
        }
        else
        {
            return false;
        }

        this->currentGoalPOI = this->wm->topologicalModel.getPOI(stoi(currentTask->getInformation().entity));
        if (!this->currentGoalPOI)
        {
            return false;
        }
    }

    // we got a new one, or already had one goal POI set
    return true;
}
/*PROTECTED REGION END*/
} /* namespace alica */
