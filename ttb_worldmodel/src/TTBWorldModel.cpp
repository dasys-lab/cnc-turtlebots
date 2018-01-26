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

TTBWorldModel::TTBWorldModel() :
		WorldModel()
    , rawSensorData(this)
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
#ifdef TTB_WORLDMODEL_DEBUG
	std::cout << "TTB-WM: SIMULATION MODE ENABLED!" << std::endl;
#endif
	this->usingSimulator = true;
}

} /* namespace ttb */

