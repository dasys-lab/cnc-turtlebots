#include "UtilityFunctionCreator.h"
#include "ServiceRobots/Charge1553186270535.h"
#include "ServiceRobots/DriveToPOI1553186299639.h"
#include "ServiceRobots/PickUp1553186320902.h"
#include "ServiceRobots/PutDown1553186313956.h"
#include "ServiceRobots/Search1553186306469.h"
#include "ServiceRobots/Serve1553186258644.h"
#include "ServiceRobots/ServeMaster1553184964252.h"
#include <iostream>

using namespace alicaAutogenerated;

namespace alica
{

UtilityFunctionCreator::~UtilityFunctionCreator() {}

UtilityFunctionCreator::UtilityFunctionCreator() {}

std::shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
{
    switch (utilityfunctionConfId) {
    case 1553184964252:
        return std::make_shared<UtilityFunction1553184964252>();
        break;
    case 1553186258644:
        return std::make_shared<UtilityFunction1553186258644>();
        break;
    case 1553186270535:
        return std::make_shared<UtilityFunction1553186270535>();
        break;
    case 1553186299639:
        return std::make_shared<UtilityFunction1553186299639>();
        break;
    case 1553186306469:
        return std::make_shared<UtilityFunction1553186306469>();
        break;
    case 1553186313956:
        return std::make_shared<UtilityFunction1553186313956>();
        break;
    case 1553186320902:
        return std::make_shared<UtilityFunction1553186320902>();
        break;
    default:
        std::cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << std::endl;
        throw new std::exception();
        break;
    }
}

} // namespace alica
