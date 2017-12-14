#pragma once
#include "distributed_systems/Door.h"

namespace ttb
{
namespace wm
{

class Room;
class Area;
class AreaDoor : public Door
{
  public:
    AreaDoor(std::shared_ptr<Room> from, std::shared_ptr<Room> to);
    virtual ~AreaDoor();
    std::string toString();
    const std::shared_ptr<Area> fromArea;
    const std::shared_ptr<Area> toArea;
};

} /* namespace wm */
} /* namespace ttb */
