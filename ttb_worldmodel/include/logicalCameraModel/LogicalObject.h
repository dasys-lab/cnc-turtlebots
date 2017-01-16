/*
 * LogicalObject.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_
#define SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_

using namespace std;

namespace ttb
{
	namespace wm
	{
		class LogicalObject
		{
		public:
			LogicalObject();
			virtual ~LogicalObject();
			string name;
			geometry_msgs::Pose2D pose;
			ttb_msgs::ObjectSize size;
			ros::Time timeStamp;

		};
	}
}

#endif /* SRC_LOGICALCAMARAMODEL_LOGICALOBJECT_H_ */
