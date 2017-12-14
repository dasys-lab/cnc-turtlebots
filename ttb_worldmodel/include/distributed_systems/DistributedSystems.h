#pragma once

#include "distributed_systems/Area.h"
#include "distributed_systems/Door.h"
#include "distributed_systems/Room.h"

#include <memory>
#include <unordered_set>

namespace supplementary
{
class SystemConfig;
}

namespace ttb
{
namespace wm
{

class DistributedSystems
{
  public:
    DistributedSystems();
    virtual ~DistributedSystems();
    const std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> &getAreas();
    const std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> &getRooms();
    const std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> &getDoors();
    void print();

  private:
    std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> areas;
    std::unordered_set<std::shared_ptr<Room>, RoomHash ,RoomComperator> rooms;
    std::unordered_set<std::shared_ptr<Door>, DoorHash ,DoorComperator> doors;
    supplementary::SystemConfig *sc;
    void readTopologyFromConfig();
};

} /* namespace wm */
} /* namespace ttb */
