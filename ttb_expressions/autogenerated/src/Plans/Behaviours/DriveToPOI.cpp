using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ // Add additional includes here
#include <Robot.h>
#include <SolverType.h>
#include <TTBWorldModel.h>
#include <TopologicalModel.h>
#include <robot/Movement.h>
#include <robot/TTBEnums.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
DriveToPOI::DriveToPOI()
    : DomainBehaviour("DriveToPOI")
{
    /*PROTECTED REGION ID(con1454329856163) ENABLED START*/ // Add additional options here
    this->query = std::make_shared<alica::Query>(this->wm->getEngine());
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
    if (!query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "DriveToPOI: Unable to get solution for variable: "
                  << this->query->getRelevantStaticVariables()[0]->getName() << std::endl;
    }
    else
    {
    	std::cout << "DriveToPOI: Solution for variable: "
    	                  << this->query->getRelevantStaticVariables()[0]->getName()
						  << " is: "
						  << result[0] << std::endl;
    }
    // TODO for debug
    return;

    /*
     * // MoveBase to nextPOI
//        std::cout << "Movement: Drive to next POI: " << nextPOI->id << std::endl;
//        move_base_msgs::MoveBaseGoal mbg;
//        mbg.target_pose.pose.position.x = nextPOI->x;
//        mbg.target_pose.pose.position.y = nextPOI->y;
//        mbg.target_pose.header.frame_id = "/map";
//        mbg.target_pose.header.seq = this->sequenceCounter++;
//        auto time = this->wm->getTime();
//        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
//        mbg.target_pose.pose.orientation.w = 1;
//        this->goalHandle = this->send(mbg);
     */

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
    query->clearStaticVariables();
    result.clear();
    query->addStaticVariable(getVariablesByName("poi"));
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
