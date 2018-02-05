using namespace std;
#include "Plans/Serve/PKVR16/PickUp.h"

/*PROTECTED REGION ID(inccpp1486381476387) ENABLED START*/ // Add additional includes here
#include <gazebo_msgs/ModelState.h>
#include <TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1486381476387) ENABLED START*/ // initialise static variables here
    /*PROTECTED REGION END*/
    PickUp::PickUp() :
            DomainBehaviour("PickUp")
    {
        /*PROTECTED REGION ID(con1486381476387) ENABLED START*/ // Add additional options here
        /*PROTECTED REGION END*/
    }
    PickUp::~PickUp()
    {
        /*PROTECTED REGION ID(dcon1486381476387) ENABLED START*/ // Add additional options here
        /*PROTECTED REGION END*/
    }
    void PickUp::run(void* msg)
    {
        /*PROTECTED REGION ID(run1486381476387) ENABLED START*/ // Add additional options here
        cout << "PickUp::run picking up!" << endl;
        gazebo_msgs::ModelState ms;
        // ms.model_name = this->wm->taskManager.getNextTask().entity;
        ms.model_name = "box_1";
        std::cout << "PickUp: Before receiving Position!" << std::endl;
        auto ownPos = this->wm->rawSensorData.getOdomPositionBuffer()->getLastValidContent();
        // TODO: Position is always nullopt
        if (ownPos)
        {
            ms.pose.position.x = ownPos->x - 0.12;
            std::cout << "PickUp: Before after Position!" << std::endl;
            ms.pose.position.y = ownPos->y;
            ms.pose.position.z = 0.5;
            ms.reference_frame = "";
            this->modelPosition_pub.publish(ms);
        }
        // TODO should be done in some virtual actuator of the ttb robot class (antonym of worldmodel)

        //    this->setModelPublisher.publish(ms);

        /*PROTECTED REGION END*/
    }
    void PickUp::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1486381476387) ENABLED START*/ // Add additional options here
        modelPosition_pub = n.advertise < gazebo_msgs::ModelState > ("/gazebo/set_model_state", 1000);
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1486381476387) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
