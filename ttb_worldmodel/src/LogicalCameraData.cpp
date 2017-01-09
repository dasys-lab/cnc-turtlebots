/*
 * LogicalCameraData.cpp
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#include "LogicalCameraData.h"

namespace ttb
{
	namespace wm
	{
		LogicalCameraData::LogicalCameraData()
		{
			// TODO Auto-generated constructor stub

		}

		LogicalCameraData::~LogicalCameraData()
		{
			// TODO Auto-generated destructor stub
		}

		void LogicalCameraData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData)
		{
			LogicalObject logicalObject;
			string type = logicalCameraData->type;

			switch (type) {
				case "victim":
					logicalObject = new Victim();
					logicalObject.name = logicalCameraData->modelName;
					logicalObject.pose = logicalCameraData->pose;
					logicalObject.size = logicalCameraData->size;
					logicalObject.timeStamp = logicalCameraData->timeStamp;

					break;
				case "fire":

					break;
				case "box":

					break;
				default:
					break;
			}
			this->dict[type] = logicalObject;
		}
	}
}
