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
		mobile_baseCommandVelocityPub = n.advertise<geometry_msgs::Twist>(velocityTopic, 10);
	}

	DomainBehaviour::~DomainBehaviour()
	{
	}

	void alica::DomainBehaviour::send(geometry_msgs::Twist& tw)
	{
		mobile_baseCommandVelocityPub.publish(tw);
	}

} /* namespace alica */
