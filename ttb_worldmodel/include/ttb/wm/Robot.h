#pragma once

#include <geometry_msgs/Pose2D.h>

#include <nonstd/optional.hpp>

#include <memory>

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class POI;
class Robot
{
  public:
    Robot(TTBWorldModel *wm);
    virtual ~Robot();
    bool isCloseTo(std::shared_ptr<POI> goalPOI);
    bool isCloseTo(nonstd::optional<geometry_msgs::Pose2D> position);
    bool inSameRoom(std::shared_ptr<POI> goalPOI);

  private:
    TTBWorldModel *wm;
    double catchRadius;
};

} /* namespace wm */
} /* namespace ttb */
