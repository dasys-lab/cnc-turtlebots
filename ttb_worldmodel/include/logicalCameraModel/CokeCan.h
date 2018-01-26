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

class CokeCan : public LogicalObject
{
  public:
    CokeCan(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~CokeCan();
};

} /* namespace wm */
} /* namespace ttb */

