#include "BehaviourCreator.h"
#include "ServiceRobots/Behaviours/DriveCloseToObject.h"
#include "ServiceRobots/Behaviours/DriveToPOI.h"
#include "ServiceRobots/Behaviours/DriveToPoint.h"
#include "ServiceRobots/Behaviours/OpenDoor.h"
#include "ServiceRobots/Behaviours/PickUp.h"
#include "ServiceRobots/Behaviours/PutDown.h"
#include "ServiceRobots/Behaviours/Stop.h"
#include "ServiceRobots/Behaviours/Sweep.h"
#include "engine/BasicBehaviour.h"

namespace alica
{

BehaviourCreator::BehaviourCreator() {}

BehaviourCreator::~BehaviourCreator() {}

std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourConfId)
{
    switch (behaviourConfId) {
    case 1553185137554:
        return std::make_shared<Stop>();
        break;
    case 1553249791474:
        return std::make_shared<DriveToPOI>();
        break;
    case 1553249804320:
        return std::make_shared<OpenDoor>();
        break;
    case 1553251475582:
        return std::make_shared<PickUp>();
        break;
    case 1553251534505:
        return std::make_shared<DriveCloseToObject>();
        break;
    case 1553508167181:
        return std::make_shared<PutDown>();
        break;
    case 1553508193766:
        return std::make_shared<DriveToPoint>();
        break;
    case 1553508619994:
        return std::make_shared<Sweep>();
        break;
    default:
        std::cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << std::endl;
        throw new std::exception();
        break;
    }
}
} // namespace alica
