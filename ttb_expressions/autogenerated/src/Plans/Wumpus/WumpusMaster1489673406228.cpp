#include "Plans/Wumpus/WumpusMaster1489673406228.h"
using namespace alica;
/*PROTECTED REGION ID(eph1489673406228) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:WumpusMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1489673406230

     */
    shared_ptr<UtilityFunction> UtilityFunction1489673406228::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1489673406228) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: WumpusMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Spawn Agent Message Received 
     *
     * Plans in State: 				
     *   - Plan - (Name): SpawnAgentDefault, (PlanID): 1489673543981 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489673406230)
     *
     * States:
     *   - Stop (1489673406229)
     *   - Play (1489673551929)
     *   - AgentDead (1489673616222)
     *   - AgentLeftCave (1489673668786)
     *
     * Vars:
     */
    bool TransitionCondition1489673564931::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489673563202) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Play in Plan: WumpusMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Agent is Dead 
     *
     * Plans in State: 				
     *   - Plan - (Name): InteractWIthPlayground, (PlanID): 1489673751539 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489673406230)
     *
     * States:
     *   - Stop (1489673406229)
     *   - Play (1489673551929)
     *   - AgentDead (1489673616222)
     *   - AgentLeftCave (1489673668786)
     *
     * Vars:
     */
    bool TransitionCondition1489673638984::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489673632039) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Agent left with gold 
     *
     * Plans in State: 				
     *   - Plan - (Name): InteractWIthPlayground, (PlanID): 1489673751539 
     *
     * Tasks: 
     *   - DefaultTask (1414681164704) (Entrypoint: 1489673406230)
     *
     * States:
     *   - Stop (1489673406229)
     *   - Play (1489673551929)
     *   - AgentDead (1489673616222)
     *   - AgentLeftCave (1489673668786)
     *
     * Vars:
     */
    bool TransitionCondition1489673686543::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1489673685018) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

//State: AgentDead in Plan: WumpusMaster

//State: AgentLeftCave in Plan: WumpusMaster

}
