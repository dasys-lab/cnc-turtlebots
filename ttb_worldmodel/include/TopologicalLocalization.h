#pragma once

#include <supplementary/Worker.h>
#include <ros/ros.h>
#include "topology/Room.h"
#include "supplementary/InfoBuffer.h"

#define TOPOLOGICAL_LOCALIZATION_DEBUG

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class LogicalCameraData;
class TopologicalLocalization : public supplementary::Worker
{
  public:
    TopologicalLocalization(ttb::TTBWorldModel* wm);
    virtual ~TopologicalLocalization();

    virtual void run();
    void sendUpdate(std::shared_ptr<Room> room);
    const supplementary::InfoBuffer<std::shared_ptr<Room>> *getRoomBuffer();

  private:
    ttb::TTBWorldModel* wm;

    ros::Publisher topoInfoPub;

    supplementary::InfoTime ownPoseValidityDuration;
    supplementary::InfoTime roomValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<Room>> *roomBuffer;
};

} /* namespace wm */
} /* namespace ttb */
