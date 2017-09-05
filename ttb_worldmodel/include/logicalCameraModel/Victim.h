/*
 * Victim.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMARAMODEL_VICTIM_H_
#define SRC_LOGICALCAMARAMODEL_VICTIM_H_

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
			Victim(ttb_msgs::LogicalCameraPtr logicalCameraData);
			virtual ~Victim();
		};
	}
}

#endif /* SRC_LOGICALCAMARAMODEL_VICTIM_H_ */
