#include "TopologicalPathPlanner.h"

#include <TopologicalModel.h>
#include <topology/Area.h>
#include <topology/TopologicalDoor.h>
#include <topology/Door.h>
#include <topology/Room.h>

#include <algorithm>
#include <iostream>

namespace ttb
{
namespace robot
{
namespace pathPlanning
{
TopologicalPathPlanner::TopologicalPathPlanner(wm::TopologicalModel *ds)
    : topologicalModel(ds)
{
}

TopologicalPathPlanner::~TopologicalPathPlanner()
{
}

std::vector<std::shared_ptr<::ttb::wm::Area>> TopologicalPathPlanner::plan(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal)
{
    std::vector<std::shared_ptr<ttb::wm::Area>> fringe;
    fringe.push_back(start->area);
    std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>> visited;
    bool pathFound = areaBreadthSearch(fringe, visited, goal->area);
    std::vector<std::shared_ptr<ttb::wm::Area>> ret;
    if (pathFound)
    {
        auto area = goal->area;
        while (area != nullptr)
        {
            ret.insert(ret.begin(), area);
            area = visited.at(area);
        }
    }
    else
    {
    	std::cout << "TopologicalPathPlanner: no path found!" << std::endl;
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

bool TopologicalPathPlanner::areaBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Area>> &fringe,
                                               std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>> &visited,
                                               std::shared_ptr<ttb::wm::Area> goal)
{
	std::cout << "fringe size: " << fringe.size() << std::endl;
    if (fringe.size() == 0)
    {
    	std::cout << "areaBreadthSearch returning false" << std::endl;
        return false;
    }
    std::vector<std::shared_ptr<ttb::wm::Area>> newFringe;
    if (visited.size() == 0)
    {
        visited.emplace(fringe.at(0), nullptr);
        std::cout << "visited size: " << visited.size() << std::endl;
    }
    for (auto currentArea : fringe)
    {
    	std::cout << "TPplanner: current areaa doors: " << currentArea->doors.size() << std::endl;
        for (auto areaDoor : currentArea->doors)
        {
            auto nextArea = areaDoor->topologicalDoor->toArea != currentArea ? areaDoor->topologicalDoor->toArea : areaDoor->topologicalDoor->fromArea;

            if (nextArea->blocked || visited.find(nextArea) != visited.end())
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

std::vector<std::shared_ptr<ttb::wm::Door>> TopologicalPathPlanner::planInsideArea(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Area> goal)
{
    std::vector<std::shared_ptr<ttb::wm::Room>> fringe;
    fringe.push_back(start);
    std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>> visited;
    auto goalRoom = roomBreadthSearch(fringe, visited, goal);
    std::vector<std::shared_ptr<ttb::wm::Door>> ret;
    if (goalRoom)
    {
        auto room = goalRoom;
        while (visited.at(room) != nullptr)
        {
            for (auto nextDoor : room->doors)
            {
                auto nextRoom = nextDoor->topologicalDoor->toRoom != room ? nextDoor->topologicalDoor->toRoom : nextDoor->topologicalDoor->fromRoom;

                if (nextRoom == visited.at(room))
                {
                    ret.insert(ret.begin(), nextDoor);
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
        std::cout << " " << door->topologicalDoor->toString() << std::endl;
    }
#endif
    return ret;
}

std::shared_ptr<ttb::wm::Room> TopologicalPathPlanner::roomBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Room>> &fringe,
                                                                         std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>> &visited,
                                                                         std::shared_ptr<ttb::wm::Area> goal)
{
    if (fringe.size() == 0)
    {
        return nullptr;
    }
    std::vector<std::shared_ptr<ttb::wm::Room>> newFringe;
    if (visited.size() == 0)
    {
        visited.emplace(fringe.at(0), nullptr);
    }
    for (auto currentRoom : fringe)
    {
        for (auto door : currentRoom->doors)
        {
            auto nextRoom = door->topologicalDoor->toRoom != currentRoom ? door->topologicalDoor->toRoom : door->topologicalDoor->fromRoom;

            if (!door->open || visited.find(nextRoom) != visited.end())
            {
                continue;
            }

            newFringe.push_back(nextRoom);
            visited.emplace(nextRoom, currentRoom);
            if (nextRoom->area->name == goal->name)
            {
                return nextRoom;
            }
        }
    }
    return roomBreadthSearch(newFringe, visited, goal);
}
}
} /* namespace wm */
} /* namespace ttb */
