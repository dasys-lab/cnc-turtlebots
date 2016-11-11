using namespace std;
#include "Plans/Behaviours/ASPNavwoExt.h"

/*PROTECTED REGION ID(inccpp1477229760910) ENABLED START*/ //Add additional includes here
#include "SolverType.h"
#include <alica_asp_solver/ASPSolver.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1477229760910) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    ASPNavwoExt::ASPNavwoExt() :
            DomainBehaviour("ASPNavwoExt")
    {
        /*PROTECTED REGION ID(con1477229760910) ENABLED START*/ //Add additional options here
        this->query = make_shared < alica::Query > (this->wm->getEngine());
        this->doorConfig = "";
        this->iterationCounter = 0;
        /*PROTECTED REGION END*/
    }
    ASPNavwoExt::~ASPNavwoExt()
    {
        /*PROTECTED REGION ID(dcon1477229760910) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void ASPNavwoExt::run(void* msg)
    {
        /*PROTECTED REGION ID(run1477229760910) ENABLED START*/ //Add additional options here
        this->iterationCounter++;
        alica::reasoner::ASPSolver* aspSolver =
                dynamic_cast<alica::reasoner::ASPSolver*>(this->wm->getEngine()->getSolver(SolverType::ASPSOLVER));
        std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
//		if (this->doorConfig.compare("config1") == 0 && this->iterationCounter == 1)
//		{
//			aspSolver->ground( { {"distributedSystemsRooms1", {}}}, nullptr);
//		}
//		else if(this->doorConfig.compare("config2") == 0 && this->iterationCounter == 1)
//		{
//			aspSolver->ground( { {"distributedSystemsRooms2", {}}}, nullptr);
//		}
        query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
        std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
        cout << "ASPNavigation: Measured Solving and Grounding Time: " << std::chrono::duration_cast
                < chrono::milliseconds > (end - start).count() << " ms" << endl;
        if (result.size() > 0 && result.at(0).size() > 0)
        {
            cout << "ASPNavigation: ASP result found!" << endl;
            //            cout << "\tResult contains the predicates: " << endl;
            //            cout << "\t\t";
            //            for (int i = 0; i < result.size(); i++)
            //            {
            //                for (int j = 0; j < result.at(i).size(); j++)
            //                {
            //                    cout << result.at(i).at(j) << " ";
            //                }
            //            }
            //            cout << endl;

        }
        else
        {
            cout << "ASPNavigation: no result found!" << endl;
        }
        if (this->iterationCounter >= 5)
        {
            this->setSuccess(true);
        }

        /*PROTECTED REGION END*/
    }
    void ASPNavwoExt::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1477229760910) ENABLED START*/ //Add additional options here
        query->clearStaticVariables();
        result.clear();
        bool success = true;
        string tmp = "";
        try
        {
            success &= getParameter("doorConfig", this->doorConfig);
        }

        catch (exception& e)
        {
            cerr << "Could not cast the parameter properly" << endl;
        }
        if (!success)
        {
            cerr << "ASP: Parameter does not exist" << endl;
        }
        if (this->doorConfig.compare("config1") == 0)
        {
            query->addVariable(getVariablesByName("NavVar1"));
        }
        else
        {
            query->addVariable(getVariablesByName("NavVar2"));
        }
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1477229760910) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
