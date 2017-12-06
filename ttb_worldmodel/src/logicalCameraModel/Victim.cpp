#include <logicalCameraModel/Victim.h>

namespace ttb
{
namespace wm
{

Victim::Victim(ttb_msgs::LogicalCameraPtr logicalCameraData, supplementary::InfoTime maxValidityDuration)
    : LogicalObject(logicalCameraData, "Victim")
{
}

Victim::~Victim()
{
}

}
}
