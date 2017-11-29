#include "Plans/Wumpus/Turn1489674129255.h"
using namespace alica;
/*PROTECTED REGION ID(eph1489674129255) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:Turn

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1489674153776

     */
    shared_ptr<UtilityFunction> UtilityFunction1489674129255::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1489674129255) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: NewState in Plan: Turn

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : No Stench and no breeze and no gold 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489674258430::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489674256879) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Gold on current tile 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489674311741::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489674310751) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Have arrow and wumpus close 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489674364780::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489674362167) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Have gold and on own exit 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489674399440::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489674397808) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Move in Plan: Turn

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : succ 
     *
     * Plans in State: 				
     *   - Plan - (Name): MoveDefault, (PlanID): 1489674705705 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489746562418::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489746560731) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: PickUp in Plan: Turn

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : succ 
     *
     * Plans in State: 				
     *   - Plan - (Name): WumpusDefault, (PlanID): 1489674671969 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489746558803::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489746557017) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Shoot in Plan: Turn

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : succ 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShootDefault, (PlanID): 1489674687663 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489746560602::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489746558972) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Leave in Plan: Turn

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : succ 
     *
     * Plans in State: 				
     *   - Plan - (Name): LeaveDefault, (PlanID): 1489674658684 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489674153776)
     *
     * States:
     *   - NewState (1489674153775)
     *   - Move (1489674243749)
     *   - PickUp (1489674300902)
     *   - Shoot (1489674354389)
     *   - Leave (1489674390527)
     *   - NewSuccessState (1489746552131)
     *
     * Vars:
     */
    bool TransitionCondition1489746556848::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489746554764) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: Turn

}
