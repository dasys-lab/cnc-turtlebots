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

class ContaminatedArea : public LogicalObject
{
  public:
    ContaminatedArea(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~ContaminatedArea();
};

} /* namespace wm */
} /* namespace ttb */

