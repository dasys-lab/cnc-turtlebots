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
	class TTBWorldModel;
namespace wm
{

class TopologicalModel
{
  public:
    TopologicalModel(TTBWorldModel* wm);
    virtual ~TopologicalModel();

    std::shared_ptr<POI> getPOI(int id);
    std::shared_ptr<POI> getPOIByName(std::string name);
    std::shared_ptr<Door> getDoor(std::string name);
    std::shared_ptr<Area> getArea(std::string name);
    std::shared_ptr<Room> getRoom(std::string name);

    const std::unordered_set<std::shared_ptr<POI>, POIHash, POIComperator> getPOIs();
    const std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> getDoors();

    std::string toString();

  private:
    std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> areas;
    std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> rooms;
    std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> doors;
    std::unordered_set<std::shared_ptr<POI>, POIHash, POIComperator> pois;

    supplementary::SystemConfig *sc;
    void readTopologyFromConfig();
    TTBWorldModel* wm;
};

} /* namespace wm */
} /* namespace ttb */
