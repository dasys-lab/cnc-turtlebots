#include <logicalCameraModel/Landmark.h>

namespace ttb
{
namespace wm
{
Landmark::Landmark(ttb_msgs::LogicalCameraPtr logicalCameraData, supplementary::InfoTime maxValidityDuration)
    : LogicalObject(logicalCameraData, "Landmark")
{
}

Landmark::~Landmark()
{
}
}
} /* namespace ttb */
