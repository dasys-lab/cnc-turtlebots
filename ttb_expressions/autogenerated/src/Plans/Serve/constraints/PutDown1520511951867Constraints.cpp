#include "Plans/Serve/constraints/PutDown1520511951867Constraints.h"
/*PROTECTED REGION ID(ch1520511951867) ENABLED START*/
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/TaskManager.h>

#include <ttb_msgs/ServeTask.h>

#include <alica/reasoner/SimpleTerm.h>
#include <alica/reasoner/SimpleVariable.h>

#include <engine/constraintmodul/ProblemDescriptor.h>
#include <alica_solver_interface/SolverTerm.h>
#include <alica_solver_interface/SolverVariable.h>
/*PROTECTED REGION END*/

using std::cout;
using std::exception;
using std::make_shared;
using namespace alica;

namespace alicaAutogenerated
{
// Plan:PutDown
/*
 * Tasks:
 * - EP:1520511964768 : DefaultTask (1414681164704)
 *
 * States:
 * - DriveToPoint (1520511964767)
 * - PutDown (1520845381633)
 * - DriveToFail (1520849454900)
 * - FailedToPlaceObject (1520849456871)
 * - ObjectPlaced (1520849459774)
 *
 * Vars:
 * - x (1520850749297)
 * - y (1520850749534)
 * - entity (1520850764148)
 * - z (1520872574322)
 */
/*
 * RuntimeCondition - (Name): NewRuntimeCondition
 * (ConditionString):
 * Static Variables: x y z entity
 * Domain Variables:
 *
 */
void Constraint1520850075314::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1520850075314) ENABLED START*/
    auto wm = ttb::TTBWorldModel::get();
    auto currentTask = wm->taskManager.getNextTask();
    if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PUT_DOWN) {
        // current task is not for picking up an object, so don't specify any problem descriptor
        auto constraint = new alica::reasoner::SimpleTerm();
        for (auto var : c->getStaticVars()) {
            auto SimpleVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(var);
            if (SimpleVar) {
                constraint->setVariable(SimpleVar, alica::reasoner::SimpleVariable::NO_VALUE);
            }
        }
        c->setConstraint(constraint);
        return;
    }

    auto constraint = new alica::reasoner::SimpleTerm();
    auto SimpleXVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(c->getStaticVars().at(0));
    if (SimpleXVar) {
        auto x = currentTask->getInformation().entityPoint.x;
        constraint->setVariable(SimpleXVar, std::to_string(x));
    } else {
        std::cerr << "Constraint1520438401434: Variable type of X didn't fit!" << std::endl;
    }
    auto SimpleYVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(c->getStaticVars().at(1));
    if (SimpleYVar) {
        auto y = currentTask->getInformation().entityPoint.y;
        constraint->setVariable(SimpleYVar, std::to_string(y));
    } else {
        std::cerr << "Constraint1520438401434: Variable type of Y didn't fit!" << std::endl;
    }
    auto SimpleZVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(c->getStaticVars().at(2));
    if (SimpleZVar) {
        auto z = currentTask->getInformation().entityPoint.z;
        constraint->setVariable(SimpleZVar, std::to_string(z));
    } else {
        std::cerr << "Constraint1520438401434: Variable type of z didn't fit!" << std::endl;
    }
    auto SimpleEntityVar = reinterpret_cast<alica::reasoner::SimpleVariable*>(c->getStaticVars().at(3));
    if (SimpleEntityVar) {
        auto entity = currentTask->getInformation().entity;
        constraint->setVariable(SimpleEntityVar, entity);
    } else {
        std::cerr << "Constraint1520438401434: Variable type of Object Entity didn't fit!" << std::endl;
    }
    c->setConstraint(constraint);
    /*PROTECTED REGION END*/
}

// State: DriveToPoint
// State: PutDown
// State: DriveToFail
// State: FailedToPlaceObject
// State: ObjectPlaced
} // namespace alicaAutogenerated
