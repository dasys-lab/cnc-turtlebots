#pragma once

#include <cnc_geometry/CNPointAllo.h>

#include <memory>

namespace ttb
{
namespace wm
{

class Room;

class AnnotatedGridPoint : public geometry::CNPointAllo
{
public:
    AnnotatedGridPoint(std::shared_ptr<ttb::wm::Room> room, geometry_msgs::Point point);
    virtual ~AnnotatedGridPoint();

    std::shared_ptr<ttb::wm::Room> room;
};

} /* namespace wm */
} /* namespace ttb */
