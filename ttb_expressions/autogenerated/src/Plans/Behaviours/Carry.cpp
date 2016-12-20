using namespace std;
#include "Plans/Behaviours/Carry.h"

/*PROTECTED REGION ID(inccpp1468494621581) ENABLED START*/ //Add additional includes here
#include <TTBWorldModel.h>
#include "SolverType.h"
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1468494621581) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Carry::Carry() :
            DomainBehaviour("Carry")
    {
        /*PROTECTED REGION ID(con1468494621581) ENABLED START*/ //Add additional options here
        this->query = make_shared < alica::Query > (this->wm->getEngine());
        /*PROTECTED REGION END*/
    }
    Carry::~Carry()
    {
        /*PROTECTED REGION ID(dcon1468494621581) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Carry::run(void* msg)
    {
        /*PROTECTED REGION ID(run1468494621581) ENABLED START*/ //Add additional options here
        query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
        if (result.size() > 0)
        {
            auto it = find_if(result.begin(), result.end(), [](alica::reasoner::AnnotatedValVec element)
            {   return element.id == 1468495216221;});
            if (it != result.end())
            {
                if (it->values.size() > 0)
                {
                    cout << "Carry: ASP result found!" << endl;
                    cout << "\tResult contains the predicates: " << endl;
                    cout << "\t\t";
                    for (int i = 0; i < it->values.size(); i++)
                    {
                        cout << it->values.at(i) << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Carry: no result found!" << endl;
                }
            }
            else
            {
                cout << "Carry: no result found!" << endl;
            }
        }
        else
        {
            cout << "Result size == 0" << endl;
        }
        auto satisfied = query->existsSolution(SolverType::ASPSOLVER, runningPlan);
        if (satisfied)
        {
            cout << "Carry: query is satisfied!" << endl;
            this->setSuccess(true);
        }
        else
        {
            cout << "Carry: query isn't satisfied!" << endl;
        }
        /*PROTECTED REGION END*/
    }
    void Carry::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1468494621581) ENABLED START*/ //Add additional options here
        query->clearStaticVariables();
        query->addStaticVariable(getVariablesByName("CarryVar"));
        result.clear();
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1468494621581) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
