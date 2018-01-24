#include "robot/Movement.h"

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

Movement::Movement()
{
	this->sc = supplementary::SystemConfig::getInstance();
    velocityTopic = (*sc)["Drive"]->get<std::string>("Topics.VelocityTopic", NULL);
    mobile_baseCommandVelocityPub = n.advertise<geometry_msgs::Twist>(velocityTopic, 10);

    moveBaseGoalTopic = (*sc)["Drive"]->get<string>("Topics.MoveBaseGoalTopic", NULL);
    move_base_simpleGoalPub = n.advertise<geometry_msgs::PoseStamped>(moveBaseGoalTopic, 10);

    moveBaseActionClientNamespace = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionClientNamespace", NULL);
    ac = new actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>(moveBaseActionClientNamespace, true);

    // TODO: why this topic (currently not used) and how does the simple action client work?
    moveBaseActionGoalTopic = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionGoalTopic", NULL);
    goalActive = false;
}

Movement::~Movement()
{
    // TODO Auto-generated destructor stub
}

void Movement::send(geometry_msgs::PoseStamped &mbsg)
{
    move_base_simpleGoalPub.publish(mbsg);
}

void Movement::send(move_base_msgs::MoveBaseGoal &mbag)
{
    ac->sendGoal(mbag);
    goalActive = true;
}

actionlib::SimpleClientGoalState Movement::getMoveState()
{
    if (goalActive)
    {
        auto state = ac->getState();
        std::cout << "DomainBehaviour::getMoveState(): MoveState requested!" << std::endl;
        return state;
    }
    std::cerr << "DomainBehaviour::getMoveState(): no Goal started" << std::endl;
    return actionlib::SimpleClientGoalState::REJECTED;
}

void Movement::cancelGoal()
{
    ac->cancelAllGoals();
    goalActive = false;
}

void Movement::send(geometry_msgs::Twist &tw)
{
    mobile_baseCommandVelocityPub.publish(tw);
}

} /* namespace robot */
} /* namespace ttb */
