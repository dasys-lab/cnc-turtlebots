#pragma once

#include <cnc_geometry/CNPositionAllo.h>
#include <gazebo_msgs/ModelStates.h>
#include <geometry_msgs/Pose2D.h>
#include <ros/ros.h>
#include <supplementary/InfoBuffer.h>
#include <essentials/Worker.h>

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class Door;

class DoorStateRecognition : public essentials::Worker
{
public:
    DoorStateRecognition(ttb::TTBWorldModel* wm);
    virtual ~DoorStateRecognition();

    virtual void run();

private:
    ttb::TTBWorldModel* wm;
    alica::AlicaTime ownPoseValidityDuration;
    double epsilon;

    void onGazeboModelStates(gazebo_msgs::ModelStatesPtr msg);
    bool isOpen(std::shared_ptr<ttb::wm::Door> door, double z);
    double getScanDistance(std::shared_ptr<const supplementary::InformationElement<geometry::CNPositionAllo>> alloOwnPos, geometry_msgs::Pose2D objectPose);
};

} /* namespace wm */
} /* namespace ttb */
