#include "Plans/Behaviours/Carry.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1468494621581) ENABLED START*/
// Add additional includes here
#include <ttb/TTBWorldModel.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1468494621581) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

Carry::Carry()
        : DomainBehaviour("Carry")
{
    /*PROTECTED REGION ID(con1468494621581) ENABLED START*/
    // Add additional options here
    this->query = std::make_shared<alica::Query>();
    /*PROTECTED REGION END*/
}
Carry::~Carry()
{
    /*PROTECTED REGION ID(dcon1468494621581) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void Carry::run(void* msg)
{
    /*PROTECTED REGION ID(run1468494621581) ENABLED START*/
    // Add additional options here
    query->getSolution<alica::reasoner::ASPSolverWrapper, ::reasoner::AnnotatedValVec*>(this->getPlanContext(), result);
    if (result.size() > 0) {
        auto it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec* element) { return element->id == 1468495216221; });
        if (it != result.end()) {
            if ((*it)->variableQueryValues.size() > 0) {
                std::cout << "Carry: ASP result found!" << std::endl;
                std::cout << "\tResult contains the predicates: " << std::endl;
                std::cout << "\t\t";
                for (size_t i = 0; i < result.size(); i++) {
                    for (size_t j = 0; j < result.at(i)->variableQueryValues.size(); j++) {
                        for (size_t k = 0; k < result.at(i)->variableQueryValues.at(j).size(); k++) {
                            std::cout << result.at(i)->variableQueryValues.at(j).at(k) << " ";
                        }
                    }
                }
            } else {
                std::cout << "Carry: no result found!" << std::endl;
            }
        } else {
            std::cout << "Carry: no result found!" << std::endl;
        }
    } else {
        std::cout << "Result size == 0" << std::endl;
    }
    auto satisfied = query->existsSolution<alica::reasoner::ASPSolverWrapper>(this->getPlanContext());
    if (satisfied) {
        std::cout << "Carry: query is satisfied!" << std::endl;
        this->setSuccess();
    } else {
        std::cout << "Carry: query isn't satisfied!" << std::endl;
    }
    /*PROTECTED REGION END*/
}
void Carry::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1468494621581) ENABLED START*/
    // Add additional options here
    query->clearStaticVariables();
    query->addStaticVariable(getVariable("CarryVar"));
    result.clear();

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1468494621581) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
