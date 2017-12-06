#pragma once

#include <logicalCameraModel/LogicalObject.h>
#include <ros/ros.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm
	{
		class Fire : public LogicalObject
		{
		public:
			Fire(ttb_msgs::LogicalCameraPtr logicalCameraData, supplementary::InfoTime maxValidityDuration);
			virtual ~Fire();
		};
	}
}
