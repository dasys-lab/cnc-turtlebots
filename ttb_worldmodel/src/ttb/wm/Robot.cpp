#include "ttb/wm/Robot.h"

#include "ttb/TTBWorldModel.h"
#include "ttb/wm/topology/POI.h"

#include <SystemConfig.h>

namespace ttb
{
namespace wm
{

Robot::Robot(TTBWorldModel *wm)
    : wm(wm)
{
    this->catchRadius = (*this->wm->getSystemConfig())["TTBWorldModel"]->get<double>("Processing.Positioning.catchRadius", NULL);
}

Robot::~Robot()
{
}

bool Robot::isCloseTo(std::shared_ptr<POI> goalPOI)
{
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValidContent();
    if (!ownPos)
    {
        return false;
    }
    if (!goalPOI)
    {
        return false;
    }
    double dist = sqrt((goalPOI->x - ownPos->x) * (goalPOI->x - ownPos->x) + (goalPOI->y - ownPos->y) * (goalPOI->y - ownPos->y));

    return dist < this->catchRadius;
}

bool Robot::inSameRoom(std::shared_ptr<POI> goalPOI)
{
    auto ownRoom = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (!ownRoom)
    {
        return false;
    }
    if (!goalPOI)
    {
        return false;
    }

    return goalPOI->room == ownRoom;
}

bool Robot::isCloseTo(nonstd::optional<geometry_msgs::Pose2D> position, double range)
{
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValidContent();
    if (!ownPos)
    {
        return false;
    }
    if (!position)
    {
        return false;
    }
    double dist = sqrt((position->x - ownPos->x) * (position->x - ownPos->x) + (position->y - ownPos->y) * (position->y - ownPos->y));

    if (range < 0)
    {
        return dist < this->catchRadius;
    }
    else
    {
    	return dist < range;
    }
}

} /* namespace wm */
} /* namespace ttb */
