#pragma once

#include "LogicalObject.h"
#include "topology/TopologicalDoor.h"

namespace ttb
{
namespace wm
{
class LogicalObject;

class Door
{
  public:
    Door(std::string name);
    virtual ~Door();

    std::string name;
    bool open;
    std::string aspExternal;
    LogicalObject* gazeboModel;
    std::shared_ptr<TopologicalDoor> topologicalDoor;

};

} /* namespace wm */
} /* namespace ttb */

