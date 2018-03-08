#pragma once

#include <supplementary/Worker.h>
#include <ros/ros.h>

namespace ttb
{
class TTBWorldModel;
namespace wm
{

class TopologicalInfoPublisher : public supplementary::Worker
{
  public:
    TopologicalInfoPublisher(ttb::TTBWorldModel* wm);
    virtual ~TopologicalInfoPublisher();
    virtual void run();

    private:
    ttb::TTBWorldModel* wm;
    ros::Publisher topoInfoPub;
};

} /* namespace wm */
} /* namespace ttb */
