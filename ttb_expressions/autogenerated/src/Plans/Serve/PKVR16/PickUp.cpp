using namespace std;
#include "Plans/Serve/PKVR16/PickUp.h"

/*PROTECTED REGION ID(inccpp1486381476387) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1486381476387) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    PickUp::PickUp() :
            DomainBehaviour("PickUp")
    {
        /*PROTECTED REGION ID(con1486381476387) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    PickUp::~PickUp()
    {
        /*PROTECTED REGION ID(dcon1486381476387) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void PickUp::run(void* msg)
    {
        /*PROTECTED REGION ID(run1486381476387) ENABLED START*/ //Add additional options here
        cout << "PKVR16::PickUp: Hallo Pizza!" << endl;
        /*PROTECTED REGION END*/
    }
    void PickUp::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1486381476387) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1486381476387) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
