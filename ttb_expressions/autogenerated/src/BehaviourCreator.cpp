#include "BehaviourCreator.h"
#include "ServiceRobots/DriveSearchPattern.h"
#include "ServiceRobots/DriveToWMsPOI.h"
#include "ServiceRobots/PickUp.h"
#include "ServiceRobots/Stop.h"
#include "engine/BasicBehaviour.h"

namespace alica
{

BehaviourCreator::BehaviourCreator() {}

BehaviourCreator::~BehaviourCreator() {}

std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourConfId)
{
    switch (behaviourConfId) {
    case 1552996811900:
        return std::make_shared<Stop>();
        break;
    case 1552997304057:
        return std::make_shared<PickUp>();
        break;
    case 1552997315918:
        return std::make_shared<DriveToWMsPOI>();
        break;
    case 1552997370653:
        return std::make_shared<DriveSearchPattern>();
        break;
    default:
        std::cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << std::endl;
        throw new std::exception();
        break;
    }
}
} // namespace alica
