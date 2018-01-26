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

class RedBook : public LogicalObject
{
  public:
    RedBook(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~RedBook();
};

} /* namespace wm */
} /* namespace ttb */

