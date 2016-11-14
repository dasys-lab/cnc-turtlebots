#include "Plans/Serve/constraints/ASPNavwoExternals1477229620130Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1477229620130) ENABLED START*/
//Add additional using directives here
#include <alica_asp_solver/ASPTerm.h>
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include <memory>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:ASPNavwoExternals

    /*		
     * Tasks: 
     * - EP:1477229620132 : DefaultTask (1414681164704)
     *
     * States:
     * - Nav1 (1477229620131)
     * - InnerState (1477229628161)
     * - NewSuccessState (1477229672639)
     *
     * Vars:				
     * - PlanVar1 (1477229962547) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [PlanVar1]
     * Domain Variables:

     */
    void Constraint1477229706852::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1477229706852) ENABLED START*/
        auto constraint = make_shared<alica::reasoner::ASPTerm>();
        constraint->setRule(
                "goalReachable(X, 1) :- reachable(X, Y, 1), goal(X, 1), start(Y, 1), room(X, 1), room(Y, 1).");
        constraint->addFact("goal(r1405B, 1).");
        constraint->addFact("start(r1411, 1).");
        constraint->setProgramSection("distributedSystemsRooms1");
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: Nav1

// State: Nav1

// State: InnerState

// State: InnerState

// State: NewSuccessState

// State: NewSuccessState

}
