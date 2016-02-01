/*
 * TaskManager.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#include "TaskManager.h"

namespace ttb
{

	TaskManager::TaskManager()
	{
		// TODO Auto-generated constructor stub
	}

	TaskManager::~TaskManager()
	{
		// TODO Auto-generated destructor stub
	}

	void TaskManager::pushDriveToPOITask(shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> driveToPOITask)
	{
		this->unfinishedDriveToPOITasks.push_back(driveToPOITask);
	}

	shared_ptr<InformationElement<ttb_msgs::DriveToPOI> > TaskManager::popNextDriveToPOI()
	{
		if (this->unfinishedDriveToPOITasks.size() > 0)
		{
			auto nextTask = this->unfinishedDriveToPOITasks[0];
			this->unfinishedDriveToPOITasks.erase(this->unfinishedDriveToPOITasks.begin());
			return nextTask;
		}
		else
		{
			return nullptr;
		}
	}

	shared_ptr<InformationElement<ttb_msgs::DriveToPOI> > TaskManager::getNextDriveToPOI()
	{
		if (this->unfinishedDriveToPOITasks.size() > 0)
		{
			auto nextTask = this->unfinishedDriveToPOITasks[0];
			return nextTask;
		}
		else
		{
			return nullptr;
		}
	}

} /* namespace ttb */
