using namespace std;
#include "Plans/Serve/PKVR16/PickUp.h"

/*PROTECTED REGION ID(inccpp1486381476387) ENABLED START*/ // Add additional includes here
#include "gazebo_msgs/ModelState.h"
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1486381476387) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
PickUp::PickUp()
    : DomainBehaviour("PickUp")
{
    /*PROTECTED REGION ID(con1486381476387) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
PickUp::~PickUp()
{
    /*PROTECTED REGION ID(dcon1486381476387) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void PickUp::run(void *msg)
{
    /*PROTECTED REGION ID(run1486381476387) ENABLED START*/ // Add additional options here
    cout << "PKVR16::PickUp: Hallo Pizza!" << endl;
    gazebo_msgs::ModelState ms;

    // TODO should be done in some virtual actuator of the ttb robot class (antonym of worldmodel)
//    ms.model_name = "";
//    ms.pose.position.x = 0;
//    ms.pose.position.y = 0;
//    ms.pose.position.z = 0;
//    ms.reference_frame = "world";
//    this->setModelPublisher.publish(ms);

    /*PROTECTED REGION END*/
}
void PickUp::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1486381476387) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1486381476387) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
