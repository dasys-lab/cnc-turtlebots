#include "distributed_systems/DistributedSystems.h"

#include "distributed_systems/AreaDoor.h"
#include "distributed_systems/TopologicalPathPlanner.h"

#include <Configuration.h>
#include <SystemConfig.h>
#include <sstream>

namespace ttb
{
namespace wm
{
namespace pathPlanning
{
DistributedSystems::DistributedSystems()
{
    this->sc = supplementary::SystemConfig::getInstance();
    this->readTopologyFromConfig();
    this->tpPathPlanner = new TopologicalPathPlanner(this);
#ifdef DSDEBUG
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

DistributedSystems::~DistributedSystems()
{
    delete this->tpPathPlanner;
}

const std::unordered_set<std::shared_ptr<Area>, AreaHash, AreaComperator> &DistributedSystems::getAreas()
{
    return this->areas;
}

const std::unordered_set<std::shared_ptr<Room>, RoomHash, RoomComperator> &DistributedSystems::getRooms()
{
    return this->rooms;
}

const std::unordered_set<std::shared_ptr<Door>, DoorHash, DoorComperator> &DistributedSystems::getDoors()
{
    return this->doors;
}

void DistributedSystems::readTopologyFromConfig()
{
    std::shared_ptr<std::vector<std::string>> areaNames = (*sc)["DistributedSystems"]->getNames("DistributedSystems", "Areas", NULL);
    // Create Areas
    for (auto config : *(areaNames))
    {
        this->areas.insert(std::make_shared<Area>((*sc)["DistributedSystems"]->get<std::string>("DistributedSystems", "Areas", config.c_str(), NULL)));
    }
    // Create Rooms
    std::shared_ptr<std::vector<std::string>> roomNames = (*sc)["DistributedSystems"]->getNames("DistributedSystems", "Rooms", NULL);
    for (auto config : *(roomNames))
    {
        this->rooms.insert(std::make_shared<Room>(config, *this->areas.find(std::make_shared<Area>((*sc)["DistributedSystems"]->get<std::string>(
                                                              "DistributedSystems", "Rooms", config.c_str(), NULL)))));
    }
    // Create Doors connecting rooms within an area
    std::shared_ptr<std::vector<std::string>> doorSections = (*sc)["DistributedSystems"]->getSections("DistributedSystems", "Doors", NULL);
    for (auto section : *(doorSections))
    {
        std::shared_ptr<Room> from = *(this->rooms.find(std::make_shared<Room>(section, nullptr)));
        std::shared_ptr<std::vector<std::string>> doorNames = (*sc)["DistributedSystems"]->getNames("DistributedSystems", "Doors", section.c_str(), NULL);
        for (auto name : *(doorNames))
        {
            std::shared_ptr<Room> to = *(this->rooms.find(std::make_shared<Room>(
                (*sc)["DistributedSystems"]->get<std::string>("DistributedSystems", "Doors", section.c_str(), name.c_str(), NULL), nullptr)));
            std::shared_ptr<Door> door = std::make_shared<Door>(from, to, name);
            from->doors.insert(door);
            to->doors.insert(door);
            this->doors.insert(door);
        }
    }
    // Create Doors connecting rooms from different areas
    std::shared_ptr<std::vector<std::string>> areaDoorSections = (*sc)["DistributedSystems"]->getSections("DistributedSystems", "AreaDoors", NULL);
    for (auto section : *(areaDoorSections))
    {
        std::shared_ptr<Room> from = *(this->rooms.find(std::make_shared<Room>(section, nullptr)));
        std::shared_ptr<std::vector<std::string>> areaDoorNames =
            (*sc)["DistributedSystems"]->getNames("DistributedSystems", "AreaDoors", section.c_str(), NULL);
        for (auto name : *(areaDoorNames))
        {
            std::shared_ptr<Room> to = *(this->rooms.find(std::make_shared<Room>(
                (*sc)["DistributedSystems"]->get<std::string>("DistributedSystems", "AreaDoors", section.c_str(), name.c_str(), NULL), nullptr)));
            std::shared_ptr<AreaDoor> door = std::make_shared<AreaDoor>(from, to, name);
            from->doors.insert(door);
            to->doors.insert(door);
            this->doors.insert(door);
            door->fromArea->doors.insert(door);
            door->toArea->doors.insert(door);
        }
    }
}

void DistributedSystems::print()
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
}
} /* namespace wm */
} /* namespace ttb */
