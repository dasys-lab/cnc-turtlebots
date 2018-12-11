#include "Plans/Behaviours/ASPMinimizePath.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1477125924367) ENABLED START*/
// Add additional includes here
#include <reasoner/asp/Query.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <ttb/TTBWorldModel.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1477125924367) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

ASPMinimizePath::ASPMinimizePath()
        : DomainBehaviour("ASPMinimizePath")
{
    /*PROTECTED REGION ID(con1477125924367) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    /*PROTECTED REGION END*/
}
ASPMinimizePath::~ASPMinimizePath()
{
    /*PROTECTED REGION ID(dcon1477125924367) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void ASPMinimizePath::run(void* msg)
{
    /*PROTECTED REGION ID(run1477125924367) ENABLED START*/
    // Add additional options here
    if (this->isSuccess()) {
        return;
    }
    auto start = std::chrono::high_resolution_clock::now();
    query->getSolution<alica::reasoner::ASPSolverWrapper, ::reasoner::asp::AnnotatedValVec*>(this->getPlanContext(), result);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "ASPMinimizePath: Measured Solving and Grounding Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    if (result.size() > 0) {
        auto it = find_if(result.begin(), result.end(), [](::reasoner::asp::AnnotatedValVec* element) { return element->id == 1477125906086; });
        if (it != result.end()) {
            if ((*it)->variableQueryValues.size() > 0) {
                std::cout << "ASPMinimizePath: ASP result found!" << std::endl;
                std::cout << "\tResult contains the predicates: " << std::endl;
                std::cout << "\t\t";
                for (size_t i = 0; i < result.size(); i++) {
                    for (size_t j = 0; j < result.at(i)->variableQueryValues.size(); j++) {
                        for (size_t k = 0; k < result.at(i)->variableQueryValues.at(j).size(); k++) {
                            std::cout << result.at(i)->variableQueryValues.at(j).at(k) << " ";
                        }
                    }
                }
                std::cout << "\tThe model contains the predicates: " << std::endl;
                std::cout << "\t\t";
                for (size_t i = 0; i < (*it)->query->getCurrentModels()->at(0).size(); i++) {
                    std::cout << (*it)->query->getCurrentModels()->at(0).at(i) << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "ASPMinimizePath: no result found!" << std::endl;
                std::cout << "\tThe model contains the predicates: " << std::endl;
                std::cout << "\t\t";
                for (size_t i = 0; i < (*it)->query->getCurrentModels()->at(0).size(); i++) {
                    std::cout << (*it)->query->getCurrentModels()->at(0).at(i) << " ";
                }
                std::cout << std::endl;
            }
        } else {
            std::cout << "ASPNavigation: no result found!" << std::endl;
        }
    } else {
        std::cout << "ASPNavigation: no result found!" << std::endl;
    }
    this->setSuccess();
    /*PROTECTED REGION END*/
}
void ASPMinimizePath::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1477125924367) ENABLED START*/
    // Add additional options here
    query->clearStaticVariables();
    query->addStaticVariable(getVariable("MinVar"));
    result.clear();

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1477125924367) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
