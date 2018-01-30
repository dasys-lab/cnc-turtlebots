#include "topology/Room.h"

#include "topology/Area.h"
#include "topology/TopologicalDoor.h"
#include "topology/POI.h"

#include <sstream>

namespace ttb
{
namespace wm
{
Room::Room(std::string name, std::shared_ptr<Area> area)
	: name(name)
	, area(area)
{
}

Room::Room(std::string name)
	: name(name)
{
}


Room::~Room()
{
}

std::size_t Room::hash() const
{
	return std::hash<std::string>()(this->name);
}

std::string Room::toString()
{
	std::stringstream ss;
	ss << "\tRoom: " << this->name << " belongs to Area: " << this->area->name << " Hash: " << this->hash() << std::endl;
	ss << "\t\tDoors: " << std::endl;
	for(auto door : this->doors)
	{
		ss << "\t\t\t" << door->toString();
	}
	ss << std::endl;
	return ss.str();
}

} /* namespace wm */
} /* namespace ttb */
