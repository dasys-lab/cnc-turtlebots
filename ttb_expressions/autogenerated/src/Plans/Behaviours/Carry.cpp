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
    	 this->query = make_shared < alica::ConstraintQuery > (this->wm->getEngine());
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
    	if(result.size() > 0)
    	{
    		cout << "Carry: ASP result found!" << endl;
    	}
        /*PROTECTED REGION END*/
    }
    void Carry::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1468494621581) ENABLED START*/ //Add additional options here
    	query->clearDomainVariables();
    	query->clearStaticVariables();
    	query->addVariable(getVariablesByName("BookPlanVar"));
    	result.clear();
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1468494621581) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
