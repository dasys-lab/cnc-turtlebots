#include "Plans/Behaviours/ASPRCCTest.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1480766583222) ENABLED START*/
// Add additional includes here
#include <ttb/TTBWorldModel.h>

#include <asp_commons/ASPQuery.h>
#include <asp_commons/AnnotatedValVec.h>
#include <asp_commons/IASPSolver.h>
#include <asp_solver/ASPSolver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1480766583222) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

ASPRCCTest::ASPRCCTest()
        : DomainBehaviour("ASPRCCTest")
{
    /*PROTECTED REGION ID(con1480766583222) ENABLED START*/
    // Add additional options here
    this->query = make_shared<alica::Query>();
    this->iterationCounter = 0;
    resultfile.open("results_rcctest.txt", fstream::app);
    /*PROTECTED REGION END*/
}
ASPRCCTest::~ASPRCCTest()
{
    /*PROTECTED REGION ID(dcon1480766583222) ENABLED START*/
    // Add additional options here
    resultfile.close();
    /*PROTECTED REGION END*/
}
void ASPRCCTest::run(void* msg)
{
    /*PROTECTED REGION ID(run1480766583222) ENABLED START*/
    // Add additional options here
    if (this->isSuccess()) {
        return;
    }
    if (this->iterationCounter % 2 == 0) {
        auto s = this->wm->getEngine()->getSolver<reasoner::ASPSolverWrapper>();
        delete s;
        auto ae = this->wm->getEngine();
        std::vector<char const*> args{"clingo", nullptr};
        auto solver = new ::reasoner::ASPSolver(args);
        auto solverWrapper = new alica::reasoner::ASPSolverWrapper(ae, args);
        solverWrapper->init(solver);
        ae->addSolver<reasoner::ASPSolverWrapper>(solverWrapper);
    }
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    query->getSolution<alica::reasoner::ASPSolverWrapper, ::reasoner::AnnotatedValVec*>(this->getPlanContext(), result);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    cout << "ASPNavigation: Measured Solving and Grounding Time: " << std::chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000000.0
         << /*" ms" <<*/ endl;
    resultfile << (end - start).count() / 1000000.0 << " ";
    if (result.size() > 0) {
        auto it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec* element) { return element->id == 1480766551805; });
        if (it != result.end()) {
            if ((*it)->variableQueryValues.size() > 0) {
                cout << "ASPNavigation: ASP result found!" << endl;
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
                //					for (int i = 0; i < it->query->getCurrentModels()->at(0).size();
                // i++)
                //					{
                //						cout << it->query->getCurrentModels()->at(0).at(i) << "
                //";
                //					}
                //					cout << endl;
            } else {
                //					cout << "ASPNavigation: no result found!" << endl;
                //					cout << "\tThe model contains the predicates: " << endl;
                //					cout << "\t\t";
                //					for (int i = 0; i < it->query->getCurrentModels()->at(0).size();
                // i++)
                //					{
                //						cout << it->query->getCurrentModels()->at(0).at(i) << "
                //";
                //					}
                //					cout << endl;
            }
        } else {
            //				cout << "ASPNavigation: no result found!" << endl;
        }
    } else {
        //			cout << "ASPNavigation: no result found!" << endl;
    }
    if (this->iterationCounter % 2 == 1) {
        resultfile << endl;
    }
    if (this->iterationCounter == 19) {
        this->setSuccess();
        cout << "DONE" << endl;
    }
    this->iterationCounter++;

    /*PROTECTED REGION END*/
}
void ASPRCCTest::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1480766583222) ENABLED START*/
    // Add additional options here
    query->clearStaticVariables();
    query->addStaticVariable(getVariable("TestVar"));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1480766583222) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
