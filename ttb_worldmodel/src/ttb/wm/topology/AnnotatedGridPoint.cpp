#include "ttb/wm/topology/AnnotatedGridPoint.h"

namespace ttb
{
namespace wm
{

AnnotatedGridPoint::AnnotatedGridPoint(std::shared_ptr<ttb::wm::Room> room, geometry_msgs::Point point)
        : room(room)
{
    this->x = point.x;
    this->y = point.y;
}

AnnotatedGridPoint::~AnnotatedGridPoint() {}

} /* namespace wm */
} /* namespace ttb */
