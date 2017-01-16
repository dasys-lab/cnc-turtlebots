/*
 * LogicalCameraData.h
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#ifndef SRC_LOGICALCAMERADATA_H_
#define SRC_LOGICALCAMERADATA_H_

#include <map>
#include <vector>

using namespace std;

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

		private:
			map<string, list<LogicalObject>> dict;
		};
	}
}
#endif /* SRC_LOGICALCAMERADATA_H_ */
