using namespace std;

#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"

#include  "Plans/Serve/PKVR16/PickUp.h"

#include  "Plans/Behaviours/Wumpus/WaitForTurn.h"

#include  "Plans/Behaviours/Wumpus/Wumpus.h"

#include  "Plans/Behaviours/Wumpus/Shoot.h"

#include  "Plans/Behaviours/SearchForDockingStationAsp.h"

#include  "Plans/Behaviours/ASPNavigation.h"

#include  "Plans/Behaviours/ChargingDefault.h"

#include  "Plans/Behaviours/Wumpus/Move.h"

#include  "Plans/Behaviours/Carry.h"

#include  "Plans/Behaviours/Wumpus/Leave.h"

#include  "Plans/Behaviours/ASPMinimizePath.h"

#include  "Plans/Behaviours/Wumpus/SpawnAgent.h"

#include  "Plans/Behaviours/Stop.h"

#include  "Plans/Serve/PKVR16/DriveSearchPattern.h"

#include  "Plans/Behaviours/ASPNavwoExt.h"

#include  "Plans/Behaviours/DriveToPOI.h"

#include  "Plans/Behaviours/SimpleDrive.h"

#include  "Plans/Behaviours/Rotate.h"

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

            case 1486381497239:

                return make_shared<PickUp>();
                break;

            case 1489673907866:

                return make_shared<WaitForTurn>();
                break;

            case 1489674671969:

                return make_shared<Wumpus>();
                break;

            case 1489674687663:

                return make_shared<Shoot>();
                break;

            case 1470041828429:

                return make_shared<SearchForDockingStationAsp>();
                break;

            case 1475693376771:

            case 1476356448920:

                return make_shared<ASPNavigation>();
                break;

            case 1447958132701:

                return make_shared<ChargingDefault>();
                break;

            case 1489674705705:

                return make_shared<Move>();
                break;

            case 1468494631985:

                return make_shared<Carry>();
                break;

            case 1489674658684:

                return make_shared<Leave>();
                break;

            case 1477125946392:

                return make_shared<ASPMinimizePath>();
                break;

            case 1489673543981:

                return make_shared<SpawnAgent>();
                break;

            case 1414681278745:

                return make_shared<Stop>();
                break;

            case 1481546413105:

                return make_shared<DriveSearchPattern>();
                break;

            case 1477229777461:

            case 1477229800616:

                return make_shared<ASPNavwoExt>();
                break;

            case 1454329864420:

            case 1454329905072:

            case 1454329918634:

            case 1454330438527:

                return make_shared<DriveToPOI>();
                break;

            case 1432735473356:

                return make_shared<SimpleDrive>();
                break;

            case 1447068225787:

                return make_shared<Rotate>();
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
