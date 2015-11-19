using namespace std;

#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"

#include  "Plans/Behaviours/SearchDockingStation.h"

#include  "Plans/Behaviours/Rotate.h"

#include  "Plans/Behaviours/SimpleDrive.h"

#include  "Plans/Behaviours/Stop.h"

#include  "Plans/Behaviours/ChargingDefault.h"

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

            case 1414681446065:

                return make_shared<SearchDockingStation>();
                break;

            case 1447068225787:

                return make_shared<Rotate>();
                break;

            case 1432735473356:

                return make_shared<SimpleDrive>();
                break;

            case 1414681278745:

                return make_shared<Stop>();
                break;

            case 1447958132701:

                return make_shared<ChargingDefault>();
                break;

            default:
                cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << endl;
                throw new exception();
                break;
        }
    }
}
