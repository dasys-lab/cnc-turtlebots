#pragma once

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

  private:
    TTBWorldModel *wm;
    double catchRadius;
};

} /* namespace wm */
} /* namespace ttb */
