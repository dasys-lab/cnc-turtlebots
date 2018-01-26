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

class Cup : public LogicalObject
{
  public:
    Cup(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~Cup();
};

} /* namespace wm */
} /* namespace ttb */

