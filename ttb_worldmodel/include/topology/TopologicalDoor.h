#pragma once

#include "Room.h"

#include <memory>

namespace ttb
{
namespace wm
{

class TopologicalDoor
{

  public:
	TopologicalDoor(std::shared_ptr<Room> from, std::shared_ptr<Room> to);
    virtual ~TopologicalDoor();
    std::size_t hash() const;
    std::string toString();
    const std::shared_ptr<Room> fromRoom;
    const std::shared_ptr<Room> toRoom;
    const std::shared_ptr<Area> fromArea;
    const std::shared_ptr<Area> toArea;
};

struct TopologicalDoorComperator
{
    bool operator()(const std::shared_ptr<TopologicalDoor> a, std::shared_ptr<TopologicalDoor> b) const
    {
       return a->hash() == b->hash();
    }
};

struct TopologicalDoorHash
{
    std::size_t operator()(const std::shared_ptr<TopologicalDoor> obj) const
    {
    	return obj->hash();
    }
};

} /* namespace wm */
} /* namespace ttb */
