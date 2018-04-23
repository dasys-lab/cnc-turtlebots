#include "Plans/Serve/constraints/PutDown1520511951867Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1520511951867) ENABLED START*/
#include <ttb/wm/TaskManager.h>
#include <ttb/TTBWorldModel.h>

#include <ttb_msgs/ServeTask.h>

#include <alica/reasoner/DummyTerm.h>
#include <alica/reasoner/DummyVariable.h>

#include <engine/constraintmodul/ProblemDescriptor.h>
#include <engine/constraintmodul/SolverTerm.h>
#include <engine/constraintmodul/SolverVariable.h>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:PutDown

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
     * Static Variables: [x, y, z, entity]
     * Domain Variables:

     */
    void Constraint1520850075314::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1520850075314) ENABLED START*/
        auto wm = ttb::TTBWorldModel::get();
        auto currentTask = wm->taskManager.getNextTask();
        if (!currentTask || currentTask->getInformation().type != ttb_msgs::ServeTask::PUT_DOWN)
        {
            // current task is not for picking up an object, so don't specify any problem descriptor
            auto constraint = std::make_shared<alica::reasoner::DummyTerm>();
            for (auto var : *c->getStaticVars())
            {
                auto dummyVar = std::dynamic_pointer_cast<alica::reasoner::DummyVariable>(var);
                if (dummyVar)
                {
                    constraint->setVariable(dummyVar, alica::reasoner::DummyVariable::NO_VALUE);
                }
            }
            c->setConstraint(dynamic_pointer_cast<alica::SolverTerm>(constraint));
            return;
        }

        auto constraint = std::make_shared<alica::reasoner::DummyTerm>();
        auto dummyXVar = std::dynamic_pointer_cast < alica::reasoner::DummyVariable > (c->getStaticVars()->at(0));
        if (dummyXVar)
        {
            auto x = currentTask->getInformation().entityPoint.x;
            constraint->setVariable(dummyXVar, to_string(x));
        }
        else
        {
            std::cerr << "Constraint1520438401434: Variable type of X didn't fit!" << std::endl;
        }
        auto dummyYVar = std::dynamic_pointer_cast < alica::reasoner::DummyVariable > (c->getStaticVars()->at(1));
        if (dummyYVar)
        {
            auto y = currentTask->getInformation().entityPoint.y;
            constraint->setVariable(dummyYVar, to_string(y));
        }
        else
        {
            std::cerr << "Constraint1520438401434: Variable type of Y didn't fit!" << std::endl;
        }
        auto dummyZVar = std::dynamic_pointer_cast < alica::reasoner::DummyVariable > (c->getStaticVars()->at(2));
        if (dummyZVar)
        {
            auto z = currentTask->getInformation().entityPoint.z;
            constraint->setVariable(dummyZVar, to_string(z));
        }
        else
        {
            std::cerr << "Constraint1520438401434: Variable type of z didn't fit!" << std::endl;
        }
        auto dummyEntityVar = std::dynamic_pointer_cast < alica::reasoner::DummyVariable > (c->getStaticVars()->at(3));
        if (dummyEntityVar)
        {
            auto entity = currentTask->getInformation().entity;
            constraint->setVariable(dummyEntityVar, entity);
        }
        else
        {
            std::cerr << "Constraint1520438401434: Variable type of Object Entity didn't fit!" << std::endl;
        }
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        /*PROTECTED REGION END*/
    }

// State: DriveToPoint

// State: DriveToPoint

// State: PutDown

// State: PutDown

// State: DriveToFail

// State: DriveToFail

// State: FailedToPlaceObject

// State: FailedToPlaceObject

// State: ObjectPlaced

// State: ObjectPlaced

}