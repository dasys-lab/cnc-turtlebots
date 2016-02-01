using namespace std;
#include "Plans/Behaviours/DriveToPOI.h"

/*PROTECTED REGION ID(inccpp1454329856163) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1454329856163) ENABLED START*/ //initialise static variables here
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
    	move_base_msgs::MoveBaseActionGoal mbag;
    	mbag.goal.target_pose.header.frame_id = "'map'";


    	switch (id) {
			case 1:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.Y", NULL);
				cout << "id is 1, setting params for Floor1";
				break;
			case 2:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.Y", NULL);
				cout << "id is 2, setting params for HiwiRoom";
				break;
			case 3:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.Y", NULL);
				cout << "id is 3, setting params for StudentLab1";
				break;

			case 4:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.Y", NULL);
				cout << "id is 4, setting params for Kicker";
				break;
			default:
				cout << "I don't know where to go, so I will stay at my current position!";
				return;
		}

    	mbag.goal.target_pose.pose.position.x = poiX;
    	mbag.goal.target_pose.pose.position.y = poiY;

    	send(mbag);


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
            	cout << "id is " << id;
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
