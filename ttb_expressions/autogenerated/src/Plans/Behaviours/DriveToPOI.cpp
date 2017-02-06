 using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ //Add additional includes here
#include "actionlib/client/simple_action_client.h"
#include "move_base_msgs/MoveBaseAction.h"
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/ //initialise static variables here
    typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
    /*PROTECTED REGION END*/
    DriveToPOI::DriveToPOI() :
            DomainBehaviour("DriveToPOI")
    {
        /*PROTECTED REGION ID(con1454329856163) ENABLED START*/ //Add additional options here
        id = -1;
        /*PROTECTED REGION END*/
    }
    DriveToPOI::~DriveToPOI()
    {
        /*PROTECTED REGION ID(dcon1454329856163) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void DriveToPOI::run(void* msg)
    {
        /*PROTECTED REGION ID(run1454329856163) ENABLED START*/ //Add additional options here
        ttb::wm::PointOfInterest currentPOI;
        // TODO
//        if (this->id == 0)
//        {
//            currentPOI = this->wm->taskManager.popNextTask();
//        }
//        else
//        {
//            currentPOI = this->wm->taskManager.getPOI(id);
//        }

        MoveBaseClient mbc("move_base", true);

//    	mbag.header.frame_id = "map";
//    	mbag.header.stamp = ros::Time::now();
//    	mbag.goal.target_pose.header.frame_id = "map";
//    	mbag.goal.target_pose.pose.position.x = poiX;
//    	mbag.goal.target_pose.pose.position.x = poiY;

        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.header.frame_id = "map";
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.pose.position.x = currentPOI.x;
        mbg.target_pose.pose.position.y = currentPOI.y;

        mbc.sendGoal(mbg);
        mbc.waitForResult();

        if (mbc.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        {
            this->setSuccess(true);
        }

//    	geometry_msgs::PoseStamped ps;
//		ps.header.frame_id = "map";
//		ps.header.stamp = ros::Time::now();
//		ps.pose.orientation.w = 1;
//    	ps.pose.position.x = currentPOI.x;
//    	ps.pose.position.y = currentPOI.y;
//    	send(ps);
        /*PROTECTED REGION END*/
    }
    void DriveToPOI::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/ //Add additional options here
        try
        {
            string tmp;
            if (getParameter("ID", tmp))
            {
                id = stod(tmp);
                cout << "DriveToPOI: POI Id is " << id << endl;
            }
            else
            {
                id = -1;
                cerr << "Parameter does not exist" << endl;
            }
        }
        catch (exception& e)
        {
            cerr << "Could not cast the parameter properly" << endl;
        }
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
