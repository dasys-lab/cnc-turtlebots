using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ // Add additional includes here
#include <Robot.h>
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
    this->poiID = -1;
    this->nextPOI = nullptr;
    this->currentTask = nullptr;
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
    if (this->goalHandle.isExpired() && this->poiID == 0)
    {
        std::cout << "DriveToPOI: getting new task " << std::endl;
        if (this->currentTask == nullptr)
        {
            this->currentTask = this->wm->taskManager.getNextTask();
            if (this->currentTask && this->currentTask->getInformation().type == ttb_msgs::ServeTask::DRIVE_TO)
            {
                this->wm->taskManager.popNextTask();
            }
            else
            {
                std::cerr << "DriveToPOI: Next task is not of type DRIVE_TO!" << std::endl;
                return;
            }
        }
        auto poi = this->wm->topologicalModel.getPOI(stoi(this->currentTask->getInformation().entity));
        if (!poi)
        {
            std::cerr << "DriveToPOI: POI " << this->currentTask->getInformation().entity << " does not exist!" << std::endl;
            return;
        }

        auto room = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
        if (!room)
        {
            return;
        }
        // Only get a new poi if no path has been given before of nextPOI has been reached
        if (this->nextPOI == nullptr)
        {
            std::cout << "DriveToPOI: getting next POI!" << std::endl;
            this->nextPOI = this->robot->movement->getNextPOI(room.value(), poi);
            std::cout << "DriveToPOI: next POI is: " << this->nextPOI->toString() << std::endl;
        }

        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.pose.position.x = nextPOI->x;
        mbg.target_pose.pose.position.y = nextPOI->y;
        mbg.target_pose.header.frame_id = "/map";

        this->goalHandle = this->robot->movement->send(mbg);
    }
    else if (this->goalHandle.getCommState() == actionlib::CommState::DONE)
    {
        if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::SUCCEEDED)
        {
            this->nextPOI = nullptr;
            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() << std::endl;
            this->goalHandle.reset();
            //				this->setSuccess(true);
        }
        else if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::ABORTED)
        {
            std::cout << "DriveToPOI: CommState: " << this->goalHandle.getCommState().toString()
                      << " TerminalState: " << this->goalHandle.getTerminalState().toString() << std::endl;
            this->setFailure(true);
        }
    }
    /*PROTECTED REGION END*/
}
void DriveToPOI::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/ // Add additional options here
    this->goalHandle.reset();
    try
    {
        string tmp;
        if (getParameter("ID", tmp))
        {
            poiID = stod(tmp);
            cout << "DriveToPOI: POI Id is " << poiID << endl;
        }
        else
        {
            poiID = -1;
            cerr << "Parameter does not exist" << endl;
        }
    }
    catch (exception &e)
    {
        std::cerr << "DriveToPOI: Could not cast the parameter properly!" << std::endl;
    }
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
