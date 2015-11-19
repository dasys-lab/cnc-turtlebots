#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "geometry_msgs/Twist.h"
#include "sound_play/SoundRequest.h"
#include "TTBWorldModel.h"

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

		ttb::TTBWorldModel* wm;

	protected:
		supplementary::SystemConfig* sc;

	private:
		int ownID;

		// ros communication stuff for ttb behaviours
		string soundRequesTopic;
		string velocityTopic;
		ros::Publisher mobile_baseCommandVelocityPub;
		ros::Publisher soundRequestPub;
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

