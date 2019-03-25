#include "ServiceRobots/Behaviours/Stop.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1553185137554) ENABLED START*/
#include <TurtleBot.h>
#include <geometry_msgs/Twist.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1553185137554) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

Stop::Stop()
        : DomainBehaviour("Stop")
{
    /*PROTECTED REGION ID(con1553185137554) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
Stop::~Stop()
{
    /*PROTECTED REGION ID(dcon1553185137554) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void Stop::run(void* msg)
{
    /*PROTECTED REGION ID(run1553185137554) ENABLED START*/
    geometry_msgs::Twist tw;
    tw.linear.x = 0.0;
    tw.linear.y = 0.0;
    tw.linear.z = 0.0;

    tw.angular.x = 0.0;
    tw.angular.y = 0.0;
    tw.angular.z = 0.0;
    this->turtleBot->movement->send(tw);

    // cancel move base goals
    this->turtleBot->movement->cancelAllGoals();
    /*PROTECTED REGION END*/
}
void Stop::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1553185137554) ENABLED START*/
    // Add additional options here

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1553185137554) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

} /* namespace alica */
