using namespace std;
#include "Plans/Behaviours/SimpleDrive.h"

/*PROTECTED REGION ID(inccpp1432735451661) ENABLED START*/ //Add additional includes here
#include <kobuki_msgs/BumperEvent.h>
#include <geometry_msgs/Twist.h>
#include <Robot.h>
#include <TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1432735451661) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    SimpleDrive::SimpleDrive() :
            DomainBehaviour("SimpleDrive")
    {
        /*PROTECTED REGION ID(con1432735451661) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    SimpleDrive::~SimpleDrive()
    {
        /*PROTECTED REGION ID(dcon1432735451661) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void SimpleDrive::run(void* msg)
    {
        /*PROTECTED REGION ID(run1432735451661) ENABLED START*/ //Add additional options here
        geometry_msgs::Twist move;

        move.linear.x = 0.3;

        auto bumperEvent = wm->rawSensorData.getBumperEventBuffer()->getLastValidContent();
        if (bumperEvent && bumperEvent->state == kobuki_msgs::BumperEvent::PRESSED)
        {
            this->setSuccess(true);
        }
        else
        {
            robot->movement->send(move);
        }

        /*PROTECTED REGION END*/
    }
    void SimpleDrive::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1432735451661) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1432735451661) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
