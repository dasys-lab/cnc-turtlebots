/*
 * SearchTask.h
 *
 *  Created on: Feb 6, 2017
 *      Author: lab-user
 */

#ifndef SRC_TASKS_SEARCHTASK_H_
#define SRC_TASKS_SEARCHTASK_H_

#include <tasks/ServeTask.h>

namespace ttb
{
namespace wm
{

class SearchTask : public ServeTask
{
  public:
    SearchTask();
    virtual ~SearchTask();
};

} /* namespace wm */
} /* namespace ttb */

#endif /* SRC_TASKS_SEARCHTASK_H_ */
