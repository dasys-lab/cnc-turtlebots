#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "geometry_msgs/Twist.h"


#include "ros/ros.h"

namespace supplementary {
	class SystemConfig;
}

namespace ttb {
	class TTBWorldModel;
}

namespace alica
{
	class DomainBehaviour : public BasicBehaviour
	{
	public:
		DomainBehaviour(string name);
		virtual ~DomainBehaviour();
		void send(geometry_msgs::Twist& tw);

	protected:
		supplementary::SystemConfig* sc;

	private:
		int ownID;
		ttb::TTBWorldModel* wm;

		// ros communication stuff for ttb behaviours
		string velocityTopic;
		ros::Publisher mobile_baseCommandVelocityPub;
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

