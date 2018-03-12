using namespace std;
#include "Plans/Behaviours/PutDown.h"

/*PROTECTED REGION ID(inccpp1520850797525) ENABLED START*/ //Add additional includes here
#include <SolverType.h>
#include <TurtleBot.h>
#include <robot/SimulatedArm.h>
#include <ttb/TTBWorldModel.h>
#include <geometry_msgs/Point.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1520850797525) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    PutDown::PutDown() :
            DomainBehaviour("PutDown")
    {
        /*PROTECTED REGION ID(con1520850797525) ENABLED START*/ //Add additional options here
        this->query = std::make_shared < alica::Query > (this->wm->getEngine());
        this->isPuttingDown = false;
        /*PROTECTED REGION END*/
    }
    PutDown::~PutDown()
    {
        /*PROTECTED REGION ID(dcon1520850797525) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void PutDown::run(void* msg)
    {
        /*PROTECTED REGION ID(run1520850797525) ENABLED START*/ //Add additional options here
        result.clear();
        if (!this->query->getSolution(SolverType::DUMMYSOLVER, runningPlan, result))
        {
            std::cout << "PickUp: Unable to get solution for variable: "
                    << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << std::endl;
            return;
        }

//        std::cout << "PickUp: Solution for variable: "
//                << this->query->getUniqueVariableStore()->getAllRep()[0]->getName() << " is: " << result[0]
//                << std::endl;

        auto object = this->wm->logicalCameraData.getObject(result[2]);
        if (!object)
        {
            this->setFailure(true);
            return;
        }
        if (!this->isPuttingDown)
        {
        	geometry_msgs::Point point;
        	point.x = stod(result[0]);
        	point.y = stod(result[1]);
        	point.z = stod(result[3]);
            this->isPuttingDown = this->turtleBot->simulatedArm->dropObject(result[2], point);
        }
        if (!this->isPuttingDown)
        {
            this->setFailure(true);
            return;
        }
        auto armState = this->turtleBot->simulatedArm->getArmState();
        if (armState == ttb::robot::SimulatedArm::ArmState::waiting)
        {
            return;
        }
        else if (armState == ttb::robot::SimulatedArm::ArmState::failed)
        {
            this->setFailure(true);
        }
        else
        {
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void PutDown::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1520850797525) ENABLED START*/ //Add additional options here
        this->isPuttingDown = false;
        this->query->clearStaticVariables();
        this->result.clear();
        this->query->addStaticVariable(getVariablesByName("x"));
        this->query->addStaticVariable(getVariablesByName("y"));
        this->query->addStaticVariable(getVariablesByName("entity"));
        this->query->addStaticVariable(getVariablesByName("z"));
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1520850797525) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
