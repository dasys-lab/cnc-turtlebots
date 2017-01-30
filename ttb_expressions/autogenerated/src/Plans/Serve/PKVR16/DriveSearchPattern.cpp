using namespace std;
#include "Plans/Serve/PKVR16/DriveSearchPattern.h"

/*PROTECTED REGION ID(inccpp1481545714198) ENABLED START*/ //Add additional includes here
#include "nav_msgs/GetMap.h"
#include "geometry_msgs/Point.h"
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1481545714198) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    DriveSearchPattern::DriveSearchPattern() :
            DomainBehaviour("DriveSearchPattern")
    {
        /*PROTECTED REGION ID(con1481545714198) ENABLED START*/ //Add additional options here
        scanRange = (*sc)["LogicalCamera"]->get<double>("LogicalCamera.Landmark.range", NULL);
        this->listPoint = -1;
        /*PROTECTED REGION END*/
    }
    DriveSearchPattern::~DriveSearchPattern()
    {
        /*PROTECTED REGION ID(dcon1481545714198) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void DriveSearchPattern::run(void* msg)
    {
        /*PROTECTED REGION ID(run1481545714198) ENABLED START*/ //Add additional options here
        ownPosition = wm->rawSensorData.getOwnPosition();
        if (wm->logicalCameraData.getLogicalObjects("landmark").size() == 4)
        {
            this->setSuccess(true);
            return;
        }

        auto state = getMoveState();
        move_base_msgs::MoveBaseGoal goal;
        switch (state.state_)
        {
            case actionlib::SimpleClientGoalState::ACTIVE:
                cout << "DriveSearchPattern: Goal is active!" << endl;
                cout << "current goal:" << list[listPoint].x << "," << list[listPoint].y << endl;
                distanceGoalX = fabs(list[listPoint].x - ownPosition->x);
                distanceGoalY = fabs(list[listPoint].y - ownPosition->y);
                distanceToGoal = sqrt(distanceGoalX * distanceGoalX + distanceGoalY * distanceGoalY);
                if (distanceToGoal < scanRange / 4)
                {
                    cancelGoal();
                    cout << "Goal reached in scanRange/4. Distance:" << distanceToGoal << " " << state.state_ << endl;
                }
                break;
            case actionlib::SimpleClientGoalState::PENDING:
            case actionlib::SimpleClientGoalState::RECALLED:
            case actionlib::SimpleClientGoalState::REJECTED:
            case actionlib::SimpleClientGoalState::PREEMPTED:
            case actionlib::SimpleClientGoalState::ABORTED:
            case actionlib::SimpleClientGoalState::SUCCEEDED:
            case actionlib::SimpleClientGoalState::LOST:
//                if (listPoint < list.size())
//                {
                    listPoint++;
//                }

                goal.target_pose.pose.orientation.w = 1;
                goal.target_pose.pose.position = list[listPoint];

                goal.target_pose.header.frame_id = "map";
                goal.target_pose.header.stamp = ros::Time::now();
                goal.target_pose.header.seq = 0;
                cout << "DriveSearchPattern: Sending next Goal: (" << list[listPoint].x << "," << list[listPoint].y
                        << ")" << endl;
                send(goal);

                break;
            default:
                break;
        }

//		printf("X-Coordinate: %d", list[1].x);
//		printf("MapHeight: %f ", mapHeight);
//		printf("MapWidth: %f ", mapWidth);
//		printf("Reslution: %f\n", resolution);

        // 2. Punkte der reihe nach abfahren
        // 3. Wenn eine Box gefunden wird, Nachricht an WM schicken (neue Nachricht notwendig)

        /*PROTECTED REGION END*/
    }
    void DriveSearchPattern::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1481545714198) ENABLED START*/ //Add additional options here
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
            //srv.response.map.info.origin.position.x todo move all points by origin to avoid points outside of the map
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
/*PROTECTED REGION ID(methods1481545714198) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
