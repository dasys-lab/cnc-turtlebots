#include "ServiceRobots/constraints/PutDown1553186313956Constraints.h"
/*PROTECTED REGION ID(ch1553186313956) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:PutDown
/*
 * Tasks:
 * - EP:1553251833164 : DefaultTask (1528875085489)
 *
 * States:
 * - DriveToPoint (1553251836208)
 * - PutDown (1553251837742)
 * - DriveToFailed (1553251860992)
 * - FailedToPlaceObject (1553251862908)
 * - ObjectPlaced (1553254969436)
 *
 * Vars:
 * - X (1553506228672)
 * - Y (1553506233885)
 * - Z (1553506237542)
 * - entity (1553506241307)
 */
/*
 * RuntimeCondition - (Name): 1553506204186
 * (ConditionString):
 * Static Variables: X Y Z entity
 * Domain Variables:
 *
 */
void Constraint1553506204186::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1553506204186) ENABLED START*/
    // Please describe your runtime constraint here
    /*PROTECTED REGION END*/
}

// State: DriveToPoint
// State: PutDown
// State: DriveToFailed
// State: FailedToPlaceObject
// State: ObjectPlaced
} // namespace alicaAutogenerated
