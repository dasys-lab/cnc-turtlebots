#include "TTBWorldModel.h"

#include "engine/AlicaEngine.h"
#include "engine/IAlicaClock.h"
#include <nav_msgs/Odometry.h>

#include "RawSensorData.h"
#include "WrappedMessageHandler.h"

namespace ttb
{

TTBWorldModel *TTBWorldModel::get()
{
    static TTBWorldModel instance;
    return &instance;
}

TTBWorldModel::TTBWorldModel()
    : rawSensorData(this)
    , pois(this)
    , doors(this)
    , logicalCameraData(this)
	, usingSimulator(false)
	, communication(nullptr)
{
}

TTBWorldModel::~TTBWorldModel()
{
	delete this->communication;
}

bool TTBWorldModel::isUsingSimulator()
{
	return this->usingSimulator || (this->communication != nullptr && this->communication->getTimeLastSimMsgReceived() > 0);
}

void TTBWorldModel::enableUsingSimulator()
{
	this->usingSimulator = true;
}

void TTBWorldModel::setEngine(alica::AlicaEngine* ae)
{
	this->WorldModel::setEngine(ae);
	this->communication = new ttb::wm::Communication(this);
}

} /* namespace ttb */


