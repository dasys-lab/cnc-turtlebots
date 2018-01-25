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

class MonkeyWrench : public LogicalObject
{
  public:
    MonkeyWrench(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~MonkeyWrench();
};

} /* namespace wm */
} /* namespace ttb */

