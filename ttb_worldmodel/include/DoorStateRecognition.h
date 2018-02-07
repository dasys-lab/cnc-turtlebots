#pragma once

#include <supplementary/Worker.h>
#include <cnc_geometry/CNPositionAllo.h>
#include <geometry_msgs/Pose2D.h>
#include <supplementary/InfoBuffer.h>

namespace ttb
{
class TTBWorldModel;
namespace wm
{

class DoorStateRecognition : public supplementary::Worker
{
  public:
    DoorStateRecognition(ttb::TTBWorldModel *wm);
    virtual ~DoorStateRecognition();

    virtual void run();
  private:
    ttb::TTBWorldModel *wm;
    supplementary::InfoTime ownPoseValidityDuration;

    double getScanDistance(std::shared_ptr<const supplementary::InformationElement<geometry::CNPositionAllo>> alloOwnPos, geometry_msgs::Pose2D objectPose);
};

} /* namespace wm */
} /* namespace ttb */
