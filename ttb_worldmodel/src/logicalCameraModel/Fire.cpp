#include <logicalCameraModel/Fire.h>

#include <SystemConfig.h>

namespace ttb
{
namespace wm
{
Fire::Fire(ttb_msgs::LogicalCameraPtr logicalCameraData, supplementary::InfoTime maxValidityDuration)
    : LogicalObject(logicalCameraData, "Fire")
{
}

Fire::~Fire()
{
}
}
}
