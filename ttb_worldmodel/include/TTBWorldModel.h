#pragma once

#include "LogicalCameraData.h"
#include "RawSensorData.h"
#include "SystemConfig.h"
#include "TaskManager.h"
#include "Communication.h"
#include "TopologicalLocalization.h"
#include "TopologicalModel.h"

#include <supplementary/EventTrigger.h>
#include <supplementary/WorldModel.h>
#include <supplementary/InformationElement.h>

namespace supplementary
{
class SystemConfig;
}

namespace alica
{
class AlicaEngine;
}

namespace ttb
{
class WrappedMessageHandler;

class TTBWorldModel : public supplementary::WorldModel
{
  public:
    static TTBWorldModel *get(); /**< Singleton Getter */

    virtual ~TTBWorldModel();
    void init();
    bool isUsingSimulator();
    void enableUsingSimulator();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::LogicalCameraData logicalCameraData;
    wm::TopologicalModel topologicalModel;
    wm::TopologicalLocalization topologicalLocalization;
    wm::TaskManager taskManager;
    wm::Communication* communication;

  private:
    TTBWorldModel(); /**< Private Singleton Constructor */

    bool usingSimulator;
};

} /* namespace ttb */

