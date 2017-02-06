/*
 * ServeTask.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#include "tasks/ServeTask.h"
#include "ttb_msgs/ServeTask.h"

namespace ttb
{
namespace wm
{

ServeTask::ServeTask(shared_ptr<InformationElement<ttb_msgs::ServeTask>> taskMsg) : entity(taskMsg->getInformation()->entitiy)
{
	switch(taskMsg->getInformation()->type)
	{
		case ttb_msgs::ServeTask::PICK_UP:
			this->type = TaskType::PICKUP;
			break;
		case ttb_msgs::ServeTask::PUT_DOWN:
			this->type = TaskType::PICKUP;
			break;
		case ttb_msgs::ServeTask::SEARCH:
			this->type = TaskType::SEARCH;
			break;
		case ttb_msgs::ServeTask::DRIVE_TO:
			this->type = TaskType::POI;
			break;
		default:
			this->type = TaskType::SERVE;
			break;
	}
}

ServeTask::~ServeTask()
{
    // TODO Auto-generated destructor stub
}

} /* namespace wm */
} /* namespace ttb */
