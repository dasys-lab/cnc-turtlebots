/*
 * TaskManager.h
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#ifndef SRC_TASKMANAGER_H_
#define SRC_TASKMANAGER_H_

#include "ttb_msgs/DriveToPOI.h"
#include "InformationElement.h"
#include "POI.h"
#include <SystemConfig.h>

namespace ttb { namespace wm
{

	class TaskManager
	{
	public:
		TaskManager();
		virtual ~TaskManager();

		void pushDriveToPOITask(shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> driveToPOITask);

		shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> popNextDriveToPOI();
		shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> getNextDriveToPOI();

		POI getPOI(int id);
		POI popNextPOI();


	private:
		shared_ptr<supplementary::SystemConfig> sc;
		map<int, POI> poiMap;
		vector<shared_ptr<InformationElement<ttb_msgs::DriveToPOI>>> unfinishedDriveToPOITasks;
	};

}} /* namespace ttb */

#endif /* SRC_TASKMANAGER_H_ */
