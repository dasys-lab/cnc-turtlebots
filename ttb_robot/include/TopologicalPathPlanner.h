#pragma once

#include <map>
#include <memory>
#include <vector>

//#define TP_DEBUG

namespace ttb
{
namespace wm
{
class Door;
class Room;
class Area;
class TopologicalModel;
} // namespace wm
namespace robot
{

namespace pathPlanning
{

class TopologicalPathPlanner
{
public:
    TopologicalPathPlanner(wm::TopologicalModel* ds);
    virtual ~TopologicalPathPlanner();
    /*
     * Returns a vector of Areas
     * First Area contains start room
     * Last Area contains goal room
     */
    bool planAreaPath(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal, std::vector<std::shared_ptr<::ttb::wm::Area>>& areaList);
    /*
     * Returns a vector of Doors
     * First Door is start of path
     * Last Door is connected to the goal Area
     */
    bool planDoorPath(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Room> goal, std::vector<std::shared_ptr<::ttb::wm::Door>>& doorList);
    /*
     * Returns a vector of Doors
     * First Door is start of path
     * Last Door is connected to the goal room
     */
    //    std::vector<std::shared_ptr<ttb::wm::Door>> planToNextArea(std::shared_ptr<ttb::wm::Room> start, std::shared_ptr<ttb::wm::Area> goal);

private:
    wm::TopologicalModel* topologicalModel;
    bool areaBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Area>>& fringe,
            std::map<std::shared_ptr<ttb::wm::Area>, std::shared_ptr<ttb::wm::Area>>& visited, std::shared_ptr<ttb::wm::Area> goal);
    bool roomBreadthSearch(std::vector<std::shared_ptr<ttb::wm::Room>>& fringe,
            std::map<std::shared_ptr<ttb::wm::Room>, std::shared_ptr<ttb::wm::Room>>& visited, std::shared_ptr<ttb::wm::Room> goal);
};
} // namespace pathPlanning
} // namespace robot
} /* namespace ttb */
