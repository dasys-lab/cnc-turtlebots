#include "Plans/Behaviours/SearchForDockingStationAsp.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1470041810334) ENABLED START*/
// Add additional includes here
#include <asp_commons/ASPQuery.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <ttb/TTBWorldModel.h>
#include <ttb/wm/topology/POI.h>

#include <actionlib/client/simple_action_client.h>
#include <kobuki_msgs/DockInfraRed.h>
#include <kobuki_msgs/SensorState.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <nav_msgs/Odometry.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1470041810334) ENABLED START*/
// initialise static variables here
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
/*PROTECTED REGION END*/

SearchForDockingStationAsp::SearchForDockingStationAsp()
        : DomainBehaviour("SearchForDockingStationAsp")
{
    /*PROTECTED REGION ID(con1470041810334) ENABLED START*/
    // Add additional options here
    this->query = make_shared<alica::Query>();
    /*PROTECTED REGION END*/
}
SearchForDockingStationAsp::~SearchForDockingStationAsp()
{
    /*PROTECTED REGION ID(dcon1470041810334) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void SearchForDockingStationAsp::run(void* msg)
{
    /*PROTECTED REGION ID(run1470041810334) ENABLED START*/
    // Add additional options here
    auto odom = wm->rawSensorData.getOdometryBuffer()->getLastValidContent();
    auto core = wm->rawSensorData.getMobileBaseSensorStateBuffer()->getLastValidContent();
    auto infrRedDock = wm->rawSensorData.getDockInfrRedBuffer()->getLastValidContent();

#ifdef testWithoutTTB
    if ((*core)->charger == kobuki_msgs::SensorState::DISCHARGING) {
#endif
        std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        query->getSolution<alica::reasoner::ASPSolverWrapper, ::reasoner::AnnotatedValVec*>(this->getPlanContext(), result);
        std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::cout << "SearchForDockingStationAsp: Measured Solving and Grounding Time: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0 << " ms" << std::endl;
        std::shared_ptr<ttb::wm::POI> dockingStation = nullptr;
        if (result.size() > 0) {
            auto it = find_if(result.begin(), result.end(), [](::reasoner::AnnotatedValVec* element) { return element->id == 1470042926317; });
            if (it != result.end()) {
                if ((*it)->variableQueryValues.size() > 0) {
                    std::cout << "SearchForDockingStationAsp: ASP result found!" << std::endl;
                    std::stringstream ss;
                    ss << (*it)->variableQueryValues.at(0).at(0);
                    std::cout << (*it)->variableQueryValues.at(0).at(0) << std::endl;
                    // TODO fix after adding asp to topological model
                    //                    shared_ptr < ttb::wm::POI > dockingStation = this->wm->pois.getPOIByName(
                    //                            getPOIName(ss.str()));
                    //
                    //                    std::cout << "SearchForDockingStationAsp: Docking station is located at (" <<
                    //                    dockingStation->x << " | "
                    //                            << dockingStation->y << ")" << std::endl;
                } else {
                    std::cout << "SearchForDockingStationAsp: no result found!" << std::endl;
                    std::cout << "\tThe model contains the predicates: " << std::endl;
                    std::cout << "\t\t";
                    for (size_t i = 0; i < (*it)->query->getCurrentModels()->at(0).size(); i++) {
                        std::cout << (*it)->query->getCurrentModels()->at(0).at(i) << " ";
                    }
                    std::cout << std::endl;
                }
            } else {
                std::cout << "SearchForDockingStationAsp: no result vector found!" << std::endl;
            }
        } else {
            std::cout << "SearchForDockingStationAsp: result empty!" << std::endl;
        }
        if (dockingStation == nullptr) {
            std::cout << "SearchForDockingStationAsp: no docking station found!" << std::endl;
            return;
        }
        MoveBaseClient mbc("move_base", true);
        move_base_msgs::MoveBaseGoal mbg;
        mbg.target_pose.header.frame_id = "map";
        mbg.target_pose.pose.orientation.w = 1;
        mbg.target_pose.pose.position.x = dockingStation->x;
        mbg.target_pose.pose.position.y = dockingStation->y;

        mbc.sendGoal(mbg);
        mbc.waitForResult();

        if (mbc.getState() != actionlib::SimpleClientGoalState::SUCCEEDED) {
#ifdef testWithoutTTB
            KDL::Rotation rot;
            tf::quaternionMsgToKDL((*core)->pose.pose.orientation, rot);

            double r, p, y;
            rot.GetRPY(r, p, y);

            ecl::Pose2D<double> pose;
            pose.x((*odom)->pose.pose.position.x);
            pose.y((*odom)->pose.pose.position.y);
            pose.heading(y);

            dock.setMinAbsV(0.08); // 0.07 works ok
            dock.setMinAbsW(0.5);

            dock.update(infrRedDock->data, (*core)->bumper, (*core)->charger, pose);

            geometry_msgs::Twist cmd_vel;
            cmd_vel.linear.x = dock.getVX();
            cmd_vel.angular.z = dock.getWZ();

            send(cmd_vel);
#endif
        } else {
            this->setSuccess();
        }
#ifdef testWithoutTTB
    }
#endif
    /*PROTECTED REGION END*/
}
void SearchForDockingStationAsp::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1470041810334) ENABLED START*/
    // Add additional options here
    query->clearStaticVariables();
    query->addStaticVariable(getVariable("SearchVar"));
    result.clear();

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1470041810334) ENABLED START*/
// Add additional methods here
std::string alica::SearchForDockingStationAsp::getPOIName(std::string predicate)
{
    size_t start = predicate.find("(");
    size_t end = predicate.find(",", start);
    std::string p = predicate.substr(start + 1, end - start - 1);
    return p;
}
/*PROTECTED REGION END*/

} /* namespace alica */
