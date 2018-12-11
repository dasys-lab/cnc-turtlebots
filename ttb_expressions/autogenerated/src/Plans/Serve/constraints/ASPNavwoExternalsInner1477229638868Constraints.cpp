#include "Plans/Serve/constraints/ASPNavwoExternalsInner1477229638868Constraints.h"
/*PROTECTED REGION ID(ch1477229638868) ENABLED START*/
// Add additional using directives here
#include <ttb/TTBWorldModel.h>

#include <reasoner/asp/Enums.h>
#include <reasoner/asp/Solver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <asp_solver_wrapper/ASPTerm.h>

#include <engine/AlicaEngine.h>
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <alica_solver_interface/SolverTerm.h>
#include <memory>
/*PROTECTED REGION END*/

using std::cout;
using std::exception;
using std::make_shared;
using namespace alica;

namespace alicaAutogenerated
{
// Plan:ASPNavwoExternalsInner
/*
 * Tasks:
 * - EP:1477229659175 : DefaultTask (1414681164704)
 *
 * States:
 * - Nav2 (1477229659174)
 * - NewSuccessState (1479298294756)
 *
 * Vars:
 * - PlanVar2 (1477229909334)
 */
/*
 * RuntimeCondition - (Name): NewRuntimeCondition
 * (ConditionString):
 * Static Variables: PlanVar2
 * Domain Variables:
 *
 */
void Constraint1477229712321::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1477229712321) ENABLED START*/
    ttb::TTBWorldModel* wm = ttb::TTBWorldModel::get();
    auto constraint = new alica::reasoner::ASPTerm(-1);
    auto queryId = ((alica::reasoner::ASPSolverWrapper*) wm->getEngine()->getSolver<alica::reasoner::ASPSolverWrapper>())->getQueryCounter();
    constraint->setQueryId(queryId);
    std::stringstream ss;
    ss << "goalReachable(X, 2) :- reachable(X, Y, 2), goal(X, 2), start(Y, 2), room(X, 2), room(Y, 2).";
    constraint->setQueryRule(ss.str());
    ss.str("");
    ss << "goal(r1405B, 2).";
    constraint->addFact(ss.str());
    ss.str("");
    ss << "start(r1411, 2).";
    constraint->addFact(ss.str());
    constraint->setProgramSection("distributedSystemsRooms2");
    constraint->setId(1477229712321);
    constraint->setType(::reasoner::asp::QueryType::Extension);
    c->setConstraint(constraint);
    /*PROTECTED REGION END*/
}

// State: Nav2
// State: NewSuccessState
} // namespace alicaAutogenerated
