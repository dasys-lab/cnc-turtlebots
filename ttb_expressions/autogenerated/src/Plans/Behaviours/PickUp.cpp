using namespace std;
#include "Plans/Behaviours/PickUp.h"

/*PROTECTED REGION ID(inccpp1520438451345) ENABLED START*/ // Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1520438451345) ENABLED START*/ // initialise static variables here
    /*PROTECTED REGION END*/
    PickUp::PickUp() :
            DomainBehaviour("PickUp")
    {
        /*PROTECTED REGION ID(con1520438451345) ENABLED START*/ // Add additional options her
        this->query = std::make_shared < alica::Query > (this->wm->getEngine());
        this->isGrabbing = false;
        /*PROTECTED REGION END*/
    }
    PickUp::~PickUp()
    {
        /*PROTECTED REGION ID(dcon1520438451345) ENABLED START*/ // Add additional options here
        /*PROTECTED REGION END*/
    }
    void PickUp::run(void* msg)
    {
        /*PROTECTED REGION ID(run1520438451345) ENABLED START*/ // Add additional options here
        result.clear();
        if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
        {
            std::cout << "PickUp: Unable to get solution for variable: "
                    << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << std::endl;
            return;
        }

        std::cout << "PickUp: Solution for variable: "
                << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
                << std::endl;

        auto object = this->wm->logicalCameraData.getObject(result[0]);
        if (!object)
        {
            this->setFailure(true);
            return;
        }
        if (!this->isGrabbing)
        {
            this->isGrabbing = this->turtleBot->simulatedArm->grabObject(result[0]);
        }
        if (!this->isGrabbing)
        {
            this->setFailure(true);
            return;
        }
        auto armState = this->turtleBot->simulatedArm->getArmState();
        if (armState == ttb::robot::SimulatedArm::ArmState::waiting)
        {
            return;
        }
        else if (armState == ttb::robot::SimulatedArm::ArmState::pickUpFailed)
        {
            this->setFailure(true);
        }
        else
        {
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void PickUp::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1520438451345) ENABLED START*/ // Add additional options here
        this->isGrabbing = false;
        this->query->clearStaticVariables();
        this->result.clear();
        this->query->addStaticVariable(getVariablesByName("entity"));
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1520438451345) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
