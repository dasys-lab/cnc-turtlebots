#include "Plans/Serve/ASPRCCTestMaster1480766525772.h"
using namespace alica;
/*PROTECTED REGION ID(eph1480766525772) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ASPRCCTestMaster

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- PlanVar (1480766663869)
     */
    bool RunTimeCondition1480766551805::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1480766551805) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1480766525774

     */
    shared_ptr<UtilityFunction> UtilityFunction1480766525772::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1480766525772) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: NewState in Plan: ASPRCCTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): ASPRCCTestDefault, (PlanID): 1480766599215 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1480766525774)
     *
     * States:
     *   - NewState (1480766525773)
     *   - Succ (1480766535708)
     *
     * Vars:
     */
    bool TransitionCondition1480766547208::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1480766545779) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: Succ in Plan: ASPRCCTestMaster

}
