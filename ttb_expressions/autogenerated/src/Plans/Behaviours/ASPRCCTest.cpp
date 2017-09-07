using namespace std;
#include "Plans/Behaviours/ASPRCCTest.h"

/*PROTECTED REGION ID(inccpp1480766583222) ENABLED START*/ //Add additional includes here
#include <TTBWorldModel.h>
#include "actionlib/client/simple_action_client.h"
#include "move_base_msgs/MoveBaseAction.h"
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <asp_commons/ASPQuery.h>
#include "ttb_poi/TTBPointOfInterests.h"
#include "SolverType.h"
#include <asp_commons/IASPSolver.h>
#include <asp_solver/ASPSolver.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1480766583222) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    ASPRCCTest::ASPRCCTest() :
            DomainBehaviour("ASPRCCTest")
    {
        /*PROTECTED REGION ID(con1480766583222) ENABLED START*/ //Add additional options here
        this->query = make_shared < alica::Query > (this->wm->getEngine());
        this->iterationCounter = 0;
        /*PROTECTED REGION END*/
    }
    ASPRCCTest::~ASPRCCTest()
    {
        /*PROTECTED REGION ID(dcon1480766583222) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void ASPRCCTest::run(void* msg)
    {
        /*PROTECTED REGION ID(run1480766583222) ENABLED START*/ //Add additional options here
        if (this->isSuccess())
        {
            return;
        }
        std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
        std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
        cout << /*"ASPNavigation: Measured Solving and Grounding Time: "
         <<*/std::chrono::duration_cast < chrono::nanoseconds > (end - start).count() / 1000000.0 << /*" ms" <<*/endl;
        if (result.size() > 0)
        {
            auto it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec element)
            {   return element.id == 1480766551805;});
            if (it != result.end())
            {
                if (it->variableQueryValues.size() > 0)
                {
//					cout << "ASPNavigation: ASP result found!" << endl;
//					cout << "\tResult contains the predicates: " << endl;
//					cout << "\t\t";
//					for (int i = 0; i < result.size(); i++)
//					{
//						for (int j = 0; j < result.at(i).values.size(); j++)
//						{
//							cout << result.at(i).values.at(j) << " ";
//						}
//					}
//					cout << endl;
//					cout << "\tThe model contains the predicates: " << endl;
//					cout << "\t\t";
//					for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
//					{
//						cout << it->query->getCurrentModels()->at(0).at(i) << " ";
//					}
//					cout << endl;
                }
                else
                {
//					cout << "ASPNavigation: no result found!" << endl;
//					cout << "\tThe model contains the predicates: " << endl;
//					cout << "\t\t";
//					for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
//					{
//						cout << it->query->getCurrentModels()->at(0).at(i) << " ";
//					}
//					cout << endl;
                }
            }
            else
            {
//				cout << "ASPNavigation: no result found!" << endl;
            }

        }
        else
        {
//			cout << "ASPNavigation: no result found!" << endl;
        }
        if (this->iterationCounter == 2)
        {
            this->setSuccess(true);
        }
        this->iterationCounter++;

        /*PROTECTED REGION END*/
    }
    void ASPRCCTest::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1480766583222) ENABLED START*/ //Add additional options here
        query->clearStaticVariables();
        query->addStaticVariable(getVariablesByName("TestVar"));
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1480766583222) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
