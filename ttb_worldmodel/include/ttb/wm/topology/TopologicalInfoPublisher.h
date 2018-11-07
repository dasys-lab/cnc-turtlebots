#pragma once

#include <ros/ros.h>
#include <supplementary/Worker.h>

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
