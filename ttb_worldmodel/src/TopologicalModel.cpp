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

    //Test Areas
    auto testArea = *this->areas.find(std::make_shared<Area>("utility"));
    testArea->blocked = true;
    this->tpPathPlanner->plan(*this->rooms.find(std::make_shared<Room>("r1406C")), *this->rooms.find(std::make_shared<Room>("r1403")));
    testArea->blocked = false;
    testArea = *this->areas.find(std::make_shared<Area>("mainHall"));
    testArea->blocked = true;
    this->tpPathPlanner->plan(*this->rooms.find(std::make_shared<Room>("r1406C")), *this->rooms.find(std::make_shared<Room>("r1403")));
    //Test Doors
    this->tpPathPlanner->planInsideArea(*this->rooms.find(std::make_shared<Room>("r1411")), *this->areas.find(std::make_shared<Area>("mainHall")));
    auto testDoor = *this->doors.find(std::make_shared<Door>(*this->rooms.find(std::make_shared<Room>("r1411C")),
    		*this->rooms.find(std::make_shared<Room>("r1411")), "door1"));
    testDoor->open = false;
    this->tpPathPlanner->planInsideArea(*this->rooms.find(std::make_shared<Room>("r1411")), *this->areas.find(std::make_shared<Area>("mainHall")));
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
    std::shared_ptr<std::vector<std::string>> areaNames = (*sc)["TopologicalModel"]->getNames("TopologicalModel", "Areas", NULL);
    // Create Areas
    for (auto config : *(areaNames))
    {
        this->areas.insert(std::make_shared<Area>((*sc)["TopologicalModel"]->get<std::string>("TopologicalModel", "Areas", config.c_str(), NULL)));
    }
    // Create Rooms
    std::shared_ptr<std::vector<std::string>> roomNames = (*sc)["TopologicalModel"]->getNames("TopologicalModel", "Rooms", NULL);
    for (auto config : *(roomNames))
    {
        this->rooms.insert(std::make_shared<Room>(config, *this->areas.find(std::make_shared<Area>((*sc)["TopologicalModel"]->get<std::string>(
                                                              "TopologicalModel", "Rooms", config.c_str(), NULL)))));
    }
    // Create Doors connecting rooms within an area
    std::shared_ptr<std::vector<std::string>> doorSections = (*sc)["TopologicalModel"]->getSections("TopologicalModel", "Doors", NULL);
    for (auto section : *(doorSections))
    {
        std::shared_ptr<Room> from = *(this->rooms.find(std::make_shared<Room>(section, nullptr)));
        std::shared_ptr<std::vector<std::string>> doorNames = (*sc)["TopologicalModel"]->getNames("TopologicalModel", "Doors", section.c_str(), NULL);
        for (auto name : *(doorNames))
        {
            std::shared_ptr<Room> to = *(this->rooms.find(std::make_shared<Room>(
                (*sc)["TopologicalModel"]->get<std::string>("TopologicalModel", "Doors", section.c_str(), name.c_str(), NULL), nullptr)));
            std::shared_ptr<Door> door = std::make_shared<Door>(from, to, name);
            from->doors.insert(door);
            to->doors.insert(door);
            this->doors.insert(door);
        }
    }
    // Create Doors connecting rooms from different areas
    std::shared_ptr<std::vector<std::string>> areaDoorSections = (*sc)["TopologicalModel"]->getSections("TopologicalModel", "AreaDoors", NULL);
    for (auto section : *(areaDoorSections))
    {
        std::shared_ptr<Room> from = *(this->rooms.find(std::make_shared<Room>(section, nullptr)));
        std::shared_ptr<std::vector<std::string>> areaDoorNames =
            (*sc)["TopologicalModel"]->getNames("TopologicalModel", "AreaDoors", section.c_str(), NULL);
        for (auto name : *(areaDoorNames))
        {
            std::shared_ptr<Room> to = *(this->rooms.find(std::make_shared<Room>(
                (*sc)["TopologicalModel"]->get<std::string>("TopologicalModel", "AreaDoors", section.c_str(), name.c_str(), NULL), nullptr)));
            std::shared_ptr<TopologicalDoor> door = std::make_shared<TopologicalDoor>(from, to, name);
            from->doors.insert(door);
            to->doors.insert(door);
            this->doors.insert(door);
            door->fromArea->doors.insert(door);
            door->toArea->doors.insert(door);
        }
    }
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

const std::unordered_set<std::shared_ptr<Door>, TopologicalDoorHash, TopologicalDoorComperator> &TopologicalModel::getDoors()
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
