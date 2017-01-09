#include "DomainBehaviour.h"
#include "engine/AlicaEngine.h"
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
		string robotName = wm->getEngine()->getRobotName() + "/";

		// ros communication for ttb behaviours
		ros::NodeHandle n;
		velocityTopic = robotName + (*sc)["Drive"]->get<string>("Topics.VelocityTopic", NULL);
		soundRequesTopic = robotName + (*sc)["TTBWorldModel"]->get<string>("Sensors.SoundRequestTopic", NULL);

		moveBaseActionGoalTopic = robotName + (*sc)["Drive"]->get<string>("Topics.MoveBaseActionGoalTopic", NULL);
		moveBaseGoalTopic = robotName + (*sc)["Drive"]->get<string>("Topics.MoveBaseGoalTopic", NULL);

		mobile_baseCommandVelocityPub = n.advertise<geometry_msgs::Twist>(velocityTopic, 10);
		soundRequestPub = n.advertise<sound_play::SoundRequest>(soundRequesTopic, 10);

		move_base_simpleGoalPub = n.advertise<geometry_msgs::PoseStamped>(moveBaseGoalTopic, 10);

		ac = new actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>("move", true);

		goalActive = false;
	}

	DomainBehaviour::~DomainBehaviour()
	{
		delete ac;
	}

	void alica::DomainBehaviour::send(geometry_msgs::Twist& tw)
	{
		mobile_baseCommandVelocityPub.publish(tw);
	}
	void alica::DomainBehaviour::send(sound_play::SoundRequest& sr)
	{
		soundRequestPub.publish(sr);
	}

	void alica::DomainBehaviour::send(geometry_msgs::PoseStamped& mbsg)
	{
		move_base_simpleGoalPub.publish(mbsg);
	}

	void alica::DomainBehaviour::send(move_base_msgs::MoveBaseGoal& mbag)
	{
		ac->sendGoal(mbag);
		goalActive = true;
	}

	actionlib::SimpleClientGoalState alica::DomainBehaviour::getMoveState()
	{
		if (goalActive)
		{
			auto state = ac->getState();
			cout << "DomainBehaviour::getMoveState(): MoveState requested!" << endl;
			return state;
		}
		cerr << "DomainBehaviour::getMoveState(): no Goal started" << endl;
		return actionlib::SimpleClientGoalState::REJECTED;

	}

	void alica::DomainBehaviour::cancelGoal()
	{
		ac->cancelAllGoals();
		goalActive = false;
	}

} /* namespace alica */
