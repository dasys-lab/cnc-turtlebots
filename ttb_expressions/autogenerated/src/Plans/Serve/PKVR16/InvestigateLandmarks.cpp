using namespace std;
#include "Plans/Serve/PKVR16/InvestigateLandmarks.h"

/*PROTECTED REGION ID(inccpp1485780420922) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1485780420922) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    InvestigateLandmarks::InvestigateLandmarks() :
            DomainBehaviour("InvestigateLandmarks")
    {
        /*PROTECTED REGION ID(con1485780420922) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    InvestigateLandmarks::~InvestigateLandmarks()
    {
        /*PROTECTED REGION ID(dcon1485780420922) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void InvestigateLandmarks::run(void* msg)
    {
        /*PROTECTED REGION ID(run1485780420922) ENABLED START*/ //Add additional options here
        cout << "PKVR16::InvestigateLandmarks: Hallo Pizza!" << endl;
        /*PROTECTED REGION END*/
    }
    void InvestigateLandmarks::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1485780420922) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1485780420922) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
