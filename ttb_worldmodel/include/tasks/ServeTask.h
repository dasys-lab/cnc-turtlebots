/*
 * ServeTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_SERVETASK_H_
#define SRC_TASKS_SERVETASK_H_
#include <TaskManager.h>

namespace ttb
{
namespace wm
{

class ServeTask
{
  public:
    ServeTask(shared_ptr<InformationElement<ttb_msgs::ServeTask>> taskMsg);
    virtual ~ServeTask();

    TaskType type;
    std::string entity;
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_SERVETASK_H_ */
