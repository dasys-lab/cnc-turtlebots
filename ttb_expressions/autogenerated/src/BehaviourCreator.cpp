#include "BehaviourCreator.h"
#include "Plans/Behaviours/ASPMinimizePath.h"
#include "Plans/Behaviours/ASPNavigation.h"
#include "Plans/Behaviours/ASPNavwoExt.h"
#include "Plans/Behaviours/ASPRCCTest.h"
#include "Plans/Behaviours/Carry.h"
#include "Plans/Behaviours/ChargingDefault.h"
#include "Plans/Behaviours/DriveCloseToObject.h"
#include "Plans/Behaviours/DriveToPOI.h"
#include "Plans/Behaviours/DriveToPoint.h"
#include "Plans/Behaviours/OpenDoor.h"
#include "Plans/Behaviours/PickUp.h"
#include "Plans/Behaviours/PutDown.h"
#include "Plans/Behaviours/Rotate.h"
#include "Plans/Behaviours/SearchDockingStation.h"
#include "Plans/Behaviours/SearchForDockingStationAsp.h"
#include "Plans/Behaviours/SimpleDrive.h"
#include "Plans/Behaviours/Stop.h"
#include "Plans/Behaviours/Sweep.h"
#include "engine/BasicBehaviour.h"

using std::cout;
using std::exception;
using std::make_shared;
using std::string;

namespace alica
{

BehaviourCreator::BehaviourCreator() {}

BehaviourCreator::~BehaviourCreator() {}

std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourConfId)
{
    switch (behaviourConfId) {
    case 1414681269156:
        return make_shared<Stop>();
        break;
    case 1414681429307:
        return make_shared<SearchDockingStation>();
        break;
    case 1432735451661:
        return make_shared<SimpleDrive>();
        break;
    case 1447068205139:
        return make_shared<Rotate>();
        break;
    case 1447958115909:
        return make_shared<ChargingDefault>();
        break;
    case 1454329856163:
        return make_shared<DriveToPOI>();
        break;
    case 1468494621581:
        return make_shared<Carry>();
        break;
    case 1470041810334:
        return make_shared<SearchForDockingStationAsp>();
        break;
    case 1475693360605:
        return make_shared<ASPNavigation>();
        break;
    case 1477125924367:
        return make_shared<ASPMinimizePath>();
        break;
    case 1477229760910:
        return make_shared<ASPNavwoExt>();
        break;
    case 1480766583222:
        return make_shared<ASPRCCTest>();
        break;
    case 1519913953735:
        return make_shared<OpenDoor>();
        break;
    case 1520437499749:
        return make_shared<Sweep>();
        break;
    case 1520438451345:
        return make_shared<PickUp>();
        break;
    case 1520521852939:
        return make_shared<DriveCloseToObject>();
        break;
    case 1520850797525:
        return make_shared<PutDown>();
        break;
    case 1520850811997:
        return make_shared<DriveToPoint>();
        break;
    default:
        cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << endl;
        throw exception();
        break;
    }
}
} // namespace alica
