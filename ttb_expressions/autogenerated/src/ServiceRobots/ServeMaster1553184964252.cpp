#include "ServiceRobots/ServeMaster1553184964252.h"
/*PROTECTED REGION ID(eph1553184964252) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:ServeMaster
/* generated comment
    Task: DefaultTask  -> EntryPoint-ID: 1553185666788
*/
shared_ptr<UtilityFunction> UtilityFunction1553184964252::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1553184964252) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553185893509, ConditionString: Start received, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Stop, (PlanID): 1553185137554
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553185666788)
 *
 * States:
 *
 *   - Stop (1553185656305)
 *   - Serve (1553185657036)
 *   - Charge (1553185657561)
 *
 * Vars:
 */
bool PreCondition1553185893509::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553185745471) ENABLED START*/
    return implement_me_1553185745471;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553185932074, ConditionString: low accu, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Serve, (PlanID): 1553186258644
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553185666788)
 *
 * States:
 *
 *   - Stop (1553185656305)
 *   - Serve (1553185657036)
 *   - Charge (1553185657561)
 *
 * Vars:
 */
bool PreCondition1553185932074::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553185750137) ENABLED START*/
    return implement_me_1553185750137;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186173260, ConditionString: Stop received, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Serve, (PlanID): 1553186258644
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553185666788)
 *
 * States:
 *
 *   - Stop (1553185656305)
 *   - Serve (1553185657036)
 *   - Charge (1553185657561)
 *
 * Vars:
 */
bool PreCondition1553186173260::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186159975) ENABLED START*/
    return implement_me_1553186159975;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553185967081, ConditionString: Stop received, Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Charge, (PlanID): 1553186270535
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553185666788)
 *
 * States:
 *
 *   - Stop (1553185656305)
 *   - Serve (1553185657036)
 *   - Charge (1553185657561)
 *
 * Vars:
 */
bool PreCondition1553185967081::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553185754607) ENABLED START*/
    return implement_me_1553185754607;
    /*PROTECTED REGION END*/
}
/*
 *
 * Transition:
 *   - Name: 1553186199715, ConditionString: fully charged (child success), Comment : MISSING_COMMENT
 *
 * Plans in State:
 *
 *   - Plan - (Name): Charge, (PlanID): 1553186270535
 *
 * Tasks:
 *
 *   - DefaultTask (1528875085489) (Entrypoint: 1553185666788)
 *
 * States:
 *
 *   - Stop (1553185656305)
 *   - Serve (1553185657036)
 *   - Charge (1553185657561)
 *
 * Vars:
 */
bool PreCondition1553186199715::evaluate(shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1553186193775) ENABLED START*/
    return implement_me_1553186193775;
    /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated
