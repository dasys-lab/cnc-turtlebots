#include "distributed_systems/TopologicalPathPlanner.h"

#include "distributed_systems/Area.h"
#include "distributed_systems/AreaDoor.h"
#include "distributed_systems/DistributedSystems.h"
#include "distributed_systems/Door.h"
#include "distributed_systems/Room.h"

namespace ttb
{
namespace wm
{

TopologicalPathPlanner::TopologicalPathPlanner(DistributedSystems* ds)
	: ds(ds)
{
}

TopologicalPathPlanner::~TopologicalPathPlanner()
{
}

//BFS(start_node, goal_node) {
//  return BFS'({start_node}, ∅, goal_node);
//}
//BFS'(fringe, visited, goal_node) {
//  if(fringe == ∅) {
//    // Knoten nicht gefunden
//    return false;
//  }
//  if (goal_node ∈ fringe) {
//    return true;
//  }
//  return BFS'({child | x ∈ fringe, child ∈ expand(x)} \ visited, visited ∪ fringe, goal_node);
//}

std::vector<std::shared_ptr<Area>> TopologicalPathPlanner::plan(std::shared_ptr<Room> start, std::shared_ptr<Room> goal)
{

	std::set<std::shared_ptr<Area>> fringe;
	fringe.insert(start->area);
	std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> visited;
	areaBreadthSearch(fringe, visited, goal->area);

	std::vector<std::shared_ptr<Area>> ret;
	return ret;
}

std::vector<std::shared_ptr<Room>> TopologicalPathPlanner::planInsideArea(std::shared_ptr<Room> start, std::shared_ptr<Area> goal)
{
}

void TopologicalPathPlanner::areaBreadthSearch(std::set<std::shared_ptr<Area>> &fringe, std::map<std::shared_ptr<Area>, std::shared_ptr<Area>> &visited,
                                               std::shared_ptr<Area> goal)
{
}

} /* namespace wm */
} /* namespace ttb */
