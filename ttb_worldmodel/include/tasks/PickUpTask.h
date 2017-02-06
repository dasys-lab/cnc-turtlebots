/*
 * PickUpTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_PICKUPTASK_H_
#define SRC_TASKS_PICKUPTASK_H_

#include <tasks/ServeTask.h>

namespace ttb
{
namespace wm
{

class PickUpTask : public ServeTask
{
  public:
    PickUpTask();
    virtual ~PickUpTask();
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_PICKUPTASK_H_ */
