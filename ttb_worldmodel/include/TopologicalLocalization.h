#pragma once

namespace ttb
{
namespace wm
{
class LogicalCameraData;
class TopologicalLocalization
{
  public:
    TopologicalLocalization(LogicalCameraData* logicalCameraData);
    virtual ~TopologicalLocalization();

    void tick();

  private:
    LogicalCameraData* logicalCameraData;


};

} /* namespace wm */
} /* namespace ttb */
