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

bool TopologicalPathPlanner::planAreaPath(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal,
                                          std::vector<std::shared_ptr<::ttb::wm::Area>> &areaList)
{
    if (start->area->name.compare(goal->area->name) == 0)
    {
        //std::cout << "TopologicalPathPlanner: start and goal room are in the same area!" << std::endl;
        return true;
    }
    std::vector<std::shared_ptr<ttb::wm::Area>> fringe;
    fringe.push_back(start->area);
    std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>> visited;
    bool pathFound = areaBreadthSearch(fringe, visited, goal->area);
    if (pathFound)
    {
        auto area = goal->area;
        while (area != start->area)
        {
            areaList.insert(areaList.begin(), area);
            area = visited.at(area);
        }
    }
    else
    {
        //std::cout << "TopologicalPathPlanner: no path between areas found!" << std::endl;
        return false;
    }

#ifdef TP_DEBUG
    std::cout << "Path: " << std::endl;
    for (auto area : areaList)
    {
        std::cout << " " << area->name << " ";
    }
    std::cout << std::endl;
#endif
    return true;
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

bool TopologicalPathPlanner::planDoorPath(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal,
                                                                                 std::vector<std::shared_ptr<::ttb::wm::Door>> &doorList)
{
	if(start->name.compare(goal->name) == 0)
	{
        //std::cout << "TopologicalPathPlanner: start and goal room are identical!" << std::endl;
        return true;
	}
    std::vector<std::shared_ptr<ttb::wm::Room>> fringe;
    fringe.push_back(start);
    std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>> visited;
    auto goalRoom = roomBreadthSearch(fringe, visited, goal);
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
                	doorList.insert(doorList.begin(), nextDoor);
                    room = nextRoom;
                    break;
                }
            }
        }
    }
    else
    {
    	return false;
    }

#ifdef TP_DEBUG
    std::cout << "Path: " << std::endl;
    for (auto door : doorList)
    {
        std::cout << " " << door->toString() << std::endl;
    }
#endif
    return true;
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

// std::vector<std::shared_ptr<ttb::wm::Door>> TopologicalPathPlanner::planToNextArea(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Area> goal)
//{
//	std::shared_ptr<ttb::wm::Door> doorToNextArea = nullptr;
//	std::shared_ptr<ttb::wm::Room> goalRoom = nullptr;
//    for (auto door : goal->doors)
//    {
//        if (start->area == door->fromArea)
//        {
//        	goalRoom = door->fromRoom;
//        	doorToNextArea = door;
//        	break;
//        }
//        else if (start->area == door->toArea)
//        {
//        	goalRoom = door->toRoom;
//        	doorToNextArea = door;
//        	break;
//        }
//    }
//    std::vector<std::shared_ptr<ttb::wm::Door>> result = planBetweenRooms(start, goalRoom);
//    result.push_back(doorToNextArea);
//    return result;
//}
}
} /* namespace wm */
} /* namespace ttb */
