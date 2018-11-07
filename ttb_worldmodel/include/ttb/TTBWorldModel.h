#pragma once

#include "ttb/wm/Communication.h"
#include "ttb/wm/DoorStateRecognition.h"
#include "ttb/wm/RawSensorData.h"
#include "ttb/wm/Robot.h"
#include "ttb/wm/TaskManager.h"
#include "ttb/wm/sim/LogicalCameraData.h"
#include "ttb/wm/topology/TopologicalInfoPublisher.h"
#include "ttb/wm/topology/TopologicalLocalization.h"
#include "ttb/wm/topology/TopologicalModel.h"

#include <SystemConfig.h>
#include <supplementary/EventTrigger.h>
#include <supplementary/InformationElement.h>
#include <supplementary/WorldModel.h>

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
    static TTBWorldModel* get(); /**< Singleton Getter */

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
    wm::Robot robot;

private:
    TTBWorldModel(); /**< Private Singleton Constructor */

    bool usingSimulator;
    std::string robotName;
};

} /* namespace ttb */
