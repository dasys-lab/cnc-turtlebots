using namespace std;

#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"

#include  "Plans/Behaviours/DriveCloseToObject.h"

#include  "Plans/Behaviours/Sweep.h"

#include  "Plans/Behaviours/SearchForDockingStationAsp.h"

#include  "Plans/Behaviours/ASPNavigation.h"

#include  "Plans/Behaviours/OpenDoor.h"

#include  "Plans/Behaviours/ChargingDefault.h"

#include  "Plans/Behaviours/Carry.h"

#include  "Plans/Behaviours/PutDown.h"

#include  "Plans/Behaviours/PickUp.h"

#include  "Plans/Behaviours/ASPMinimizePath.h"

#include  "Plans/Behaviours/Stop.h"

#include  "Plans/Behaviours/ASPNavwoExt.h"

#include  "Plans/Behaviours/DriveToPOI.h"

#include  "Plans/Behaviours/SimpleDrive.h"

#include  "Plans/Behaviours/Rotate.h"

#include  "Plans/Behaviours/DriveToPoint.h"

#include  "Plans/Behaviours/SearchDockingStation.h"

#include  "Plans/Behaviours/ASPRCCTest.h"

namespace alica
{

    BehaviourCreator::BehaviourCreator()
    {
    }

    BehaviourCreator::~BehaviourCreator()
    {
    }

    shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourConfId)
    {
        switch (behaviourConfId)
        {

            case 1520521878834:

                return make_shared<DriveCloseToObject>();
                break;

            case 1520437614544:

                return make_shared<Sweep>();
                break;

            case 1470041828429:

                return make_shared<SearchForDockingStationAsp>();
                break;

            case 1475693376771:

            case 1476356448920:

                return make_shared<ASPNavigation>();
                break;

            case 1519913968184:

                return make_shared<OpenDoor>();
                break;

            case 1447958132701:

                return make_shared<ChargingDefault>();
                break;

            case 1468494631985:

                return make_shared<Carry>();
                break;

            case 1520850807590:

                return make_shared<PutDown>();
                break;

            case 1520438478153:

                return make_shared<PickUp>();
                break;

            case 1477125946392:

                return make_shared<ASPMinimizePath>();
                break;

            case 1414681278745:

                return make_shared<Stop>();
                break;

            case 1477229777461:

            case 1477229800616:

                return make_shared<ASPNavwoExt>();
                break;

            case 1519913781149:

                return make_shared<DriveToPOI>();
                break;

            case 1432735473356:

                return make_shared<SimpleDrive>();
                break;

            case 1447068225787:

                return make_shared<Rotate>();
                break;

            case 1520850827610:

                return make_shared<DriveToPoint>();
                break;

            case 1414681446065:

                return make_shared<SearchDockingStation>();
                break;

            case 1480766599215:

                return make_shared<ASPRCCTest>();
                break;

            default:
                cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << endl;
                throw new exception();
                break;
        }
    }
}
