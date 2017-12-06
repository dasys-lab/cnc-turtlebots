#pragma once

#include "logicalCameraModel/LogicalObject.h"

#include <ros/ros.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm
	{
		class Box : public LogicalObject
		{
		public:
			Box(ttb_msgs::LogicalCameraPtr logicalCameraData);
			virtual ~Box();

		private:

		};
	}
}
