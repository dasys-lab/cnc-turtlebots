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
#include <SystemConfig.h>
#include <tasks/PointOfInterest.h>

namespace ttb { namespace wm
{

	enum TaskType {
		SERVE, POI, SEARCH, PICKUP, PUTDOWN
	};

	class TaskManager
	{
	public:
		TaskManager();
		virtual ~TaskManager();

		void pushTask(shared_ptr<InformationElement<ServeTask>> task);

		shared_ptr<InformationElement<ServeTask>> popNextTask();
		shared_ptr<InformationElement<ServeTask>> getNextTask();

		bool isNextTask(TaskType type);

//		POI getPOI(int id);
//		POI popNextPOI();


	private:
		shared_ptr<supplementary::SystemConfig> sc;
		map<int, POI> poiMap;

		vector<shared_ptr<InformationElement<ServeTask>>> pendingTasks;
	};

}} /* namespace ttb */

#endif /* SRC_TASKMANAGER_H_ */
