#include "distributed_systems/Area.h"

#include "distributed_systems/AreaDoor.h"

#include <sstream>

namespace ttb
{
namespace wm
{
namespace pathPlanning
{
Area::Area(std::string name)
	: name(name)
{
	this->blocked = false;
}

Area::~Area()
{
}

std::size_t Area::hash() const
{
	return std::hash<std::string>()(this->name);
}

std::string Area::toString()
{
	std::stringstream ss;
	ss << "\tArea: " << this->name << " Hash: " << this->hash() << std::endl;
	ss << "\t\tDoors: " << std::endl;
	for(auto door : this->doors)
	{
		ss << "\t\t\t" << door->toString();
	}
	ss << std::endl;
	return ss.str();
}
}
} /* namespace wm */
} /* namespace ttb */
