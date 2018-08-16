using namespace std;
#include "Plans/Behaviours/DriveToPoint.h"

/*PROTECTED REGION ID(inccpp1520850811997) ENABLED START*/ // Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1520850811997) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
DriveToPoint::DriveToPoint()
    : DomainBehaviour("DriveToPoint")
{
    /*PROTECTED REGION ID(con1520850811997) ENABLED START*/ // Add additional options here
    this->query = std::make_shared<alica::Query>();
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
DriveToPoint::~DriveToPoint()
{
    /*PROTECTED REGION ID(dcon1520850811997) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void DriveToPoint::run(void *msg)
{
    /*PROTECTED REGION ID(run1520850811997) ENABLED START*/ // Add additional options here
    result.clear();
    if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
    {
        std::cout << "DriveToPoint: Unable to get solution for variables: "
                  << this->query->getUniqueVariableStore()->getAllRep()[0]->getName()
                  << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << std::endl;
        return;
    }

    //    std::cout << "DriveToPoint: Solution for variable: " <<
    //    this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
    //              << "for variable " << this->query->getUniqueVariableStore()->getAllRep()[1]->getName() << " is: " <<
    //              result[1] << "for variable " << std::endl;

    if (this->wm->robot.isCloseTo(stod(result[0]), stod(result[1]), this->turtleBot->simulatedArm->getArmRange() / 2.0))
    {
        this->goalHandle.reset();
        this->turtleBot->movement->cancelAllGoals();
        this->setSuccess(true);
        return;
    }

    if (isMoveBaseDone())
    {
        // MoveBase to nextPOI
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = stod(result[0]);
        mbg.target_pose.pose.position.y = stod(result[1]);
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.header.frame_id = "/map";
        auto time = this->wm->getTime();
        mbg.target_pose.header.stamp = ros::Time((uint32_t)(time / 1000000000UL), (uint32_t)(time % 1000000000UL));
        this->goalHandle = this->turtleBot->movement->send(mbg);
    }
    /*PROTECTED REGION END*/
}
void DriveToPoint::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1520850811997) ENABLED START*/ // Add additional options here
    this->query->clearStaticVariables();
    this->result.clear();
    this->query->addStaticVariable(getVariableByName("x"));
    this->query->addStaticVariable(getVariableByName("y"));
    this->goalHandle.reset();
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1520850811997) ENABLED START*/ // Add additional methods here
bool DriveToPoint::isMoveBaseDone()
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
