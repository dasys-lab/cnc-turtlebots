#include "Robot.h"

#include "topology/POI.h"
#include "TTBWorldModel.h"

#include <SystemConfig.h>

namespace ttb
{
namespace wm
{

Robot::Robot(TTBWorldModel *wm)
    : wm(wm)
{
	this->catchRadius = (*this->wm->getSystemConfig())["TTBRobot"]->get<double>("Movement.catchRadius", NULL);
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
    double sqrDistance = (goalPOI->x - ownPos->x) * (goalPOI->x - ownPos->x) +
                         (goalPOI->y - ownPos->y) * (goalPOI->y - ownPos->y);

    std::cout << "Robot: isCloseTo: SqrDistance is " << sqrt(sqrDistance) << std::endl;
    return sqrt(sqrDistance) < this->catchRadius;
}

} /* namespace wm */
} /* namespace ttb */
