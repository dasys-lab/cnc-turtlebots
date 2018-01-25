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

class TrashCan : public LogicalObject
{
  public:
    TrashCan(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~TrashCan();
};

} /* namespace wm */
} /* namespace ttb */

