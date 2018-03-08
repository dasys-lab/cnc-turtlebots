using namespace std;
#include "Plans/Behaviours/ASPMinimizePath.h"

/*PROTECTED REGION ID(inccpp1477125924367) ENABLED START*/ //Add additional includes here
#include <ttb/TTBWorldModel.h>
#include <SolverType.h>
#include <asp_commons/ASPQuery.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1477125924367) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    ASPMinimizePath::ASPMinimizePath() :
            DomainBehaviour("ASPMinimizePath")
    {
        /*PROTECTED REGION ID(con1477125924367) ENABLED START*/ //Add additional options here
        this->query = std::make_shared < alica::Query > (this->wm->getEngine());
        /*PROTECTED REGION END*/
    }
    ASPMinimizePath::~ASPMinimizePath()
    {
        /*PROTECTED REGION ID(dcon1477125924367) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void ASPMinimizePath::run(void* msg)
    {
        /*PROTECTED REGION ID(run1477125924367) ENABLED START*/ //Add additional options here
        if (this->isSuccess())
        {
            return;
        }
        auto start = std::chrono::high_resolution_clock::now();
        query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
        auto end = std::chrono::high_resolution_clock::now();
        cout << "ASPMinimizePath: Measured Solving and Grounding Time: " << std::chrono::duration_cast
                < chrono::milliseconds > (end - start).count() << " ms" << endl;
        if (result.size() > 0)
        {
            auto it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec element)
            {   return element.id == 1477125906086;});
            if (it != result.end())
            {
                if (it->variableQueryValues.size() > 0)
                {
                    cout << "ASPMinimizePath: ASP result found!" << endl;
                    cout << "\tResult contains the predicates: " << endl;
                    cout << "\t\t";
                    for (int i = 0; i < result.size(); i++)
                    {
                        for (int j = 0; j < result.at(i).variableQueryValues.size(); j++)
                        {
                            for (int k = 0; k < result.at(i).variableQueryValues.at(j).size(); k++)
                            {
                                cout << result.at(i).variableQueryValues.at(j).at(k) << " ";
                            }
                        }
                    }
                    cout << "\tThe model contains the predicates: " << endl;
                    cout << "\t\t";
                    for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
                    {
                        cout << it->query->getCurrentModels()->at(0).at(i) << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "ASPMinimizePath: no result found!" << endl;
                    cout << "\tThe model contains the predicates: " << endl;
                    cout << "\t\t";
                    for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
                    {
                        cout << it->query->getCurrentModels()->at(0).at(i) << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "ASPNavigation: no result found!" << endl;
            }

        }
        else
        {
            cout << "ASPNavigation: no result found!" << endl;
        }
        this->setSuccess(true);
        /*PROTECTED REGION END*/
    }
    void ASPMinimizePath::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1477125924367) ENABLED START*/ //Add additional options here
        query->clearStaticVariables();
        query->addStaticVariable(getVariablesByName("MinVar"));
        result.clear();
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1477125924367) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
