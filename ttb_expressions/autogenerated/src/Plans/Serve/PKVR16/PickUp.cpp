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
	cout<<"PickUp::run picking up!"<<endl;
    gazebo_msgs::ModelState ms;
    //ms.model_name = this->wm->taskManager.getNextTask().entity;
    ms.model_name= 'box_1';
    shared_ptr<geometry::CNPosition> ownPos = this->wm->rawSensorData.getOwnPosition();
    ms.pose.position.x = ownPos->x;
    ms.pose.position.y = ownPos->y;
    ms.pose.position.z = 1;
    ms.reference_frame = "world";
    this->modelPosition_pub.publish(ms);
    // TODO should be done in some virtual actuator of the ttb robot class (antonym of worldmodel)

//    this->setModelPublisher.publish(ms);

    /*PROTECTED REGION END*/
}
void PickUp::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1486381476387) ENABLED START*/ // Add additional options here
	modelPosition_pub = n.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1000);
	/*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1486381476387) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
