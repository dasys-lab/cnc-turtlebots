#include "Plans/Behaviours/ASPNavigation.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1475693360605) ENABLED START*/
// Add additional includes here
#include <ttb/TTBWorldModel.h>

#include <reasoner/asp/Query.h>
#include <reasoner/asp/Solver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1475693360605) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

ASPNavigation::ASPNavigation()
        : DomainBehaviour("ASPNavigation")
{
    /*PROTECTED REGION ID(con1475693360605) ENABLED START*/
    // Add additional options here
    this->query = make_shared<alica::Query>();
    this->iterationCounter = 0;
    resultfile.open("results_externals.txt", std::fstream::app);
    /*PROTECTED REGION END*/
}
ASPNavigation::~ASPNavigation()
{
    /*PROTECTED REGION ID(dcon1475693360605) ENABLED START*/
    // Add additional options here
    resultfile.close();
    /*PROTECTED REGION END*/
}
void ASPNavigation::run(void* msg)
{
    /*PROTECTED REGION ID(run1475693360605) ENABLED START*/
    // Add additional options here
    if (this->isSuccess()) {
        return;
    }
    if (this->iterationCounter % 4 == 0) {
        // Reinitialize the Solver of the Engine every Xth iteration.
        auto s = (alica::reasoner::ASPSolverWrapper*) this->getPlanContext().getAlicaEngine()->getSolver<alica::reasoner::ASPSolverWrapper>();
        delete s;
        auto ae = this->getPlanContext().getAlicaEngine();
        auto solver = new ::reasoner::asp::Solver({});
        auto solverWrapper = new alica::reasoner::ASPSolverWrapper(ae, {});
        solverWrapper->init(solver);
        ae->addSolver<alica::reasoner::ASPSolverWrapper>(solverWrapper);
    }
    //		if (this->iterationCounter == 0)
    //		{
    //			cout << "ASPNavigation: grounding navTest" << endl;
    //			solver->loadFileFromConfig("navTest");
    //			solver->ground( { {"navTest", {}}}, nullptr);
    //			auto ext = make_shared<Gringo::Value>(solver->getGringoModule()->parseValue("reachable(r1405B,
    // r1411)"));
    //			solver->getClingo()->assignExternal(*(ext), Gringo::TruthValue::True);
    //			solver->solve();
    //		}
    //		else if (this->iterationCounter == 1)
    //		{
    //			cout << "ASPNavigation: grounding navTest2" << endl;
    //			solver->ground( { {"navTest2", {}}}, nullptr);
    //			auto ext = make_shared<Gringo::Value>(solver->getGringoModule()->parseValue("reachable(r1405B,
    // r1411)"));
    //			solver->getClingo()->assignExternal(*(ext), Gringo::TruthValue::False);
    //			solver->solve();
    //		}
    //		else if (this->iterationCounter == 2)
    //		{
    //			cout << "ASPNavigation: grounding navTest3" << endl;
    //			solver->ground( { {"navTest3", {}}}, nullptr);
    //			auto ext = make_shared<Gringo::Value>(solver->getGringoModule()->parseValue("reachable(r1405B,
    // r1411)"));
    //			solver->getClingo()->assignExternal(*(ext), Gringo::TruthValue::True);
    //			solver->solve();
    //		}
    //		else
    //		{
    //			this->setSuccess(true);
    //		}
    //		auto solver = (alica::reasoner::ASPSolver*)this->wm->getEngine()->getSolver(SolverType::ASPSOLVER);
    //		solver->loadFileFromConfig("bookExample");
    //		solver->getClingo()->ground( { {"bookExample", {}}}, nullptr);
    //		solver->solve();
    //		auto model = solver->getCurrentModels();
    //		auto val1 = Gringo::Value(solver->getGringoModule()->parseValue("test(5)"));
    //		for (int i = 0; i < model.at(0).size(); i++)
    //		{
    //			if (solver->checkMatchValues(&val1, &(model.at(0).at(i))))
    //			{
    //				cout << "match found: " << val1 << " " << model.at(0).at(i) << endl;
    //				break;
    //			}
    //			else
    //			{
    //				cout << model.at(0).at(i);
    //			}
    //		}
    //		cout << endl;
    if (this->isSuccess()) {
        return;
    }
    // TODO fix after adding aps to doors in topological model
    //        if (this->iterationCounter == 0)
    //        {
    //            this->wm->doors.openDoor("doorClosed(r1411, studentArea)");
    //            this->wm->doors.openDoor("doorClosed(r1411C, studentArea)");
    //            this->wm->doors.openDoor("doorClosed(r1411, r1411C)");
    //            this->wm->doors.openDoor("doorClosed(studentArea, mainHallA)");
    //            this->wm->doors.openDoor("doorClosed(mainHallB, utility)");
    //            this->wm->doors.openDoor("doorClosed(r1405B, utility)");
    //            this->wm->doors.closeDoor("doorClosed(mainHallA, mainHallB)");
    //        }
    //        if (this->iterationCounter == 2)
    //        {
    //            this->wm->doors.openDoor("doorClosed(mainHallA, mainHallB)");
    //        }

    //      this->wm->doors.openDoor("doorClosed(mainHallA, offices)");
    //      this->wm->doors.openDoor("doorClosed(offices, utility)");

    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    query->getSolution<alica::reasoner::ASPSolverWrapper, ::reasoner::asp::AnnotatedValVec*>(this->getPlanContext(), result);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::cout << "ASPNavigation: Measured Solving and Grounding Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    if (result.size() > 0) {
        auto it = find_if(result.begin(), result.end(), [](::reasoner::asp::AnnotatedValVec* element) { return element->id == 1475692986360; });
        if (it != result.end()) {
            if ((*it)->variableQueryValues.size() > 0) {
                std::cout << "ASPNavigation: ASP result found!" << std::endl;
                std::cout << "\tResult contains the predicates: " << std::endl;
                std::cout << "\t\t";
                for (size_t i = 0; i < result.size(); i++) {
                    for (size_t j = 0; j < result.at(i)->variableQueryValues.size(); j++) {
                        for (size_t k = 0; k < result.at(i)->variableQueryValues.at(j).size(); k++) {
                            std::cout << result.at(i)->variableQueryValues.at(j).at(k) << " ";
                        }
                    }
                }
                std::cout << std::endl;
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
                //                    cout << "ASPNavigation: no result found!" << endl;
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
            std::cout << "ASPNavigation: no result found!!" << std::endl;
        }
    } else {
        std::cout << "ASPNavigation: no result found!!!" << std::endl;
    }
    if (this->iterationCounter == 3) {
        this->setSuccess();
    }
    this->iterationCounter++;

    /*PROTECTED REGION END*/
}
void ASPNavigation::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1475693360605) ENABLED START*/
    // Add additional options here
    query->clearStaticVariables();
    query->addStaticVariable(getVariable("NavVar"));
    // result.clear(); // <-- this is done in each query->getSolution call

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1475693360605) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
