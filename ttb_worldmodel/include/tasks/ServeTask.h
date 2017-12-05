#pragma once

#include <TaskManager.h>

#include <supplementary/InformationElement.h>

namespace ttb
{
namespace wm
{

class ServeTask
{
  public:
    ServeTask(shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> taskMsg);
    virtual ~ServeTask();

    TaskType type;
    std::string entity;
};

} /* namespace wm */
} /* namespace ttb */
