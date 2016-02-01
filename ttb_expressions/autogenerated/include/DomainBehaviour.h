#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "geometry_msgs/Twist.h"
#include "sound_play/SoundRequest.h"
#include "sound_play/sound_play.h"
#include "TTBWorldModel.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

#include "ros/ros.h"

namespace supplementary {
	class SystemConfig;
}


namespace alica
{
	class DomainBehaviour : public BasicBehaviour
	{
	public:
		DomainBehaviour(string name);
		virtual ~DomainBehaviour();

		void send(geometry_msgs::Twist& tw);
		void send(sound_play::SoundRequest& sr);
		void send(move_base_msgs::MoveBaseActionGoal& mbag);

		ttb::TTBWorldModel* wm;

	protected:
		supplementary::SystemConfig* sc;

	private:
		int ownID;

		// ros communication stuff for ttb behaviours
		string soundRequesTopic;
		string velocityTopic;
		string moveBaseGoalTopic;
		ros::Publisher mobile_baseCommandVelocityPub;
		ros::Publisher soundRequestPub;
		ros::Publisher move_baseActionGoalPub;
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

