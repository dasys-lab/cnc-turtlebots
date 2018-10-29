#include "Plans/Behaviours/DriveToPOI.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/
// Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <alica/reasoner/DummyVariable.h>
#include <robot/Movement.h>
#include <robot/TTBEnums.h>
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/topology/TopologicalModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

DriveToPOI::DriveToPOI()
    : DomainBehaviour("DriveToPOI")
{
    /*PROTECTED REGION ID(con1454329856163) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    this->goalPOI = nullptr;
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
DriveToPOI::~DriveToPOI()
{
    /*PROTECTED REGION ID(dcon1454329856163) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void DriveToPOI::run(void *msg)
{
    /*PROTECTED REGION ID(run1454329856163) ENABLED START*/
    // Add additional options here
    result.clear();
    if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "DriveToPOI: Unable to get solution for variable: "
                  << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << std::endl;
        return;
    }

    //    std::cout << "DriveToPOI: Solution for variable: "
    //              << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0] <<
    //              std::endl;

    if (this->goalPOI && this->wm->robot.isCloseTo(this->goalPOI))
    {
        this->goalHandle.reset();
        this->turtleBot->movement->cancelAllGoals();
        this->setSuccess(true);
        return;
    }

    if (result[0].compare(alica::reasoner::DummyVariable::NO_VALUE) == 0)
    {
        std::cout << "DriveToPoi: no solution found result contains: " << result[0] << std::endl;
        return;
    }

    auto newGoalPOI = this->wm->topologicalModel.getPOI(stoi(result[0]));
    if (this->goalPOI == nullptr || (this->goalPOI != newGoalPOI && this->wm->robot.isCloseTo(this->goalPOI)))
    {
        this->turtleBot->movement->cancelAllGoals();
        this->goalHandle.reset();
        this->goalPOI = newGoalPOI;
    }
    else if (isMoveBaseDone())
    {
        // MoveBase to nextPOI
        std::cout << "DriveToPOI: Drive to next POI: " << this->goalPOI->id << std::endl;
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = this->goalPOI->x;
        mbg.target_pose.pose.position.y = this->goalPOI->y;
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.header.frame_id = "/map";
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
        this->goalHandle = this->turtleBot->movement->send(mbg);
    }

    /*PROTECTED REGION END*/
}
void DriveToPOI::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/
    // Add additional options here
    this->goalPOI = nullptr;
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariable("poi"));
    this->goalHandle.reset();

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/
// Add additional methods here
bool DriveToPOI::isMoveBaseDone()
{
    if (!this->goalHandle.isExpired() && this->goalHandle.getCommState() == actionlib::CommState::DONE)
    {
        if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::ABORTED)
        {
            //            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
            //                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() <<
            //                      std::endl;
            this->setFailure(true);
        }
        //        else if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::SUCCEEDED)
        //        {
        //            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
        //                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() << std::endl;
        //        }
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
