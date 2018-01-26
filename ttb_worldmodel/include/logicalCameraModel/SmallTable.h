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

class SmallTable : public LogicalObject
{
  public:
    SmallTable(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~SmallTable();
};

} /* namespace wm */
} /* namespace ttb */

