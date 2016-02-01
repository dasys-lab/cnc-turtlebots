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

    	switch (id) {
			case 1:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Floor1.Y", NULL);
				break;
			case 2:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.HiwiRoom.Y", NULL);
				break;
			case 3:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.StudentLab.Y", NULL);
				break;

			case 4:
				poiX = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.X", NULL);
				poiY = (*this->sc)["POI"]->get<double>("POI.Points.Kicker.Y", NULL);
				break;
			default:
				cout << "I don't know where to go!";
				break;
		}









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
