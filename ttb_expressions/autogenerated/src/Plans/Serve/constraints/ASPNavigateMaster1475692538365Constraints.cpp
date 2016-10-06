#include "Plans/Serve/constraints/ASPNavigateMaster1475692538365Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1475692538365) ENABLED START*/
//Add additional using directives here
#include <alica_asp_solver/Term.h>
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include <memory>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:ASPNavigateMaster

    /*		
     * Tasks: 
     * - EP:1475692538367 : DefaultTask (1414681164704)
     *
     * States:
     * - Navigate (1475692538366)
     * - NewSuccessState (1475752156074)
     *
     * Vars:				
     * - NavMasterVar (1475698052801) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [NavMasterVar]
     * Domain Variables:

     */
    void Constraint1475692986360::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1475692986360) ENABLED START*/
        auto constraint = make_shared<alica::reasoner::Term>();
        constraint->setRule("goalReachable(X) :- reachable(X, Y), goal(X), start(Y), room(X), room(Y).");
        constraint->addFact("goal(r1405B).");
        constraint->addFact("start(r1411).");
        constraint->setBackgroundFileName("distributedSystemsRooms");
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: Navigate

// State: Navigate

// State: NewSuccessState

// State: NewSuccessState

}
