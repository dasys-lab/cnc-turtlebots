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
{
}

TTBWorldModel::~TTBWorldModel()
{
}

} /* namespace ttb */
