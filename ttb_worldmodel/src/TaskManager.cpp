/*
 * TaskManager.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#include "TaskManager.h"
#include <tasks/PointOfInterest.h>
#include <tasks/ServeTask.h>
#include <ttb_msgs/ServeTask.h>

namespace ttb
{
namespace wm
{

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::pushTask(shared_ptr<InformationElement<ttb_msgs::ServeTask>> taskMsg)
{
	auto serveTask = make_shared<ServeTask>(taskMsg);
	this->pendingTasks.push_back(make_shared<InformationElement<ServeTask>>(serveTask, taskMsg->timeStamp));
}

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
