#include "ttb/TTBWorldModel.h"

//#include "ttb/WrappedMessageHandler.h"
//#include "ttb/wm/Communication.h"
//#include "ttb/wm/RawSensorData.h"

#include <chrono>
#include <engine/AlicaClock.h>
#include <engine/AlicaEngine.h>
#include <nav_msgs/Odometry.h>

namespace ttb
{

TTBWorldModel* TTBWorldModel::get()
{
    static TTBWorldModel instance;
    return &instance;
}

TTBWorldModel::TTBWorldModel()
        : WorldModel()
        , rawSensorData(this)
        , logicalCameraData(this)
        , topologicalLocalization(this)
        , topologicalModel(this)
        , doorStateRecognition(this)
        , usingSimulator(false)
        , communication(nullptr)
        , topoInfoPublisher(this)
        , robot(this)
{
    this->robotName = sc->getHostname();
}

TTBWorldModel::~TTBWorldModel()
{
    delete this->communication;
    this->topologicalLocalization.stop();
    this->doorStateRecognition.stop();
    this->topoInfoPublisher.stop();
}

std::string TTBWorldModel::getRobotName()
{
    return this->robotName;
}

void TTBWorldModel::init()
{
    this->communication = new wm::Communication(this);
    this->topologicalLocalization.setIntervalMS(std::chrono::milliseconds(33));
    this->topologicalLocalization.start();
    this->doorStateRecognition.setIntervalMS(std::chrono::milliseconds(100));
    this->doorStateRecognition.start();
    this->topoInfoPublisher.setIntervalMS(std::chrono::milliseconds(300));
    this->topoInfoPublisher.start();
}

bool TTBWorldModel::isUsingSimulator()
{
    return this->usingSimulator || (this->communication != nullptr && this->communication->getTimeLastSimMsgReceived() > alica::AlicaTime::zero());
}

void TTBWorldModel::enableUsingSimulator()
{
#ifdef TTB_WORLDMODEL_DEBUG
    std::cout << "TTB-WM: SIMULATION MODE ENABLED!" << std::endl;
#endif
    this->usingSimulator = true;
}

} /* namespace ttb */
