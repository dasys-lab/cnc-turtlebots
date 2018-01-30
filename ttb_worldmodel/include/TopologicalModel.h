#pragma once

#include "topology/Area.h"
#include "topology/Door.h"
#include "topology/Room.h"
#include "topology/POI.h"

#include <memory>
#include <unordered_set>

//#define DS_TEST

namespace supplementary
{
class SystemConfig;
}
namespace ttb
{
namespace wm
{

class TopologicalModel
{
  public:
    TopologicalModel();
    virtual ~TopologicalModel();
    const std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> &getAreas();
    const std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> &getRooms();
    const std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> &getDoors();

    std::shared_ptr<POI> getPOI(int id);
    std::shared_ptr<Door> getDoor(std::string name);
    std::shared_ptr<Area> getArea(std::string name);
    std::shared_ptr<Room> getRoom(std::string name);
    std::shared_ptr<POI> getPOIByName(std::string name);
    std::shared_ptr<POI> getPOIByID(int id);
    std::shared_ptr<POI> getPOIByUnaryASPPredicate(std::string aspPredicate);

    void print();

  private:
    std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> areas;
    std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> rooms;
    std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> doors;
    std::unordered_set<std::shared_ptr<POI>> pois;

    supplementary::SystemConfig *sc;
    void readPOIsFromConfig();
    void readTopologyFromConfig();
};

} /* namespace wm */
} /* namespace ttb */
