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

class LargeTable : public LogicalObject
{
  public:
    LargeTable(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~LargeTable();
};

} /* namespace wm */
} /* namespace ttb */

