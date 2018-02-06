#include "TopologicalModel.h"

#include "TTBWorldModel.h"
#include "topology/Area.h"
#include "topology/Room.h"

#include <SystemConfig.h>

#include <sstream>

namespace ttb
{
namespace wm
{
TopologicalModel::TopologicalModel(TTBWorldModel *wm)
    : wm(wm)
{
    this->sc = supplementary::SystemConfig::getInstance();
    this->readTopologyFromConfig();
}

TopologicalModel::~TopologicalModel()
{
}

void TopologicalModel::readTopologyFromConfig()
{
    // Read rooms with its connected areas and pois from config
    auto roomNames = (*sc)["TopologicalModel"]->getSections("DistributedSystems.Rooms", NULL);
    for (auto &roomName : *roomNames)
    {
        auto room = this->getRoom(roomName);
        if (!room->area)
        {
            room->area = getArea((*sc)["TopologicalModel"]->get<std::string>("DistributedSystems.Rooms",
                                                                             roomName.c_str(), "area", NULL));
        }
        if (room->pois.size() == 0)
        {
            shared_ptr<vector<string>> poisIDStrings = make_shared<vector<string>>();
            try
            {
                poisIDStrings =
                    (*sc)["TopologicalModel"]->getSections("DistributedSystems.Rooms", roomName.c_str(), "POIs", NULL);
            }
            catch (exception &e)
            {
                continue;
            }
            for (auto poiIDString : *poisIDStrings)
            {
                auto poi = getPOI(std::stoi(poiIDString));
                poi->x = (*sc)["TopologicalModel"]->get<double>("DistributedSystems.Rooms", roomName.c_str(), "POIs",
                                                                poiIDString.c_str(), "X", NULL);
                poi->y = (*sc)["TopologicalModel"]->get<double>("DistributedSystems.Rooms", roomName.c_str(), "POIs",
                                                                poiIDString.c_str(), "Y", NULL);
                poi->room = room;
                room->pois.insert(poi);
            }
        }
    }
    // Read doors with its connected rooms and pois from config
    auto doorNames = (*sc)["TopologicalModel"]->getSections("DistributedSystems.Doors", NULL);
    for (auto &doorName : *doorNames)
    {
        auto door = this->getDoor(doorName);
        if (!door->initialized)
        {
            auto fromRoomName =
                (*sc)["TopologicalModel"]->get<std::string>("DistributedSystems.Doors", doorName.c_str(), "from", NULL);
            auto toRoomName =
                (*sc)["TopologicalModel"]->get<std::string>("DistributedSystems.Doors", doorName.c_str(), "to", NULL);
            auto fromRoom = this->getRoom(fromRoomName);
            auto toRoom = this->getRoom(toRoomName);
            door->fromRoom = fromRoom;
            door->toRoom = toRoom;
            fromRoom->doors.insert(door);
            toRoom->doors.insert(door);
            if ((*sc)["TopologicalModel"]->tryGet<bool>(false, "DistributedSystems.Doors", doorName.c_str(), "areaDoor",
                                                        NULL))
            {
            	auto fromArea = door->fromRoom->area;
            	auto toArea = door->toRoom->area;
                door->fromArea = fromArea;
                door->toArea = toArea;
                fromArea->doors.insert(door);
                toArea->doors.insert(door);
            }
            door->fromPOI = getPOI(
                (*sc)["TopologicalModel"]->get<int>("DistributedSystems.Doors", doorName.c_str(), "fromPOI", NULL));
            door->toPOI = getPOI(
                (*sc)["TopologicalModel"]->get<int>("DistributedSystems.Doors", doorName.c_str(), "toPOI", NULL));
            door->initialized = true;
        }
    }
}

std::shared_ptr<POI> TopologicalModel::getPOI(int id)
{
    auto entry = this->pois.insert(std::make_shared<POI>(id));
    if (entry.second)
    {
        (*(entry.first))->gazeboModel = std::make_shared<LogicalObject>("poi_" + id, "poi");
        wm->logicalCameraData.addLogicalObject("poi_" + id, (*(entry.first))->gazeboModel);
    }
    return *(entry.first);
}

std::shared_ptr<Door> TopologicalModel::getDoor(std::string name)
{
    auto entry = this->doors.insert(std::make_shared<Door>(name));
    if (entry.second)
    {
    	(*(entry.first))->gazeboModel = std::make_shared<LogicalObject>(name, "door");
        wm->logicalCameraData.addLogicalObject(name, (*(entry.first))->gazeboModel);
    }
    return *(entry.first);
}

std::shared_ptr<Area> TopologicalModel::getArea(std::string name)
{
    auto entry = this->areas.insert(std::make_shared<Area>(name));
    return *(entry.first);
}

std::shared_ptr<Room> TopologicalModel::getRoom(std::string name)
{
    auto entry = this->rooms.insert(std::make_shared<Room>(name));
    return *(entry.first);
}

const std::unordered_set<std::shared_ptr<POI>, POIHash, POIComperator> TopologicalModel::getPOIs()
{
	return this->pois;
}

std::string TopologicalModel::toString()
{
    std::stringstream ss;
    ss << "Areas: " << std::endl;
    for (auto area : this->areas)
    {
        ss << area->toString();
    }
    ss << "Rooms: " << std::endl;
    for (auto room : this->rooms)
    {
        ss << room->toString();
    }
    ss << "Doors: " << std::endl;
    for (auto door : this->doors)
    {
        ss << "\t" << door->toString();
    }
    return ss.str();
}
} /* namespace wm */
} /* namespace ttb */
