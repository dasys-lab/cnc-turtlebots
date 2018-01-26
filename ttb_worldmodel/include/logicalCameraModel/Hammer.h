#pragma once

#include <logicalCameraModel/LogicalObject.h>
#include <ros/ros.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
namespace wm
{

class Hammer : public LogicalObject
{
  public:
    Hammer(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~Hammer();
};

} /* namespace wm */
} /* namespace ttb */

