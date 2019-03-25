#include "ServiceRobots/PutDown1553186313956.h"
/*PROTECTED REGION ID(eph1553186313956) ENABLED START*/
#include <TurtleBot.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:PutDown
// Check of RuntimeCondition - (Name): 1553506204186, (ConditionString): , (Comment) :

/*
 * Available Vars:
 *	- X (1553506228672)
 *	- Y (1553506233885)
 *	- Z (1553506237542)
 *	- entity (1553506241307)
 */
bool RunTimeCondition1553506204186::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553506204186) ENABLED START*/
    return true;
    /*PROTECTED REGION END*/
}
/* generated comment
    Task: DefaultTask  -> EntryPoint-ID: 1553251833164
*/
shared_ptr<UtilityFunction> UtilityFunction1553186313956::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1553186313956) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553503395943, ConditionString: Arrived at point, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): DriveToPoint, (PlanID): 1553508193766
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553251833164)
 *
 * States:
 *
 *   - DriveToPoint (1553251836208)
 *   - PutDown (1553251837742)
 *   - DriveToFailed (1553251860992)
 *   - FailedToPlaceObject (1553251862908)
 *   - ObjectPlaced (1553254969436)
 *
 * Vars:
 */
bool PreCondition1553503395943::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553251878842) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553503428123, ConditionString: failed to drive to point, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): DriveToPoint, (PlanID): 1553508193766
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553251833164)
 *
 * States:
 *
 *   - DriveToPoint (1553251836208)
 *   - PutDown (1553251837742)
 *   - DriveToFailed (1553251860992)
 *   - FailedToPlaceObject (1553251862908)
 *   - ObjectPlaced (1553254969436)
 *
 * Vars:
 */
bool PreCondition1553503428123::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553503372591) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Failed);
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553503411200, ConditionString: PutDown to DriveToPoint, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): PutDown, (PlanID): 1553508167181
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553251833164)
 *
 * States:
 *
 *   - DriveToPoint (1553251836208)
 *   - PutDown (1553251837742)
 *   - DriveToFailed (1553251860992)
 *   - FailedToPlaceObject (1553251862908)
 *   - ObjectPlaced (1553254969436)
 *
 * Vars:
 */
bool PreCondition1553503411200::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553503358877) ENABLED START*/
    // TODO missing in behaviour
    return false;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553503439638, ConditionString: Failed putting down, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): PutDown, (PlanID): 1553508167181
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553251833164)
 *
 * States:
 *
 *   - DriveToPoint (1553251836208)
 *   - PutDown (1553251837742)
 *   - DriveToFailed (1553251860992)
 *   - FailedToPlaceObject (1553251862908)
 *   - ObjectPlaced (1553254969436)
 *
 * Vars:
 */
bool PreCondition1553503439638::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553503376373) ENABLED START*/
    return rp->isAnyChildStatus(PlanStatus::Failed);
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553503451171, ConditionString: Putting down Successful, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): PutDown, (PlanID): 1553508167181
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553251833164)
 *
 * States:
 *
 *   - DriveToPoint (1553251836208)
 *   - PutDown (1553251837742)
 *   - DriveToFailed (1553251860992)
 *   - FailedToPlaceObject (1553251862908)
 *   - ObjectPlaced (1553254969436)
 *
 * Vars:
 */
bool PreCondition1553503451171::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553503379375) ENABLED START*/
    auto currentTask = this->wm->taskManager.getNextTask();
    if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PUT_DOWN) {
        // current task is not for driving to an POI, so don't specify any problem descriptor
        return false;
    }
    auto objectName = ttb::TurtleBot::get(this->wm)->simulatedArm->getCarriedObjectName();
    if (objectName.compare("") != 0) {
        return false;
    } else {
        std::cout << "PutDown-Plan: Successfully put down " << currentTask->getInformation().entity << std::endl;
        this->wm->taskManager.popNextTask();
        return true;
    }
    /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated
