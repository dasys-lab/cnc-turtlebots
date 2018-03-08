#include "ttb/wm/topology/Door.h"

#include "ttb/wm/topology/POI.h"
#include "ttb/wm/topology/Room.h"

namespace ttb
{
namespace wm
{

Door::Door(std::string name)
    : open(false)
    , locked(false)
    , gazeboModel(nullptr)
    , name(name)
    , initialized(false)
    , openAngle(0.0)
{
}

Door::~Door()
{
}

std::string Door::toString()
{
    std::stringstream ss;
    ss << "Door " << this->name << " is opening from Room: " << this->fromRoom->name << " (POI: " << fromPOI->id
       << ") to Room: " << this->toRoom->name << " (POI: " << this->toPOI->id << ")" << std::endl;
    return ss.str();
}

std::size_t Door::hash() const
{
    return std::hash<std::string>()(this->name);
}

} /* namespace wm */
} /* namespace ttb */
