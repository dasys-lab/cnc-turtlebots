#include "Plans/Behaviours/ChargingDefault.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1447958115909) ENABLED START*/
// Add additional includes here
#include <TurtleBot.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/SensorState.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1447958115909) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

ChargingDefault::ChargingDefault()
        : DomainBehaviour("ChargingDefault")
{
    /*PROTECTED REGION ID(con1447958115909) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
ChargingDefault::~ChargingDefault()
{
    /*PROTECTED REGION ID(dcon1447958115909) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void ChargingDefault::run(void* msg)
{
    /*PROTECTED REGION ID(run1447958115909) ENABLED START*/
    // Add additional options here
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    if ((*core)->charger == kobuki_msgs::SensorState::DOCKING_CHARGED || (*core)->charger == kobuki_msgs::SensorState::ADAPTER_CHARGED) {
        this->setSuccess();
    } else {
        geometry_msgs::Twist cmd_vel;
        cmd_vel.linear.x = 0;
        cmd_vel.angular.z = 0;
        this->turtleBot->movement->send(cmd_vel);
    }
    /*PROTECTED REGION END*/
}
void ChargingDefault::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1447958115909) ENABLED START*/
    // Add additional options here
    turtleBot->speech->say((*sc)["SpeechAct"]->get<string>("Charging.ChargingText", NULL));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1447958115909) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
