using namespace std;
#include "Plans/Behaviours/ASPNavigation.h"

/*PROTECTED REGION ID(inccpp1475693360605) ENABLED START*/ //Add additional includes here
#include <TTBWorldModel.h>
#include "SolverType.h"
#include "actionlib/client/simple_action_client.h"
#include "move_base_msgs/MoveBaseAction.h"
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1475693360605) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	ASPNavigation::ASPNavigation() :
			DomainBehaviour("ASPNavigation")
	{
		/*PROTECTED REGION ID(con1475693360605) ENABLED START*/ //Add additional options here
		this->query = make_shared<alica::ConstraintQuery>(this->wm->getEngine());
		this->openDoors = false;
		this->iterationCounter = 0;
		/*PROTECTED REGION END*/
	}
	ASPNavigation::~ASPNavigation()
	{
		/*PROTECTED REGION ID(dcon1475693360605) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void ASPNavigation::run(void* msg)
	{
		/*PROTECTED REGION ID(run1475693360605) ENABLED START*/ //Add additional options here
		if (this->iterationCounter == 0)
		{
			this->wm->doors.openDoor("doorClosed(r1411, studentArea)");
			this->wm->doors.openDoor("doorClosed(r1411C, studentArea)");
			this->wm->doors.openDoor("doorClosed(r1411, r1411C)");
			this->wm->doors.openDoor("doorClosed(studentArea, mainHallA)");
			this->wm->doors.openDoor("doorClosed(mainHallB, utility)");
			this->wm->doors.openDoor("doorClosed(r1405B, utility)");
			this->wm->doors.openDoor("doorClosed(mainHallA, mainHallB)");
		}
		if (this->iterationCounter == 5)
		{
			this->wm->doors.closeDoor("doorClosed(mainHallA, mainHallB)");
		}

//        this->wm->doors.openDoor("doorClosed(mainHallA, offices)");
//        this->wm->doors.openDoor("doorClosed(offices, utility)");

		std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
		query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
		std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
		cout << "ASPNavigation: Measured Solving and Grounding Time: "
				<< std::chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
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
		if (this->iterationCounter >= 10)
		{
			this->setSuccess(true);
		}
		this->iterationCounter++;

		/*PROTECTED REGION END*/
	}
	void ASPNavigation::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1475693360605) ENABLED START*/ //Add additional options here
		query->clearStaticVariables();
		query->addVariable(getVariablesByName("NavVar"));
		result.clear();
		bool success = true;
		string tmp = "";
		try
		{
			success &= getParameter("openDoors", tmp);
		}

		catch (exception& e)
		{
			cerr << "Could not cast the parameter properly" << endl;
		}
		if (!success)
		{
			cerr << "ASP: Parameter does not exist" << endl;
		}
		std::istringstream is(tmp);
		is >> std::boolalpha >> this->openDoors;
		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1475693360605) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
