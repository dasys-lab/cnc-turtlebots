#include <iostream>
#include "UtilityFunctionCreator.h"

#include  "Plans/TurtleTestMaster1414681057676.h"

using namespace std;
using namespace alicaAutogenerated;
namespace alica
{

UtilityFunctionCreator::~UtilityFunctionCreator()
{
}

UtilityFunctionCreator::UtilityFunctionCreator()
{
}

shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
{
  switch (utilityfunctionConfId)
  {

    case 1414681057676:
      return make_shared<UtilityFunction1414681057676>();
      break;

    default:
      cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << endl;
      throw new exception();
      break;
  }
}

}
