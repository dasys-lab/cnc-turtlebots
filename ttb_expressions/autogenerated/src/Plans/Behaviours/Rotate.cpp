using namespace std;
#include "Plans/Behaviours/Rotate.h"

/*PROTECTED REGION ID(inccpp1447068205139) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1447068205139) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Rotate::Rotate() :
            DomainBehaviour("Rotate")
    {
        /*PROTECTED REGION ID(con1447068205139) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    Rotate::~Rotate()
    {
        /*PROTECTED REGION ID(dcon1447068205139) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Rotate::run(void* msg)
    {
        /*PROTECTED REGION ID(run1447068205139) ENABLED START*/ //Add additional options here

    	geometry_msgs::Twist rotate;

    	rotate.angular.z = 1;


    	if(counter <= 	60 ) {
    		send(rotate);
    		counter++;
    	} else {
    		this->success = true;
    	}
    	auto i = wm->rawSensorData.getOwnBumperEvents();

        /*PROTECTED REGION END*/
    }
    void Rotate::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1447068205139) ENABLED START*/ //Add additional options here
    	counter = 0;
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1447068205139) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
