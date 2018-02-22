#include "TopologicalPathPlanner.h"

#include <TopologicalModel.h>
#include <topology/Area.h>
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
        while (area != start->area)
        {
            ret.insert(ret.begin(), area);
            area = visited.at(area);
        }
    }
    else
    {
        std::cout << "TopologicalPathPlanner: no path between areas found or room are in the same area!" << std::endl;
    }

#ifdef TP_DEBUG
    std::cout << "Path: " << std::endl;
    for (auto area : ret)
    {
        std::cout << " " << area->name << " ";
    }
    std::cout << std::endl;
#endif
    return ret;
}

bool TopologicalPathPlanner::areaBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Area>> &fringe,
                                               std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>> &visited,
                                               std::shared_ptr<ttb::wm::Area> goal)
{
    if (fringe.size() == 0)
    {
        return false;
    }
    std::vector<std::shared_ptr<ttb::wm::Area>> newFringe;
    if (visited.size() == 0)
    {
        visited.emplace(fringe.at(0), nullptr);
    }
    for (auto currentArea : fringe)
    {
        for (auto areaDoor : currentArea->doors)
        {
            auto nextArea = areaDoor->toArea != currentArea ? areaDoor->toArea : areaDoor->fromArea;

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

std::vector<std::shared_ptr<ttb::wm::Door>> TopologicalPathPlanner::planBetweenRooms(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal)
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
                auto nextRoom = nextDoor->toRoom != room ? nextDoor->toRoom : nextDoor->fromRoom;

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
        std::cout << " " << door->toString() << std::endl;
    }
#endif
    return ret;
}

std::shared_ptr<ttb::wm::Room> TopologicalPathPlanner::roomBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Room>> &fringe,
                                                                         std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>> &visited,
                                                                         std::shared_ptr<ttb::wm::Room> goal)
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
            auto nextRoom = door->toRoom != currentRoom ? door->toRoom : door->fromRoom;

            if (!door->open || visited.find(nextRoom) != visited.end() || nextRoom->area->blocked)
            {
                continue;
            }

            newFringe.push_back(nextRoom);
            visited.emplace(nextRoom, currentRoom);
            if (nextRoom->name == goal->name)
            {
                return nextRoom;
            }
        }
    }
    return roomBreadthSearch(newFringe, visited, goal);
}

std::vector<std::shared_ptr<ttb::wm::Door>> TopologicalPathPlanner::planToNextArea(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Area> goal)
{
	std::shared_ptr<ttb::wm::Door> doorToNextArea = nullptr;
	std::shared_ptr<ttb::wm::Room> goalRoom = nullptr;
    for (auto door : goal->doors)
    {
        if (start->area == door->fromArea)
        {
        	goalRoom = door->fromRoom;
        	doorToNextArea = door;
        	break;
        }
        else if (start->area == door->toArea)
        {
        	goalRoom = door->toRoom;
        	doorToNextArea = door;
        	break;
        }
    }
    std::vector<std::shared_ptr<ttb::wm::Door>> result = planBetweenRooms(start, goalRoom);
    result.push_back(doorToNextArea);
    return result;
}
}
} /* namespace wm */
} /* namespace ttb */
