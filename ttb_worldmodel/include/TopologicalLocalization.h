#pragma once

#include <supplementary/Worker.h>

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class LogicalCameraData;
class TopologicalLocalization : public supplementary::Worker
{
  public:
    TopologicalLocalization(ttb::TTBWorldModel* wm);
    virtual ~TopologicalLocalization();

    virtual void run();
    // TODO: getRoom() method is missing

  private:
    ttb::TTBWorldModel* wm;

};

} /* namespace wm */
} /* namespace ttb */
