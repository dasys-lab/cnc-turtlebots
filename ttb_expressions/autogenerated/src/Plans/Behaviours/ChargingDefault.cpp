using namespace std;
#include "Plans/Behaviours/ChargingDefault.h"

/*PROTECTED REGION ID(inccpp1447958115909) ENABLED START*/ // Add additional includes here
#include <kobuki_msgs/SensorState.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1447958115909) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
ChargingDefault::ChargingDefault()
    : DomainBehaviour("ChargingDefault")
{
    /*PROTECTED REGION ID(con1447958115909) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
ChargingDefault::~ChargingDefault()
{
    /*PROTECTED REGION ID(dcon1447958115909) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void ChargingDefault::run(void *msg)
{
    /*PROTECTED REGION ID(run1447958115909) ENABLED START*/ // Add additional options here
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer().getLastValidContent();
    if ((int)core->charger == kobuki_msgs::SensorState::DOCKING_CHARGED ||
        (int)core->charger == kobuki_msgs::SensorState::ADAPTER_CHARGED)
    {
        this->setSuccess(true);
    }
    else
    {
        geometry_msgs::Twist cmd_vel;
        cmd_vel.linear.x = 0;
        cmd_vel.angular.z = 0;
        send(cmd_vel);
    }
    /*PROTECTED REGION END*/
}
void ChargingDefault::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1447958115909) ENABLED START*/ // Add additional options here
    sound_play::SoundClient sound_client;
    sound_client.say((*sc)["SpeechAct"]->get<string>("Charging.ChargingText", NULL));
    //		sound_play::SoundRequest msg;
    //		msg.arg = (*sc)["SpeechAct"]->get<string>("Charging.ChargingText", NULL);
    //		msg.command = sound_play::SoundRequest::PLAY_ONCE;
    //		msg.sound = sound_play::SoundRequest::SAY;
    //		send(msg);

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1447958115909) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
