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

class BlueBook : public LogicalObject
{
  public:
    BlueBook(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~BlueBook();
};

} /* namespace wm */
} /* namespace ttb */

