#pragma once

#include <memory>
#include <map>
#include <vector>

#define TP_DEBUG

namespace ttb
{
namespace wm
{

class Door;
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
     * Returns a vector of Doors
     * First Door is start of path
     * Last Door is connected to the goal Area
     */
    std::vector<std::shared_ptr<Door>> planInsideArea(std::shared_ptr<Room> start, std::shared_ptr<Area> goal);

  private:
    DistributedSystems* ds;
#ifdef TP_DEBUG
    int tmp = 0;
#endif
    bool areaBreadthSearch(std::vector<std::shared_ptr<Area>> &fringe, std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> &visited, std::shared_ptr<Area> goal);
    std::shared_ptr<Room>  roomBreadthSearch(std::vector<std::shared_ptr<Room>> &fringe, std::map<std::shared_ptr<Room>, std::shared_ptr<Room>> &visited, std::shared_ptr<Area> goal);
};

} /* namespace wm */
} /* namespace ttb */

