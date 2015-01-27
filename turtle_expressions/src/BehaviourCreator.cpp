using namespace std;

#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"

#include  "Plans/Behaviours/SearchDockingStation.h"

#include  "Plans/Behaviours/Stop.h"

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

    case 1414681278745:

    case 1414681405241:

      return make_shared<Stop>();
      break;

    default:
      cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourConfId << endl;
      throw new exception();
      break;
  }
}
}
