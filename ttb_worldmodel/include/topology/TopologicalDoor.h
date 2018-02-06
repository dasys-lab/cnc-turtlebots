#pragma once

#include <vector>
#include <memory>

namespace ttb
{
namespace wm
{

class Room;
class Area;
class POI;
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
    std::shared_ptr<POI> fromPOI;
    std::shared_ptr<POI> toPOI;
};

} /* namespace wm */
} /* namespace ttb */
