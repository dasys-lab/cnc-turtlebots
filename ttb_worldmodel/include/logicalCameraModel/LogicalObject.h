#pragma once

#include <geometry_msgs/Pose2D.h>
#include <ros/message_forward.h>
#include <supplementary/InfoBuffer.h>
#include <ttb_msgs/ObjectSize.h>
#include <string>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm
	{
		class LogicalObject
		{
		public:
			LogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData, int ringBufferLength = 10);
			virtual ~LogicalObject();

			void processData(ttb_msgs::LogicalCameraPtr logicalCameraData);

			std::string name;
			supplementary::InfoBuffer<geometry_msgs::Pose2D> poses;
			ttb_msgs::ObjectSize size;
		};
	}
}
