#include "ttb/wm/topology/TopologicalLocalization.h"

#include "ttb/TTBWorldModel.h"
#include "ttb/wm/sim/LogicalCameraData.h"

#include <cnc_geometry/Calculator.h>
#include <essentials/Identifier.h>
#include <ttb_msgs/TopologicalInfo.h>

#include <engine/AlicaClock.h>

#include <memory>

namespace ttb
{
namespace wm
{

TopologicalLocalization::TopologicalLocalization(ttb::TTBWorldModel* wm)
        : essentials::Worker("TopologicalLocalization")
        , wm(wm)
{
    essentials::SystemConfig* sc = essentials::SystemConfig::getInstance();
    this->roomBuffer = new supplementary::InfoBuffer<std::shared_ptr<Room>>((*sc)["TopologicalLocalization"]->get<int>("Data.Room.BufferLength", NULL));
    this->roomValidityDuration = alica::AlicaTime::nanoseconds((*sc)["TopologicalLocalization"]->get<int>("Data.Room.ValidityDuration", NULL));

    this->ownPoseValidityDuration = alica::AlicaTime::nanoseconds((*sc)["TTBWorldModel"]->get<int>("Data.AMCLPose.ValidityDuration", NULL));
}

TopologicalLocalization::~TopologicalLocalization() {}

void TopologicalLocalization::run()
{
    auto ownPos = this->wm->rawSensorData.getAMCLPositionBuffer()->getLastValid();
    if (!ownPos) {
        return;
    }

    auto pois = this->wm->topologicalModel.getPOIs();
    std::vector<std::shared_ptr<POI>> currentPOIs;
    for (auto poi : pois) {
        auto pose = poi->gazeboModel->getPoseBuffer()->getTemporalCloseTo(ownPos->getCreationTime(), ownPoseValidityDuration);
        if (pose) {
            currentPOIs.push_back(poi);
        }
    }

    double minDist = std::numeric_limits<double>::max();
    std::shared_ptr<POI> closestPOI;
    if (currentPOIs.empty()) {
        return;
    }
    for (auto tmpPOI : currentPOIs) {
        double tmpDist = geometry::distance(tmpPOI->x, tmpPOI->y, ownPos->getInformation().x, ownPos->getInformation().y);
        if (tmpDist < minDist) {
            minDist = tmpDist;
            closestPOI = tmpPOI;
        }
    }
    auto infoElement =
            std::make_shared<const supplementary::InformationElement<std::shared_ptr<Room>>>(closestPOI->room, wm->getTime(), this->roomValidityDuration, 1.0);
    this->roomBuffer->add(infoElement);
}

const supplementary::InfoBuffer<std::shared_ptr<Room>>* TopologicalLocalization::getRoomBuffer()
{
    return this->roomBuffer;
}
} /* namespace wm */
} /* namespace ttb */
