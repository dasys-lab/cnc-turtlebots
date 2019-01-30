#include "ttb/wm/DoorStateRecognition.h"

#include "ttb/TTBWorldModel.h"

#include <cnc_geometry/Calculator.h>

#include <cmath>

namespace ttb
{
namespace wm
{

DoorStateRecognition::DoorStateRecognition(ttb::TTBWorldModel* wm)
        : Worker("DoorStateRecognition")
        , wm(wm)
{
    essentials::SystemConfig* sc = essentials::SystemConfig::getInstance();
    this->ownPoseValidityDuration = alica::AlicaTime::nanoseconds((*sc)["TTBWorldModel"]->get<int64_t>("Data.AMCLPose.ValidityDuration", NULL));
    this->epsilon = (*sc)["TTBWorldModel"]->get<double>("Processing.DoorStateRecognition.Epsilon", NULL);
}

DoorStateRecognition::~DoorStateRecognition() {}

void DoorStateRecognition::run()
{
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValid();
    if (!ownPos) {
        return;
    }

    auto doors = this->wm->topologicalModel.getDoors();
    for (auto door : doors) {
        auto doorPose = door->gazeboModel->getPoseBuffer()->getTemporalCloseTo(ownPos->getCreationTime(), ownPoseValidityDuration);
        if (!doorPose) {
            continue;
        }

        if (this->wm->isUsingSimulator()) {
            door->open = this->isOpen(door, doorPose->getInformation().theta);
        } else {
            double scanDist = this->getScanDistance(ownPos, doorPose->getInformation());
            door->open = scanDist >
                         geometry::distance(ownPos->getInformation().x, ownPos->getInformation().y, doorPose->getInformation().x, doorPose->getInformation().y);
        }
    }
}

bool DoorStateRecognition::isOpen(std::shared_ptr<ttb::wm::Door> door, double z)
{
    return std::abs(door->openAngle - z) < epsilon;
}

double DoorStateRecognition::getScanDistance(
        std::shared_ptr<const supplementary::InformationElement<geometry::CNPositionAllo>> alloOwnPos, geometry_msgs::Pose2D objectPose)
{
    auto scan = this->wm->rawSensorData.getLaserScanBuffer()->getTemporalCloseTo(alloOwnPos->getCreationTime(), ownPoseValidityDuration);

    int idx = 0;

    // TODO: Needed to be implemented with the math from LogicalCameraSensor and you need to know where the closed door should be (x,y).
    // alloOwnPos->getInformation().theta

    // objectPose.theta

    throw new std::runtime_error("DoorStateRecognition::getScanDistance() not implemented,yet!");

    return scan->getInformation()->ranges[idx];
}

} /* namespace wm */
} /* namespace ttb */
