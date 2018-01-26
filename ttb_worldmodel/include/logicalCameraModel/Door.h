#pragma once

#include <logicalCameraModel/LogicalObject.h>

namespace ttb_msgs
{
	ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
namespace wm
{

class Door : public LogicalObject
{
  public:
    Door(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~Door();
};

} /* namespace wm */
} /* namespace ttb */

