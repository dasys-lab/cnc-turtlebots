/*
 * DriveToTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_DRIVETOTASK_H_
#define SRC_TASKS_DRIVETOTASK_H_

#include <tasks/ServeTask.h>

namespace ttb
{
namespace wm
{

class DriveToTask : public ServeTask
{
  public:
    DriveToTask();
    virtual ~DriveToTask();
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_DRIVETOTASK_H_ */
