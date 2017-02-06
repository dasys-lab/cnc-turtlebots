/*
 * PutDownTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_PUTDOWNTASK_H_
#define SRC_TASKS_PUTDOWNTASK_H_

#include <tasks/ServeTask.h>

namespace ttb
{
namespace wm
{

class PutDownTask : public ServeTask
{
  public:
    PutDownTask();
    virtual ~PutDownTask();
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_PUTDOWNTASK_H_ */
