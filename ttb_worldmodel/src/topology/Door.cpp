#include "topology/Door.h"

#include "topology/POI.h"
#include "topology/Room.h"


namespace ttb
{
namespace wm
{

Door::Door(std::string name)
    : open(true)
    , gazeboModel(nullptr)
    , name(name)
	, initialized(false)
{
}

Door::~Door()
{
}

std::string Door::toString()
{
    std::stringstream ss;
    ss << "Door " << this->name << " is opening from Room: " << this->fromRoom->name << " to Room: " << this->toRoom->name <<
     " fromPOI " << this->fromPOI->id << " toPOI " << this->toPOI->id  << std::endl;
    return ss.str();
}

std::size_t Door::hash() const
{
    return std::hash<std::string>()(this->name);
}

} /* namespace wm */
} /* namespace ttb */
