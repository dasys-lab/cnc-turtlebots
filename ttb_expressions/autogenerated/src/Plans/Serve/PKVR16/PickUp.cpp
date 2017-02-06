using namespace std;
#include "Plans/Serve/PKVR16/PickUp.h"

/*PROTECTED REGION ID(inccpp1486381476387) ENABLED START*/ // Add additional includes here
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
    ms.model_name = "football";
    try
    {
        ms.pose.position.x = stod(this->gazeboControlWidget_.ballXEdit->text().toStdString()) / 1000.0;
        ms.pose.position.y = stod(this->gazeboControlWidget_.ballYEdit->text().toStdString()) / 1000.0;
    }
    catch (const std::exception &ex)
    {
        cerr << "GazeboControl: Cannot convert your coordinates. Please enter a correct double coordinates for the ball." << endl;
        ms.pose.position.x = 0;
        ms.pose.position.y = 0;
    }
    ms.pose.position.z = 0;
    ms.reference_frame = "world";
    this->setModelPublisher.publish(ms);
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
