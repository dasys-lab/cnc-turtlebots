#include "DomainBehaviour.h"

#include "SystemConfig.h"

namespace alica
{
	DomainBehaviour::DomainBehaviour(string name) :
			BasicBehaviour(name)
	{
		sc = supplementary::SystemConfig::getInstance();

		// usefull stuff for general ttb behaviour programming
		ownID = sc->getOwnRobotID();
		wm = ttb::TTBWorldModel::get();

		// ros communication for ttb behaviours
		ros::NodeHandle n;
		velocityTopic = (*sc)["Drive"]->get<string>("Topics.VelocityTopic", NULL);
		soundRequesTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.SoundRequestTopic", NULL);

		moveBaseActionGoalTopic = (*sc)["Drive"]->get<string>("Topics.MoveBaseActionGoalTopic", NULL);
		moveBaseGoalTopic = (*sc)["Drive"]->get<string>("Topics.MoveBaseGoalTopic", NULL);


		mobile_baseCommandVelocityPub = n.advertise<geometry_msgs::Twist>(velocityTopic, 10);
		soundRequestPub = n.advertise<sound_play::SoundRequest>(soundRequesTopic, 10);

		move_base_ActionGoalPub = n.advertise<move_base_msgs::MoveBaseActionGoal>(moveBaseActionGoalTopic, 10);
		move_base_simpleGoalPub = n.advertise<geometry_msgs::PoseStamped>(moveBaseGoalTopic, 10);
	}

	DomainBehaviour::~DomainBehaviour()
	{
	}

	void alica::DomainBehaviour::send(geometry_msgs::Twist& tw)
	{
		mobile_baseCommandVelocityPub.publish(tw);
	}
	void alica::DomainBehaviour::send(sound_play::SoundRequest& sr) {
		soundRequestPub.publish(sr);
	}

	void alica::DomainBehaviour::send(geometry_msgs::PoseStamped& mbsg) {
		move_base_simpleGoalPub.publish(mbsg);
	}

	void alica::DomainBehaviour::send(move_base_msgs::MoveBaseActionGoal& mbag) {
		move_base_ActionGoalPub.publish(mbag);
	}
} /* namespace alica */
