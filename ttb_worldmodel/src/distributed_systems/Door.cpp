#include "distributed_systems/Door.h"

#include "distributed_systems/Room.h"

#include <iostream>
#include <sstream>

namespace ttb
{
namespace wm
{

Door::Door(std::shared_ptr<Room> from, std::shared_ptr<Room> to)
	: from(from)
	, to(to)
{
    this->open = true;
}

Door::~Door()
{
}

std::size_t Door::hash() const
{
	std::stringstream ss;
	ss << this->from->name << this->to->name << this << std::endl;
	return std::hash<std::string>()(ss.str());
}

std::string Door::toString()
{
	std::stringstream ss;
	ss << "Door is opening from Room: " << this->from->name << " to Room: " << this->to->name << " Hash: " << this->hash() <<  std::endl;
	return ss.str();
}

} /* namespace wm */
} /* namespace ttb */
