/*
 * TaskManager.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#include "TaskManager.h"
#include <tasks/DriveToTask.h>
#include <tasks/PickUpTask.h>
#include <tasks/PointOfInterest.h>
#include <tasks/PutDownTask.h>
#include <tasks/SearchTask.h>
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
    switch (task->getInformation()->type)
    {
    case ttb_msgs::ServeTask::PICK_UP:
    {
        auto pickUpTask = make_shared<PickUpTask>();
        this->pendingTasks.push_back(make_shared<InformationElement<ServeTask>>(pickUpTask, task->timeStamp));
    }
    break;
    case ttb_msgs::ServeTask::PUT_DOWN:
    {
        auto pickUpTask = make_shared<PutDownTask>();
        this->pendingTasks.push_back(make_shared<InformationElement<ServeTask>>(pickUpTask, task->timeStamp));
    }
    break;
    case ttb_msgs::ServeTask::SEARCH:
    {
        auto pickUpTask = make_shared<SearchTask>();
        this->pendingTasks.push_back(make_shared<InformationElement<ServeTask>>(pickUpTask, task->timeStamp));
    }
    break;
    case ttb_msgs::ServeTask::DRIVE_TO:
    {
        auto pickUpTask = make_shared<DriveToTask>();
        this->pendingTasks.push_back(make_shared<InformationElement<ServeTask>>(pickUpTask, task->timeStamp));
    }
    break;
    default:
        cerr << "TaskManager: Unknown Task Type received!" << endl;
        break;
    }
}

// POI TaskManager::getPOI(int id)
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
// POI TaskManager::popNextPOI()
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
