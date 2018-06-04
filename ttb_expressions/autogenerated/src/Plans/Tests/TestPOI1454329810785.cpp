#include "Plans/Tests/TestPOI1454329810785.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454329810785) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:TestPOI

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454329810787

     */
    shared_ptr<UtilityFunction> UtilityFunction1454329810785::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454329810785) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: POI1 in Plan: TestPOI

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPOI1, (PlanID): 1454329864420 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454329810787)
     *
     * States:
     *   - POI1 (1454329810786)
     *   - POI2 (1454329828515)
     *   - POI3 (1454329830500)
     *
     * Vars:
     */
    bool TransitionCondition1454329835328::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454329834261) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: POI2 in Plan: TestPOI

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPOI2, (PlanID): 1454329905072 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1454329810787)
     *
     * States:
     *   - POI1 (1454329810786)
     *   - POI2 (1454329828515)
     *   - POI3 (1454329830500)
     *
     * Vars:
     */
    bool TransitionCondition1454329836408::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454329835521) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: POI3 in Plan: TestPOI

}