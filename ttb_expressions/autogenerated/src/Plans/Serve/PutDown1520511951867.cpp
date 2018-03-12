#include "Plans/Serve/PutDown1520511951867.h"
using namespace alica;
/*PROTECTED REGION ID(eph1520511951867) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:PutDown

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- x (1520850749297)
     *	- y (1520850749534)
     *	- entity (1520850764148)
     *	- z (1520872574322)
     */
    bool RunTimeCondition1520850075314::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520850075314) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1520511964768

     */
    shared_ptr<UtilityFunction> UtilityFunction1520511951867::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1520511951867) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DriveToPoint in Plan: PutDown

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Arrived at point 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPointDefault, (PlanID): 1520850827610 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1520511964768)
     *
     * States:
     *   - DriveToPoint (1520511964767)
     *   - PutDown (1520845381633)
     *   - DriveToFail (1520849454900)
     *   - FailedToPlaceObject (1520849456871)
     *   - ObjectPlaced (1520849459774)
     *
     * Vars:
     */
    bool TransitionCondition1520849450688::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520849449636) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : failed to drive to point 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPointDefault, (PlanID): 1520850827610 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1520511964768)
     *
     * States:
     *   - DriveToPoint (1520511964767)
     *   - PutDown (1520845381633)
     *   - DriveToFail (1520849454900)
     *   - FailedToPlaceObject (1520849456871)
     *   - ObjectPlaced (1520849459774)
     *
     * Vars:
     */
    bool TransitionCondition1520849521568::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520849520077) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    //State: PutDown in Plan: PutDown

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : PutDown to DriveToPoint 
     *
     * Plans in State: 				
     *   - Plan - (Name): PutDownDefault, (PlanID): 1520850807590 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1520511964768)
     *
     * States:
     *   - DriveToPoint (1520511964767)
     *   - PutDown (1520845381633)
     *   - DriveToFail (1520849454900)
     *   - FailedToPlaceObject (1520849456871)
     *   - ObjectPlaced (1520849459774)
     *
     * Vars:
     */
    bool TransitionCondition1520849451727::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520849450854) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Failed putting down 
     *
     * Plans in State: 				
     *   - Plan - (Name): PutDownDefault, (PlanID): 1520850807590 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1520511964768)
     *
     * States:
     *   - DriveToPoint (1520511964767)
     *   - PutDown (1520845381633)
     *   - DriveToFail (1520849454900)
     *   - FailedToPlaceObject (1520849456871)
     *   - ObjectPlaced (1520849459774)
     *
     * Vars:
     */
    bool TransitionCondition1520849523765::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520849521816) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Putting down Successful 
     *
     * Plans in State: 				
     *   - Plan - (Name): PutDownDefault, (PlanID): 1520850807590 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1520511964768)
     *
     * States:
     *   - DriveToPoint (1520511964767)
     *   - PutDown (1520845381633)
     *   - DriveToFail (1520849454900)
     *   - FailedToPlaceObject (1520849456871)
     *   - ObjectPlaced (1520849459774)
     *
     * Vars:
     */
    bool TransitionCondition1520849525667::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1520849523989) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: DriveToFail in Plan: PutDown

//State: FailedToPlaceObject in Plan: PutDown

//State: ObjectPlaced in Plan: PutDown

}
