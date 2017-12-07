#include <logicalCameraModel/Victim.h>

namespace ttb
{
namespace wm
{

Victim::Victim(ttb_msgs::LogicalCameraPtr logicalCameraData)
    : LogicalObject(logicalCameraData, "Victim")
{
}

Victim::~Victim()
{
}

}
}
