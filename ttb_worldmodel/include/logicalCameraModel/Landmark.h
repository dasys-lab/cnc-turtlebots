/*
 * Landmark.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Lab User 8
 */

#ifndef SRC_LOGICALCAMERAMODEL_LANDMARK_H_
#define SRC_LOGICALCAMERAMODEL_LANDMARK_H_

#include <logicalCameraModel/LogicalObject.h>
#include <ros/ros.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
	namespace wm {

	class Landmark : public LogicalObject
	{
	public:
		Landmark(ttb_msgs::LogicalCameraPtr logicalCameraData);
		virtual ~Landmark();
	};
	}
} /* namespace ttb */

#endif /* SRC_LOGICALCAMERAMODEL_LANDMARK_H_ */
