/*
 * LogicalObject.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_
#define SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_

#include <geometry_msgs/Pose2D.h>
#include <InformationElement.h>
#include <ros/message_forward.h>
#include <RingBuffer.h>
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
			RingBuffer<InformationElement<geometry_msgs::Pose2D>> poses;
			ttb_msgs::ObjectSize size;
		};
	}
}

#endif /* SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_ */
