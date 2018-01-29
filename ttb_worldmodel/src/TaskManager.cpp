#include "TaskManager.h"

#include <ttb_msgs/ServeTask.h>

using supplementary::InformationElement;

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
	this->pendingTasks.push_back(taskMsg);
}

shared_ptr<InformationElement<ttb_msgs::ServeTask>> TaskManager::popNextTask()
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

shared_ptr<InformationElement<ttb_msgs::ServeTask>> TaskManager::getNextTask()
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

bool TaskManager::isNextTask(ttb_msgs::ServeTask::_type_type type)
{
    if (this->pendingTasks.size() > 0)
    {
        return this->pendingTasks[0]->getInformation().type == type;
    }
    else
    {
        return false;
    }
}

}
} /* namespace ttb */
