using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ // Add additional includes here
#include <Robot.h>
#include <TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
DriveToPOI::DriveToPOI()
    : DomainBehaviour("DriveToPOI")
{
    /*PROTECTED REGION ID(con1454329856163) ENABLED START*/ // Add additional options here
    poiID = -1;
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
    if (this->goalHandle.isExpired())
    {
        auto task = this->wm->taskManager.getNextTask();
        if (task->getInformation().type == ttb_msgs::ServeTask::DRIVE_TO)
        {
            this->wm->taskManager.popNextTask();
        }
        else
        {
            std::cerr << "DriveToPOI: Next task is not of type DRIVE_TO!" << std::endl;
            return;
        }

        auto poi = this->wm->pois.getPOIByName(task->getInformation().entity);
        if (!poi)
        {
            std::cerr << "DriveToPOI: POI " << task->getInformation().entity << " does not exist!" << std::endl;
            return;
        }

        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.pose.position.x = poi->x;
        mbg.target_pose.pose.position.y = poi->y;
        mbg.target_pose.header.frame_id = "/map";
        this->goalHandle = this->robot->movement->send(mbg);
    }

    if (this->goalHandle.getCommState() == actionlib::CommState::DONE)
    {
    	if (this->goalHandle.getTerminalState().state_ == actionlib::TerminalState::SUCCEEDED)
    	{
    		this->setSuccess(true);
    	}
    }
    /*PROTECTED REGION END*/
}
void DriveToPOI::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/ // Add additional options here
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
