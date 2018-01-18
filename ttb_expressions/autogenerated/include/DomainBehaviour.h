#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "geometry_msgs/Twist.h"
#include "sound_play/SoundRequest.h"
#include "sound_play/sound_play.h"
#include "TTBWorldModel.h"
#include "geometry_msgs/PoseStamped.h"
#include "move_base_msgs/MoveBaseActionGoal.h"
#include "move_base_msgs/MoveBaseAction.h"
#include "move_base_msgs/MoveBaseActionResult.h"
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

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
		void send(geometry_msgs::PoseStamped& mbg);
		void send(move_base_msgs::MoveBaseGoal& mbag);
		actionlib::SimpleClientGoalState getMoveState();
		void cancelGoal();
		ttb::TTBWorldModel* wm;

	protected:
		supplementary::SystemConfig* sc;

	private:
		// ros communication stuff for ttb behaviours
		string soundRequesTopic;
		string velocityTopic;
		string moveBaseGoalTopic;
		string moveBaseActionClientNamespace;
		string moveBaseActionGoalTopic;

		ros::Publisher mobile_baseCommandVelocityPub;
		ros::Publisher soundRequestPub;
		ros::Publisher move_base_simpleGoalPub;
		ros::Publisher move_base_ActionGoalPub;

		actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>* ac;
		bool goalActive;
//		void alica::DomainBehaviour::done_cb();
//		void alica::DomainBehaviour::active_cb();
//		void alica::DomainBehaviour::feedback_cb();
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

