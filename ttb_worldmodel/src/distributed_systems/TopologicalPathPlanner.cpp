#include "distributed_systems/TopologicalPathPlanner.h"

#include "distributed_systems/Area.h"
#include "distributed_systems/AreaDoor.h"
#include "distributed_systems/DistributedSystems.h"
#include "distributed_systems/Door.h"
#include "distributed_systems/Room.h"

#include <algorithm>
#include <iostream>

namespace ttb
{
namespace wm
{

TopologicalPathPlanner::TopologicalPathPlanner(DistributedSystems *ds)
    : ds(ds)
{
}

TopologicalPathPlanner::~TopologicalPathPlanner()
{
}

std::vector<std::shared_ptr<Area>> TopologicalPathPlanner::plan(std::shared_ptr<Room> start, std::shared_ptr<Room> goal)
{
    std::vector<std::shared_ptr<Area>> fringe;
    fringe.push_back(start->area);
    std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> visited;
    bool pathFound = areaBreadthSearch(fringe, visited, goal->area);
    std::vector<std::shared_ptr<Area>> ret;
    if (pathFound)
    {
        auto area = goal->area;
        while (area != nullptr)
        {
            ret.insert(ret.begin(), area);
            area = visited.at(area);
        }
    }

#ifdef TP_DEBUG
    std::cout << "Path: " << std::endl;
    for (auto area : ret)
    {
        std::cout << " " << area->name << std::endl;
    }
#endif
    return ret;
}

bool TopologicalPathPlanner::areaBreadthSearch(std::vector<std::shared_ptr<Area>> &fringe, std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> &visited,
                                               std::shared_ptr<Area> goal)
{
    if (fringe.size() == 0)
    {
        return false;
    }
    std::vector<std::shared_ptr<Area>> newFringe;
    if (visited.size() == 0)
    {
        visited.emplace(fringe.at(0), nullptr);
    }
    for (auto currentArea : fringe)
    {
        for (auto areaDoor : currentArea->doors)
        {
            auto nextArea = areaDoor->toArea != currentArea ? areaDoor->toArea : areaDoor->fromArea;

            if (visited.find(nextArea) != visited.end())
            {
                continue;
            }

            newFringe.push_back(nextArea);
            visited.emplace(nextArea, currentArea);
            if (nextArea->name == goal->name)
            {
                return true;
            }
        }
    }
    return areaBreadthSearch(newFringe, visited, goal);
}

std::vector<std::shared_ptr<Door>> TopologicalPathPlanner::planInsideArea(std::shared_ptr<Room> start, std::shared_ptr<Area> goal)
{
    std::vector<std::shared_ptr<Room>> fringe;
    fringe.push_back(start);
    std::map<std::shared_ptr<Room>, std::shared_ptr<Room>> visited;
    auto goalRoom = roomBreadthSearch(fringe, visited, goal);
    std::vector<std::shared_ptr<Door>> ret;
    if (goalRoom)
    {
        auto room = goalRoom;
        while (visited.at(room) != nullptr)
        {
        	for (auto nextDoor : room->doors)
        	{
        		auto nextRoom = nextDoor->to != room ? nextDoor->to : nextDoor->from;

        		if (nextRoom == visited.at(room))
        		{
        			ret.insert(ret.begin(),nextDoor);
        			room = nextRoom;
        			break;
        		}
        	}
        }
    }

#ifdef TP_DEBUG
    std::cout << "Path: " << std::endl;
    for (auto door : ret)
    {
        std::cout << " " << door->toString() << std::endl;
    }
#endif
    return ret;
}

std::shared_ptr<Room> TopologicalPathPlanner::roomBreadthSearch(std::vector<std::shared_ptr<Room>> &fringe, std::map<std::shared_ptr<Room>, std::shared_ptr<Room>> &visited,
                                               std::shared_ptr<Area> goal)
{
#ifdef TP_DEBUG
    std::cout << "Level: " << tmp << std::endl;
    tmp++;
#endif
    if (fringe.size() == 0)
    {
#ifdef TP_DEBUG
        std::cout << "Fringe empty returning false" << std::endl;
#endif
        return nullptr;
    }
    std::vector<std::shared_ptr<Room>> newFringe;
    if (visited.size() == 0)
    {
#ifdef TP_DEBUG
        std::cout << "First iteration adding start area: " << fringe.at(0)->name << std::endl;
#endif
        visited.emplace(fringe.at(0), nullptr);
    }
    for (auto currentRoom : fringe)
    {
#ifdef TP_DEBUG
        std::cout << "Inside fringe: adding doors for area: " << currentRoom->name << std::endl;
#endif
        for (auto door : currentRoom->doors)
        {
            auto nextRoom = door->to != currentRoom ? door->to : door->from;

            if (visited.find(nextRoom) != visited.end())
            {
#ifdef TP_DEBUG
                std::cout << "Inside expand: already visited area: " << nextRoom->name << std::endl;
#endif
                continue;
            }

            newFringe.push_back(nextRoom);
#ifdef TP_DEBUG
            std::cout << "Inside expand: adding area: " << nextRoom->name << " to new fringe" << std::endl;
#endif
            visited.emplace(nextRoom, currentRoom);
#ifdef TP_DEBUG
            std::cout << "Inside expand: adding pair: " << nextRoom->name << " " << currentRoom->name << " to visited" << std::endl;
#endif
            if (nextRoom->area->name == goal->name)
            {
#ifdef TP_DEBUG
                std::cout << "Goal found returning true" << std::endl;
#endif
                return nextRoom;
            }
        }
    }
    return roomBreadthSearch(newFringe, visited, goal);
}

} /* namespace wm */
} /* namespace ttb */
