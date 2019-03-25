#include "ConstraintCreator.h"

#include "ServiceRobots/constraints/Charge1553186270535Constraints.h"
#include "ServiceRobots/constraints/DriveToPOI1553186299639Constraints.h"
#include "ServiceRobots/constraints/PickUp1553186320902Constraints.h"
#include "ServiceRobots/constraints/PutDown1553186313956Constraints.h"
#include "ServiceRobots/constraints/Search1553186306469Constraints.h"
#include "ServiceRobots/constraints/Serve1553186258644Constraints.h"
#include "ServiceRobots/constraints/ServeMaster1553184964252Constraints.h"

#include <iostream>

using namespace alicaAutogenerated;

namespace alica
{

ConstraintCreator::ConstraintCreator() {}

ConstraintCreator::~ConstraintCreator() {}

shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(long constraintConfId)
{
    switch (constraintConfId) {
    case 1553249831272:
        return std::make_shared<Constraint1553249831272>();
        break;
    case 1553251210748:
        return std::make_shared<Constraint1553251210748>();
        break;
    case 1553506204186:
        return std::make_shared<Constraint1553506204186>();
        break;
    case 1553508629606:
        return std::make_shared<Constraint1553508629606>();
        break;
    default:
        std::cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << std::endl;
        throw new std::exception();
        break;
    }
}

} // namespace alica
