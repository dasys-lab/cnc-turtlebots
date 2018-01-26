#pragma once

#include "Doors.h"
#include "EventTrigger.h"
#include "LogicalCameraData.h"
#include "RawSensorData.h"
#include "SystemConfig.h"
#include "TaskManager.h"
#include "Communication.h"
#include "ttb_poi/TTBPointOfInterests.h"
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
    bool isUsingSimulator();
    void enableUsingSimulator();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::LogicalCameraData logicalCameraData;
    wm::TaskManager taskManager;
    wm::TTBPointOfInterests pois;
    wm::Doors doors;
    wm::Communication* communication;

  private:
    TTBWorldModel(); /**< Private Singleton Constructor */

    bool usingSimulator;
};

} /* namespace ttb */

