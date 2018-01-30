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
    std::string toString();
    std::shared_ptr<Room> fromRoom;
    std::shared_ptr<Room> toRoom;
    std::shared_ptr<Area> fromArea;
    std::shared_ptr<Area> toArea;
};

} /* namespace wm */
} /* namespace ttb */
