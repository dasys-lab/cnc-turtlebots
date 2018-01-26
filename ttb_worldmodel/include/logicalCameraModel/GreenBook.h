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

class GreenBook : public LogicalObject
{
  public:
    GreenBook(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~GreenBook();
};

} /* namespace wm */
} /* namespace ttb */

