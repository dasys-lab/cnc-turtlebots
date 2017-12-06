#pragma once

#include <logicalCameraModel/LogicalObject.h>
#include <ros/message_forward.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm
	{
		class Victim : public LogicalObject
		{
		public:
			Victim(ttb_msgs::LogicalCameraPtr logicalCameraData, supplementary::InfoTime maxValidityDuration);
			virtual ~Victim();
		};
	}
}
