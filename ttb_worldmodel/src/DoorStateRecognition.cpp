#include "DoorStateRecognition.h"

#include "TTBWorldModel.h"
#include <cnc_geometry/Calculator.h>

namespace ttb
{
namespace wm
{

DoorStateRecognition::DoorStateRecognition(ttb::TTBWorldModel *wm)
    : Worker("DoorStateRecognition")
    , wm(wm)
{
    supplementary::SystemConfig *sc = supplementary::SystemConfig::getInstance();
    this->ownPoseValidityDuration = (*sc)["TTBWorldModel"]->get<int>("Data.AMCLPose.ValidityDuration", NULL);
}

DoorStateRecognition::~DoorStateRecognition()
{
}

void DoorStateRecognition::run()
{
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValid();
    if (!ownPos)
    {
        return;
    }

    auto doors = this->wm->topologicalModel.getDoors();
    for (auto door : doors)
    {
        auto doorPose = door->gazeboModel->getPoseBuffer()->getTemporalCloseTo(ownPos->getCreationTime(), ownPoseValidityDuration);
        if (!doorPose)
        {
            continue;
        }
        double scanDist = this->getScanDistance(ownPos, doorPose->getInformation());
        if (scanDist > geometry::distance(ownPos->getInformation().x, ownPos->getInformation().y, doorPose->getInformation().x, doorPose->getInformation().y))
        {
            door->open = true;
        }
        else
        {
            door->open = false;
        }
    }
}

double DoorStateRecognition::getScanDistance(std::shared_ptr<const supplementary::InformationElement<geometry::CNPositionAllo>> alloOwnPos,
                                             geometry_msgs::Pose2D objectPose)
{
    auto scan = this->wm->rawSensorData.getLaserScanBuffer()->getTemporalCloseTo(alloOwnPos->getCreationTime(), ownPoseValidityDuration);

    int idx = 0;

    //alloOwnPos->getInformation().theta

    //objectPose.theta



    return scan->getInformation()->ranges[idx];
}

} /* namespace wm */
} /* namespace ttb */
