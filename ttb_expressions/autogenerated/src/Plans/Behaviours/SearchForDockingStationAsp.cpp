using namespace std;
#include "Plans/Behaviours/SearchForDockingStationAsp.h"

/*PROTECTED REGION ID(inccpp1470041810334) ENABLED START*/ //Add additional includes here
#include <TTBWorldModel.h>
#include "SolverType.h"
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1470041810334) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	SearchForDockingStationAsp::SearchForDockingStationAsp() :
			DomainBehaviour("SearchForDockingStationAsp")
	{
		/*PROTECTED REGION ID(con1470041810334) ENABLED START*/ //Add additional options here
		this->query = make_shared<alica::ConstraintQuery>(this->wm->getEngine());
		/*PROTECTED REGION END*/
	}
	SearchForDockingStationAsp::~SearchForDockingStationAsp()
	{
		/*PROTECTED REGION ID(dcon1470041810334) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void SearchForDockingStationAsp::run(void* msg)
	{
		/*PROTECTED REGION ID(run1470041810334) ENABLED START*/ //Add additional options here
		auto odom = wm->rawSensorData.getOwnOdom();
		auto core = wm->rawSensorData.getOwnMobileBaseSensorState();
		auto infrRedDock = wm->rawSensorData.getOwnDockInfrRed();

		if ((int)core->charger == 0)
		{
			query->getSolution(SolverType::ASPSOLVER, runningPlan, result);
			cout << "getSolion finished" << endl;
			if (result.size() > 0)
			{
				cout << "Carry: ASP result found!" << endl;
				cout << "\tResult contains the predicates: " << endl;
				cout << "\t\t";
				for (int i = 0; i < result.size(); i++)
				{
					for (int j = 0; j < result.at(i).size(); j++)
					{
						cout << result.at(i).at(j) << " ";
					}
				}
				cout << endl;

			}
//			shared_ptr<POI> dockingStation = this->wm->pois.getPOIByID(result.at(0));
			KDL::Rotation rot;
			tf::quaternionMsgToKDL(odom->pose.pose.orientation, rot);

			double r, p, y;
			rot.GetRPY(r, p, y);

			ecl::Pose2D<double> pose;
			pose.x(odom->pose.pose.position.x);
			pose.y(odom->pose.pose.position.y);
			pose.heading(y);

			dock.setMinAbsV(0.08); // 0.07 works ok
			dock.setMinAbsW(0.5);

			dock.update(infrRedDock->data, core->bumper, core->charger, pose);

			geometry_msgs::Twist cmd_vel;
			cmd_vel.linear.x = dock.getVX();
			cmd_vel.angular.z = dock.getWZ();

			send(cmd_vel);
		}
		else
		{
			this->setSuccess(true);
		}

		/*PROTECTED REGION END*/
	}
	void SearchForDockingStationAsp::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1470041810334) ENABLED START*/ //Add additional options here
		query->clearStaticVariables();
		query->addVariable(getVariablesByName("SearchVar"));
		result.clear();
		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1470041810334) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
