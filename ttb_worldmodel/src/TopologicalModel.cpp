#include "TopologicalModel.h"

#include "topology/Area.h"
#include "topology/Room.h"
#include "topology/TopologicalDoor.h"

#include <SystemConfig.h>

#include <sstream>

namespace ttb
{
namespace wm
{
TopologicalModel::TopologicalModel()
{
    this->sc = supplementary::SystemConfig::getInstance();
    this->readTopologyFromConfig();
    this->readPOIsFromConfig();
#ifdef DS_TEST
    this->print();

    // Test Areas
    auto testArea = *this->areas.find(std::make_shared<Area>("utility"));
    testArea->blocked = true;
    this->tpPathPlanner->plan(*this->rooms.find(std::make_shared<Room>("r1406C")),
                              *this->rooms.find(std::make_shared<Room>("r1403")));
    testArea->blocked = false;
    testArea = *this->areas.find(std::make_shared<Area>("mainHall"));
    testArea->blocked = true;
    this->tpPathPlanner->plan(*this->rooms.find(std::make_shared<Room>("r1406C")),
                              *this->rooms.find(std::make_shared<Room>("r1403")));
    // Test Doors
    this->tpPathPlanner->planInsideArea(*this->rooms.find(std::make_shared<Room>("r1411")),
                                        *this->areas.find(std::make_shared<Area>("mainHall")));
    auto testDoor =
        *this->doors.find(std::make_shared<Door>(*this->rooms.find(std::make_shared<Room>("r1411C")),
                                                 *this->rooms.find(std::make_shared<Room>("r1411")), "door1"));
    testDoor->open = false;
    this->tpPathPlanner->planInsideArea(*this->rooms.find(std::make_shared<Room>("r1411")),
                                        *this->areas.find(std::make_shared<Area>("mainHall")));
#endif
}

TopologicalModel::~TopologicalModel()
{
}

void TopologicalModel::readPOIsFromConfig()
{
    auto poiSections = (*this->sc)["POI"]->getSections("POI.Points", NULL);
    for (auto &poiSectionName : (*poiSections))
    {
        shared_ptr<POI> currentPOI = make_shared<POI>(
            (*this->sc)["POI"]->get<int>("POI.Points", poiSectionName.c_str(), "ID", NULL), poiSectionName,
            (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "X", NULL),
            (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "Y", NULL));
        this->pois.insert(currentPOI);
    }
}

void TopologicalModel::readTopologyFromConfig()
{
    auto &roomNames = (*sc)["TopologicalModel"]->getSections("DistributedSystems.Rooms", NULL);
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
            auto &poisIDStrings =
                (*sc)["TopologicalModel"]->tryGetSections("DistributedSystems.Rooms", roomName.c_str(), "POIs", NULL);
            if (!poisIDStrings)
            {
            	continue;
            }
            for (auto &poiIDString : *poisIDStrings)
            {
                auto poi = getPOI(std::stoi(poiIDString));
                poi->x = (*sc)["TopologicalModel"]->get<int>("DistributedSystems.Rooms", roomName.c_str(), "POIs", poiIDString.c_str(), "X", NULL);
                poi->y = (*sc)["TopologicalModel"]->get<int>("DistributedSystems.Rooms", roomName.c_str(), "POIs", poiIDString.c_str(), "Y", NULL);
                poi->room = room;
                room->pois.insert(poi);
            }
        }
    }

    auto &doorNames = (*sc)["TopologicalModel"]->getSections("DistributedSystems.Doors", NULL);
    for (auto &doorName : *doorNames)
    {
        auto door = this->getDoor(doorName);
        if (!door->topologicalDoor)
        {
            auto fromRoomName =
                (*sc)["TopologicalModel"]->get<std::string>("DistributedSystems.Doors", doorName, "from", NULL);
            auto toRoomName =
                (*sc)["TopologicalModel"]->get<std::string>("DistributedSystems.Doors", doorName, "to", NULL);
            door->topologicalDoor =
                std::make_shared<TopologicalDoor>(this->getRoom(fromRoomName), this->getRoom(toRoomName));
            if ((*sc)["TopologicalModel"]->tryGet<bool>(false, "DistributedSystems.Doors", doorName, "areaDoor", NULL))
            {
                door->topologicalDoor->fromArea = door->topologicalDoor->fromRoom->area;
                door->topologicalDoor->toArea = door->topologicalDoor->toRoom->area;
            }
        }
    }
}

std::shared_ptr<POI> TopologicalModel::getPOI(int id)
{
    auto entry = this->pois.insert(std::make_shared<POI>(id));
    return *(entry.first);
}

std::shared_ptr<Door> TopologicalModel::getDoor(std::string name)
{
    auto entry = this->doors.insert(std::make_shared<Door>(name));
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

std::shared_ptr<POI> TopologicalModel::getPOIByName(string name)
{
    shared_ptr<POI> ret = nullptr;
    for (auto poi : this->pois)
    {
        if (poi->name.compare(name) == 0)
        {
            ret = poi;
            break;
        }
    }
    return ret;
}

std::shared_ptr<POI> TopologicalModel::getPOIByID(int id)
{
    shared_ptr<POI> ret = nullptr;
    for (auto poi : this->pois)
    {
        if (poi->id == id)
        {
            ret = poi;
            break;
        }
    }
    return ret;
}

std::shared_ptr<POI> TopologicalModel::getPOIByUnaryASPPredicate(string aspPredicate)
{
    size_t start = aspPredicate.find("(");
    size_t end = aspPredicate.find(")", start);
    string name = aspPredicate.substr(start + 1, end - start - 1);

    return this->getPOIByName(name);
}

const std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> &TopologicalModel::getAreas()
{
    return this->areas;
}

const std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> &TopologicalModel::getRooms()
{
    return this->rooms;
}

const std::unordered_set<std::shared_ptr<Door>, TopologicalDoorHash, TopologicalDoorComperator> &
TopologicalModel::getDoors()
{
    return this->doors;
}

void TopologicalModel::print()
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
    ss << "Doors:: " << std::endl;
    for (auto door : this->doors)
    {
        ss << "\t" << door->toString();
    }
    std::cout << ss.str() << std::endl;
    std::cout << ss.str() << std::endl;
}
} /* namespace wm */
} /* namespace ttb */
