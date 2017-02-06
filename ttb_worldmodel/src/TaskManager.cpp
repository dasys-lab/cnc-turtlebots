/*
 * TaskManager.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#include "TaskManager.h"
#include <tasks/ServeTask.h>
#include <ttb_msgs/ServeTask.h>

namespace ttb
{
namespace wm
{

TaskManager::TaskManager()
{
    auto poiSections = (*this->sc)["POI"]->getSections("POI.Points", NULL);
    for (auto &poiSectionName : (*poiSections))
    {
    	PointOfInterest currentPOI((*this->sc)["POI"]->get<int>("POI.Points", poiSectionName.c_str(), "ID", NULL), poiSectionName,
                       (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "X", NULL),
                       (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "Y", NULL));
        this->poiMap.emplace(currentPOI.id, currentPOI);
    }
}

TaskManager::~TaskManager()
{
}

void TaskManager::pushTask(shared_ptr<InformationElement<ttb_msgs::ServeTask>> task)
{
    // TODO: convert msg into world model object of corresponding type
    //this->pendingTasks.push_back(task);
}

//POI TaskManager::getPOI(int id)
//{
//    auto iter = this->poiMap.find(id);
//    if (iter != this->poiMap.end())
//    {
//        return iter->second;
//    }
//    else
//    {
//        return POI();
//    }
//}
//
//POI TaskManager::popNextPOI()
//{
//    auto driveToPOI = this->popNextDriveToPOI();
//    auto iter = this->poiMap.find(driveToPOI->getInformation()->poiId);
//    if (iter != this->poiMap.end())
//    {
//        return iter->second;
//    }
//    else
//    {
//        return POI();
//    }
//}

shared_ptr<InformationElement<ServeTask>> TaskManager::popNextTask()
{
    if (this->pendingTasks.size() > 0)
    {
        auto nextTask = this->pendingTasks[0];
        this->pendingTasks.erase(this->pendingTasks.begin());
        return nextTask;
    }
    else
    {
        return nullptr;
    }
}

shared_ptr<InformationElement<ServeTask>> TaskManager::getNextTask()
{
    if (this->pendingTasks.size() > 0)
    {
        auto nextTask = this->pendingTasks[0];
        return nextTask;
    }
    else
    {
        return nullptr;
    }
}

bool TaskManager::isNextTask(TaskType type)
{
    if (this->pendingTasks.size() > 0)
    {
        return this->pendingTasks[0]->getInformation()->type == type;
    }
    else
    {
        return false;
    }
}
}
} /* namespace ttb */
