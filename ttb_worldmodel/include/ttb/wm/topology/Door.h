#pragma once

#include "ttb/wm/sim/LogicalObject.h"

namespace ttb
{
namespace wm
{
class LogicalObject;
class Room;
class Area;
class POI;
class Door
{
  public:
    Door(std::string name);
    virtual ~Door();
    std::size_t hash() const;

    std::string name;
    bool open;
    double openAngle;
    std::string aspExternal;
    std::shared_ptr<LogicalObject> gazeboModel;
    std::string toString();
    std::shared_ptr<Room> fromRoom;
    std::shared_ptr<Room> toRoom;
    std::shared_ptr<Area> fromArea;
    std::shared_ptr<Area> toArea;
    std::shared_ptr<POI> fromPOI;
    std::shared_ptr<POI> toPOI;
    bool initialized;
    bool locked;
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
