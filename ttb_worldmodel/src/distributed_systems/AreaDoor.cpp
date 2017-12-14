#include "distributed_systems/AreaDoor.h"

#include "distributed_systems/Area.h"
#include "distributed_systems/Room.h"

#include <sstream>

namespace ttb
{
namespace wm
{

AreaDoor::AreaDoor(std::shared_ptr<Room> from, std::shared_ptr<Room> to)
    : Door(from, to)
	, fromArea(from->area)
	, toArea(to->area)
{
}

AreaDoor::~AreaDoor()
{
}

std::string AreaDoor::toString()
{
	std::stringstream ss;
	ss << Door::toString();
	ss << "\t\t\tDoor leading from Area: " << this->fromArea->name << " to Area: " << toArea->name << std::endl;
	ss << std::endl;
	return ss.str();
}

} /* namespace wm */
} /* namespace ttb */
