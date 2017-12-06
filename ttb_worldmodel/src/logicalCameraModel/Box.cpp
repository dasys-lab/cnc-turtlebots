#include "logicalCameraModel/Box.h"

#include <SystemConfig.h>

namespace ttb
{
namespace wm
{
Box::Box(ttb_msgs::LogicalCameraPtr logicalCameraData)
    : LogicalObject(logicalCameraData, "Box")
{

}

Box::~Box()
{
}
}
}
