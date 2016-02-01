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
		auto poiSections = (*this->sc)["POI"]->getSections("POI.Points", NULL);
		for (auto& poiSectionName : (*poiSections))
		{
			POI currentPOI (
				(*this->sc)["POI"]->get<int>("POI.Points", poiSectionName.c_str(), "ID", NULL),
				poiSectionName,
				(*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "Y", NULL)
			);
			this->poiMap.emplace(currentPOI.id, currentPOI);		}
	}

	TaskManager::~TaskManager()
	{
		// TODO Auto-generated destructor stub
	}

	void TaskManager::pushDriveToPOITask(shared_ptr<InformationElement<ttb_msgs::DriveToPOI>> driveToPOITask)
	{
		if (this->poiMap.find(driveToPOITask->getInformation()->poiId) != this->poiMap.end())
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
