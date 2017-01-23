/*
 * LogicalCameraData.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMERADATA_H_
#define SRC_LOGICALCAMERADATA_H_

#include <logicalCameraModel/LogicalObject.h>
#include <ttb_msgs/LogicalCamera.h>
#include <list>
#include <map>
#include <string>

namespace ttb
{
	namespace wm
	{
		class LogicalCameraData
		{
		public:
			LogicalCameraData();
			virtual ~LogicalCameraData();

			void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData);
			friend std::ostream& operator<<(std::ostream& os,const LogicalCameraData& camData)
			{
				os << "LogicalCameraData: " << std::endl;
				// write obj to stream
				for (auto& pair : camData.dict)
				{
					os << pair.first << ":" << endl;

					for (auto& item : pair.second)
					{
						auto tmpPos = item->poses.getLast()->getInformation();
						os << "\t" << item->name << ": Pos (" << tmpPos->x << ", " << tmpPos->y << ")" << endl;
					}
				}

				return os;
			}

		private:
			map<string, list<shared_ptr<LogicalObject>>> dict;
			shared_ptr<LogicalObject> createLogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData);
		};
	}
}
#endif /* SRC_LOGICALCAMERADATA_H_ */
