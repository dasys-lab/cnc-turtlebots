#pragma once

#include "LogicalCameraData.h"
#include "RawSensorData.h"
#include "SystemConfig.h"
#include "TaskManager.h"
#include "Communication.h"
#include "TopologicalLocalization.h"
#include "TopologicalModel.h"
#include "DoorStateRecognition.h"
#include "TopologicalInfoPublisher.h"

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
    std::string getRobotName();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::LogicalCameraData logicalCameraData;
    wm::TopologicalModel topologicalModel;
    wm::TopologicalLocalization topologicalLocalization;
    wm::DoorStateRecognition doorStateRecognition;
    wm::TaskManager taskManager;
    wm::Communication* communication;
    wm::TopologicalInfoPublisher topoInfoPublisher;

  private:
    TTBWorldModel(); /**< Private Singleton Constructor */

    bool usingSimulator;
    std::string robotName;
};

} /* namespace ttb */

