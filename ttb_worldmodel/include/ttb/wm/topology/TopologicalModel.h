#pragma once

#include "ttb/wm/topology/Area.h"
#include "ttb/wm/topology/Door.h"
#include "ttb/wm/topology/POI.h"
#include "ttb/wm/topology/Room.h"

#include <memory>
#include <unordered_set>

//#define DS_TEST

namespace essentials
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

    std::shared_ptr<POI> getPOIByName(std::string name);
    std::shared_ptr<POI> getPOI(int id, bool insert = false);
    std::shared_ptr<Door> getDoor(std::string name, bool insert = false);
    std::shared_ptr<Area> getArea(std::string name, bool insert = false);
    std::shared_ptr<Room> getRoom(std::string name, bool insert = false);

    const std::unordered_set<std::shared_ptr<POI>, POIHash, POIComperator> getPOIs();
    const std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> getDoors();

    std::string toString();

private:
    std::shared_ptr<Room> getRoomInternal(std::string name);
    std::shared_ptr<Area> getAreaInternal(std::string name);
    std::shared_ptr<Door> getDoorInternal(std::string name);
    std::shared_ptr<POI> getPOIInternal(int id);
    std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> areas;
    std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> rooms;
    std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> doors;
    std::unordered_set<std::shared_ptr<POI>, POIHash, POIComperator> pois;

    essentials::SystemConfig* sc;
    void readTopologyFromConfig();
    TTBWorldModel* wm;
};

} /* namespace wm */
} /* namespace ttb */
