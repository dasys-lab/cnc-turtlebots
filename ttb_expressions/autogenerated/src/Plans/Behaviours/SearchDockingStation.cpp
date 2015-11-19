using namespace std;
#include "Plans/Behaviours/SearchDockingStation.h"

/*PROTECTED REGION ID(inccpp1414681429307) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1414681429307) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    SearchDockingStation::SearchDockingStation() :
            DomainBehaviour("SearchDockingStation")
    {
        /*PROTECTED REGION ID(con1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    SearchDockingStation::~SearchDockingStation()
    {
        /*PROTECTED REGION ID(dcon1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void SearchDockingStation::run(void* msg)
    {
        /*PROTECTED REGION ID(run1414681429307) ENABLED START*/ //Add additional options here
        auto odom = wm->rawSensorData.getOwnOdom();
        auto core = wm->rawSensorData.getOwnMobileBaseSensorState();
        auto infrRedDock = wm->rawSensorData.getOwnDockInfrRed();

        if ((int)core->charger == 0)
        {

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
            this->success = true;
        }

        /*PROTECTED REGION END*/
    }
    void SearchDockingStation::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1414681429307) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1414681429307) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
