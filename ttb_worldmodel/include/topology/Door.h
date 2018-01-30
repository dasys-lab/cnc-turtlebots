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
    std::size_t hash() const;

    std::string name;
    bool open;
    std::string aspExternal;
    LogicalObject* gazeboModel;
    std::shared_ptr<TopologicalDoor> topologicalDoor;

};

struct DoorComperator
{
    bool operator()(const std::shared_ptr<Door> a, std::shared_ptr<Door> b) const
    {
       return a->hash() == b->hash();
    }
};

struct DoorHash
{
    std::size_t operator()(const std::shared_ptr<Door> obj) const
    {
    	return obj->hash();
    }
};

} /* namespace wm */
} /* namespace ttb */

