#pragma once

#include <memory>
#include <map>
#include <set>
#include <vector>

namespace ttb
{
namespace wm
{

class Room;
class Area;
class DistributedSystems;
class TopologicalPathPlanner
{
  public:
    TopologicalPathPlanner(DistributedSystems* ds);
    virtual ~TopologicalPathPlanner();
    /*
     * Returns a vector of Areas
     * First Area contains start room
     * Last Area contains goal room
     */
    std::vector<std::shared_ptr<Area>> plan(std::shared_ptr<Room> start, std::shared_ptr<Room> goal);
    /*
     * Returns a vector of Rooms
     * First Room is start room of path
     * Last Room is the room connected by one of the AreaDoors of the goal Area
     */
    std::vector<std::shared_ptr<Room>> planInsideArea(std::shared_ptr<Room> start, std::shared_ptr<Area> goal);

  private:
    DistributedSystems* ds;
    void areaBreadthSearch(std::set<std::shared_ptr<Area>> &fringe, std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> &visited, std::shared_ptr<Area> goal);
};

} /* namespace wm */
} /* namespace ttb */

