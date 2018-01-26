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

class MediumTable : public LogicalObject
{
  public:
    MediumTable(ttb_msgs::LogicalCameraPtr logicalCameraData);
    virtual ~MediumTable();
};

} /* namespace wm */
} /* namespace ttb */

