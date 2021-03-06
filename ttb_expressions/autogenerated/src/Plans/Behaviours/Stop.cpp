using namespace std;
#include "Plans/Behaviours/Stop.h"

/*PROTECTED REGION ID(inccpp1414681269156) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1414681269156) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Stop::Stop() :
            DomainBehaviour("Stop")
    {
        /*PROTECTED REGION ID(con1414681269156) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    Stop::~Stop()
    {
        /*PROTECTED REGION ID(dcon1414681269156) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Stop::run(void* msg)
    {
        /*PROTECTED REGION ID(run1414681269156) ENABLED START*/ //Add additional options here
        geometry_msgs::Twist tw;
        tw.linear.x = 0.0;
        tw.linear.y = 0.0;
        tw.linear.z = 0.0;

        tw.angular.x = 0.0;
        tw.angular.y = 0.0;
        tw.angular.z = 0.0;
        send(tw);
        /*PROTECTED REGION END*/
    }
    void Stop::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1414681269156) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1414681269156) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
