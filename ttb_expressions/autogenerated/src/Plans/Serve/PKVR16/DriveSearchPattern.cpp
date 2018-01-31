using namespace std;
#include "Plans/Serve/PKVR16/DriveSearchPattern.h"

/*PROTECTED REGION ID(inccpp1481545714198) ENABLED START*/ // Add additional includes here
#include <TTBWorldModel.h>
#include <Robot.h>
#include <geometry_msgs/Point.h>
#include <nav_msgs/GetMap.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1481545714198) ENABLED START*/ // initialise static variables here
    /*PROTECTED REGION END*/
    DriveSearchPattern::DriveSearchPattern() :
            DomainBehaviour("DriveSearchPattern")
    {
        /*PROTECTED REGION ID(con1481545714198) ENABLED START*/ // Add additional options here
        scanRange = (*sc)["LogicalCamera"]->get<double>("LogicalCamera.landmark.range", NULL);
        this->listPoint = -1;

        distanceGoalY = 0;
        distanceGoalX = 0;
        distanceToGoal = 0;
        mapCorrectX = 0;
        mapCorrectY = 0;
        pointsHeight = 0;
        pointsWidth = 0;
        resolution = 0;
        mapWidth = 0;
        mapHeight = 0;
        /*PROTECTED REGION END*/
    }
    DriveSearchPattern::~DriveSearchPattern()
    {
        /*PROTECTED REGION ID(dcon1481545714198) ENABLED START*/ // Add additional options here
        /*PROTECTED REGION END*/
    }
    void DriveSearchPattern::run(void* msg)
    {
        /*PROTECTED REGION ID(run1481545714198) ENABLED START*/ // Add additional options here
//        auto ownPos = wm->rawSensorData.getOdomPositionBuffer()->getLastValidContent();
//        cout << "DriveSearchPattern: seen objects:" << wm->logicalCameraData.getLogicalObjects("box").size() << endl;
//
//        if (wm->logicalCameraData.getLogicalObjects("box").size() == 4)
//        {
//            this->setSuccess(true);
//            cout << "DriveSearchPattern:: found all 4 objects" << endl;
//            return;
//        }
//
//        auto state = robot->movement->getMoveState();
//        move_base_msgs::MoveBaseGoal goal;
//        switch (state.state_)
//        {
//            case actionlib::SimpleClientGoalState::ACTIVE:
//                cout << "DriveSearchPattern: Goal is active!" << endl;
//                cout << "current goal:" << list[listPoint].x << "," << list[listPoint].y << endl;
//                distanceGoalX = fabs(list[listPoint].x - ownPos->x);
//                distanceGoalY = fabs(list[listPoint].y - ownPos->y);
//                distanceToGoal = sqrt(distanceGoalX * distanceGoalX + distanceGoalY * distanceGoalY);
//                if (distanceToGoal < scanRange / 4)
//                {
//                	robot->movement->cancelGoal();
//                    cout << "Goal reached in scanRange/4. Distance:" << distanceToGoal << " " << state.state_ << endl;
//                }
//                break;
//            case actionlib::SimpleClientGoalState::PENDING:
//            case actionlib::SimpleClientGoalState::RECALLED:
//            case actionlib::SimpleClientGoalState::REJECTED:
//            case actionlib::SimpleClientGoalState::PREEMPTED:
//            case actionlib::SimpleClientGoalState::ABORTED:
//            case actionlib::SimpleClientGoalState::SUCCEEDED:
//            case actionlib::SimpleClientGoalState::LOST:
//                //                if (listPoint < list.size())
//                //                {
//                listPoint++;
//                //                }
//
//                goal.target_pose.pose.orientation.w = 1;
//                goal.target_pose.pose.position = list[listPoint];
//
//                goal.target_pose.header.frame_id = "map";
//                goal.target_pose.header.stamp = ros::Time::now();
//                goal.target_pose.header.seq = 0;
//                cout << "DriveSearchPattern: Sending next Goal: (" << list[listPoint].x << "," << list[listPoint].y
//                        << ")" << endl;
//                robot->movement->send(goal);
//
//                break;
//            default:
//                break;
//        }
//
//        //		printf("X-Coordinate: %d", list[1].x);
//        //		printf("MapHeight: %f ", mapHeight);
//        //		printf("MapWidth: %f ", mapWidth);
//        //		printf("Reslution: %f\n", resolution);
//
//        // 2. Punkte der reihe nach abfahren
//        // 3. Wenn eine Box gefunden wird, Nachricht an WM schicken (neue Nachricht notwendig)

        /*PROTECTED REGION END*/
    }
    void DriveSearchPattern::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1481545714198) ENABLED START*/ // Add additional options here
        // 1. Punkt pattern/liste erstellen/generieren
        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient < nav_msgs::GetMap > ("/static_map");
        nav_msgs::GetMap srv;
        if (client.call(srv))
        {
            resolution = srv.response.map.info.resolution;
            mapHeight = srv.response.map.info.height * resolution;
            mapWidth = srv.response.map.info.width * resolution;
            mapCorrectX = srv.response.map.info.origin.position.x;
            mapCorrectY = srv.response.map.info.origin.position.y;
            cout << mapCorrectX << " Y " << mapCorrectY << endl;
            // srv.response.map.info.origin.position.x todo move all points by origin to avoid points outside of the map
        }
        else
        {
            cout << "Failed to call service /static_map. Is there a map_server running?" << endl;
        }
        pointsWidth = mapWidth / (scanRange / 2);
        pointsHeight = mapHeight / (scanRange / 2);

        for (double x = (scanRange / 2); x < mapWidth - (scanRange / 2); x += (scanRange / 2))
        {
            for (double y = (scanRange / 2); y < mapHeight - (scanRange / 2); y += (scanRange / 2))
            {
                geometry_msgs::Point p;
                p.x = x + mapCorrectX;
                p.y = y + mapCorrectY;
                p.z = 0;
                list.push_back(p);
            }
        }

        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1481545714198) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
