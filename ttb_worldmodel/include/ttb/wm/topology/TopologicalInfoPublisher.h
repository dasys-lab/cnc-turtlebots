#pragma once

#include <ros/ros.h>
#include <essentials/Worker.h>

namespace ttb
{
class TTBWorldModel;
namespace wm
{

class TopologicalInfoPublisher : public essentials::Worker
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
