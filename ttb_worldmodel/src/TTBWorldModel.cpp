#include "TTBWorldModel.h"

#include "Communication.h"
#include "RawSensorData.h"
#include "WrappedMessageHandler.h"

#include <engine/AlicaEngine.h>
#include <engine/IAlicaClock.h>
#include <nav_msgs/Odometry.h>
#include <chrono>

namespace ttb
{

TTBWorldModel *TTBWorldModel::get()
{
    static TTBWorldModel instance;
    return &instance;
}

TTBWorldModel::TTBWorldModel() :
		WorldModel()
    , rawSensorData(this)
    , logicalCameraData(this)
	, topologicalLocalization(this)
	, topologicalModel(this)
	, usingSimulator(false)
	, communication(nullptr)
{
	this->robotName = sc->getHostname();
}

TTBWorldModel::~TTBWorldModel()
{
	delete this->communication;
	this->topologicalLocalization.stop();
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
}

bool TTBWorldModel::isUsingSimulator()
{
	return this->usingSimulator || (this->communication != nullptr && this->communication->getTimeLastSimMsgReceived() > 0);
}

void TTBWorldModel::enableUsingSimulator()
{
#ifdef TTB_WORLDMODEL_DEBUG
	std::cout << "TTB-WM: SIMULATION MODE ENABLED!" << std::endl;
#endif
	this->usingSimulator = true;
}

} /* namespace ttb */

