#include "tasks/ServeTask.h"
#include "ttb_msgs/ServeTask.h"

using supplementary::InformationElement;

namespace ttb
{
namespace wm
{

ServeTask::ServeTask(shared_ptr<InformationElement<ttb_msgs::ServeTask>> taskMsg) : entity(taskMsg->getInformation().entity)
{
	switch(taskMsg->getInformation().type)
	{
		case ttb_msgs::ServeTask::PICK_UP:
			this->type = TaskType::PICK_UP;
			break;
		case ttb_msgs::ServeTask::PUT_DOWN:
			this->type = TaskType::PUT_DOWN;
			break;
		case ttb_msgs::ServeTask::SEARCH:
			this->type = TaskType::SEARCH;
			break;
		case ttb_msgs::ServeTask::DRIVE_TO:
			this->type = TaskType::DRIVE_TO;
			break;
		default:
			this->type = TaskType::SERVE;
			break;
	}
}

ServeTask::~ServeTask()
{
}

} /* namespace wm */
} /* namespace ttb */
