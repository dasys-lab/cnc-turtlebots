#pragma once

#include "ttb/wm/topology/Room.h"

#include <supplementary/InfoBuffer.h>
#include <essentials/Worker.h>

#define TOPOLOGICAL_LOCALIZATION_DEBUG

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class LogicalCameraData;
class TopologicalLocalization : public essentials::Worker
{
public:
    TopologicalLocalization(ttb::TTBWorldModel* wm);
    virtual ~TopologicalLocalization();

    virtual void run();
    const supplementary::InfoBuffer<std::shared_ptr<Room>>* getRoomBuffer();

private:
    ttb::TTBWorldModel* wm;

    alica::AlicaTime ownPoseValidityDuration;
    alica::AlicaTime roomValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<Room>>* roomBuffer;
};

} /* namespace wm */
} /* namespace ttb */
