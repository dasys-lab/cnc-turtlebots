using namespace std;
#include "Plans/Behaviours/ASPNavwoExt.h"

/*PROTECTED REGION ID(inccpp1477229760910) ENABLED START*/ //Add additional includes here
#include "SolverType.h"
#include <asp_commons/IASPSolver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <asp_commons/ASPQuery.h>
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1477229760910) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	ASPNavwoExt::ASPNavwoExt() :
			DomainBehaviour("ASPNavwoExt")
	{
		/*PROTECTED REGION ID(con1477229760910) ENABLED START*/ //Add additional options here
		this->query = make_shared<alica::Query>(this->wm->getEngine());
		this->doorConfig = "";
		this->iterationCounter = 0;
		resultfile.open("results2.txt", fstream::app);
		/*PROTECTED REGION END*/
	}
	ASPNavwoExt::~ASPNavwoExt()
	{
		/*PROTECTED REGION ID(dcon1477229760910) ENABLED START*/ //Add additional options here
		resultfile.close();
		/*PROTECTED REGION END*/
	}

	void ASPNavwoExt::run(void* msg)
	{
		/*PROTECTED REGION ID(run1477229760910) ENABLED START*/ //Add additional options here
		if (this->isSuccess())
		{
			return;
		}
		std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
		query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
		std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
		cout << "ASPNavigation: Measured Solving and Grounding Time: "
				<< std::chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000000.0 << " ms" << endl;
		resultfile << (end - start).count() / 1000000.0 << " ";
		if (result.size() > 0)
		{
			auto it = result.end();
			if (this->doorConfig.compare("config1") == 0)
			{
				it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec element)
				{	return element.id == 1477229706852;});
			}
			else if (this->doorConfig.compare("config2") == 0)
			{
				it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec element)
				{	return element.id == 1477229712321;});
			}
			else
			{
				cout << "ASPNavwoExt: wrong config" << endl;
			}
			if (it != result.end())
			{
				if (it->variableQueryValues.size() > 0)
				{
					cout << "ASPNavwoExt: ASP result found!" << endl;
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
					cout << endl;
//                    cout << "\tThe model contains the predicates: " << endl;
//                    cout << "\t\t";
//                    for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
//                    {
//                        cout << it->query->getCurrentModels()->at(0).at(i) << " ";
//                    }
//                    cout << endl;
				}
				else
				{
					cout << "ASPNavwoExt: no result found!" << endl;
//                    cout << "\tThe model contains the predicates: " << endl;
//                    cout << "\t\t";
//                    for (int i = 0; i < it->query->getCurrentModels()->at(0).size(); i++)
//                    {
//                        cout << it->query->getCurrentModels()->at(0).at(i) << " ";
//                    }
//                    cout << endl;
				}
			}
			else
			{
				cout << "ASPNavwoExt: no result found!" << endl;
			}

		}
		else
		{
			cout << "ASPNavwoExt: no result found!" << endl;
		}
		if (iterationCounter == 1)
		{
			this->setSuccess(true);
			if (this->doorConfig.compare("config2") == 0)
			{
				resultfile << endl;
			}
			else
			{
				resultfile << flush;
			}
		}
		this->iterationCounter++;

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
			query->addStaticVariable(getVariablesByName("NavVar1"));
		}
		else
		{
			query->addStaticVariable(getVariablesByName("NavVar2"));
		}
		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1477229760910) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
