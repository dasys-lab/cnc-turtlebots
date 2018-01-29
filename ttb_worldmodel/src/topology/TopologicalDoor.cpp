#include "topology/TopologicalDoor.h"

#include "topology/Room.h"

#include <iostream>
#include <sstream>

namespace ttb
{
namespace wm
{
TopologicalDoor::TopologicalDoor(std::shared_ptr<Room> from, std::shared_ptr<Room> to)
    : fromRoom(from)
    , toRoom(to)
{
}

TopologicalDoor::~TopologicalDoor()
{
}

std::size_t TopologicalDoor::hash() const
{
    std::stringstream ss;
    // TODO: make door unique, although two doors per connection exist
    ss << this->fromRoom->name << this->toRoom->name << std::endl;
    return std::hash<std::string>()(ss.str());
}

std::string TopologicalDoor::toString()
{
    std::stringstream ss;
    ss << "TopologicalDoor is opening from Room: " << this->fromRoom->name << " to Room: " << this->toRoom->name << " Hash: " << this->hash() << std::endl;
    return ss.str();
}
} /* namespace wm */
} /* namespace ttb */
