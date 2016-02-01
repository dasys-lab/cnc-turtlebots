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

    	double poiX;
    	double poiY;
    	MoveBaseClient mbc("move_base",true);


//    	geometry_msgs::PoseStamped ps;
//    	ps.header.frame_id = "map";
//    	ps.header.stamp = ros::Time::now();
//    	ps.pose.orientation.w = 1;

    	move_base_msgs::MoveBaseGoal mbg;

    	mbg.target_pose.header.frame_id = "map";
    	mbg.target_pose.pose.orientation.w = 1;

//    	mbag.header.frame_id = "map";
//    	mbag.header.stamp = ros::Time::now();
//
//    	mbag.goal.target_pose.header.frame_id = "map";



    	switch (id) {
			case 1:
				cout << "id is 1, setting params for Floor1" << endl;
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.Y", NULL);
				break;
			case 2:
				cout << "id is 2, setting params for HiwiRoom";
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.Y", NULL);
				break;
			case 3:
				cout << "id is 3, setting params for StudentLab1";
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.Y", NULL);
				break;

			case 4:
				cout << "id is 4, setting params for Kicker";
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.Y", NULL);
				break;
			default:
				cout << "I don't know where to go, so I will stay at my current position!" << endl;
				return;
		}

//    	mbag.goal.target_pose.pose.position.x = poiX;
//    	mbag.goal.target_pose.pose.position.x = poiY;

    	mbg.target_pose.pose.position.x = poiX;
    	mbg.target_pose.pose.position.x = poiY;

    	mbc.sendGoal(mbg);
    	mbc.waitForResult();

    	if(mbc.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    		this->success = true;
    	}

//    	ps.pose.position.x = poiX;
//    	ps.pose.position.y = poiY;
//
//    	send(ps);



        /*PROTECTED REGION END*/
    }
    void DriveToPOI::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1454329856163) ENABLED START*/ //Add additional options here
    	string tmp;
        bool success = true;
        success &= getParameter("ID",tmp);
        try
        {
            if (success)
            {
            	id = stod(tmp);
            	cout << "id is " << id << endl;
            }
            success = true;

        }
        catch (exception& e)
        {
            cerr << "Could not cast the parameter properly" << endl;
        }
        if (!success)
        {
            cerr << "Parameter does not exist" << endl;
        }
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1454329856163) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */