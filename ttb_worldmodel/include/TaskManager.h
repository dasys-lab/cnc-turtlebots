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

using namespace std;
namespace ttb
{

	class TaskManager
	{
	public:
		TaskManager();
		virtual ~TaskManager();

		void pushDriveToPOITask(shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> driveToPOITask);

		shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> popNextDriveToPOI();
		shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> getNextDriveToPOI();

	private:
		vector<shared_ptr<InformationElement<ttb_msgs::DriveToPOI>>> unfinishedDriveToPOITasks;
	};

} /* namespace ttb */

#endif /* SRC_TASKMANAGER_H_ */
