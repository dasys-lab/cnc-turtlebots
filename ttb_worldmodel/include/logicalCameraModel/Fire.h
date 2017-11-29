/*
 * Fire.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMARAMODEL_FIRE_H_
#define SRC_LOGICALCAMARAMODEL_FIRE_H_

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
			Fire(ttb_msgs::LogicalCameraPtr logicalCameraData);
			virtual ~Fire();
		};
	}
}

#endif /* SRC_LOGICALCAMARAMODEL_FIRE_H_ */
