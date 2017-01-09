using namespace std;
#include "Plans/Serve/PKVR16/DriveSearchPattern.h"

/*PROTECTED REGION ID(inccpp1481545714198) ENABLED START*/ //Add additional includes here

#include "nav_msgs/GetMap.h"
#include "geometry_msgs/Point.h"
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1481545714198) ENABLED START*/ //initialise static variables here
	double mapHeight;
	double mapWidth;
	double resolution;
	int pointsWidth;
	int pointsHeight;
	/*PROTECTED REGION END*/
	DriveSearchPattern::DriveSearchPattern() :
			DomainBehaviour("DriveSearchPattern")
	{
		/*PROTECTED REGION ID(con1481545714198) ENABLED START*/ //Add additional options here
		scanRange = (*sc)["LogicalCamera"]->get<double>("LogicalCamera.Landmark.range", NULL);
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
		// 1. Punkt pattern/liste erstellen/generieren
		ros::NodeHandle n;
		ros::ServiceClient client = n.serviceClient <nav_msgs::GetMap> ("/static_map");
		nav_msgs::GetMap srv;
		if (client.call(srv))
		{
			resolution = srv.response.map.info.resolution;
			mapHeight = srv.response.map.info.height * resolution;
			mapWidth = srv.response.map.info.width * resolution;
		}
		else
		{
			cout << "Failed to call service /static_map. Is there a map_server running?" << endl;
		}
		pointsWidth = mapWidth/(scanRange/2);
		pointsHeight = mapHeight/(scanRange/2);
//		bool pattern[][] = new bool [pointsWidth][pointsHeight];
		vector<geometry_msgs::Point> list;

		for(double x = 0; x < mapWidth; x += (scanRange/2)){
			for(double y = 0; y < mapHeight; y += (scanRange/2)){
				geometry_msgs::Point p;
				p.x = x;
				p.y = y;
				p.z = 0;
				//cout << p << endl;
				list.push_back(p);
			}
		}

		move_base_msgs::MoveBaseGoal goal;
		goal.target_pose.pose.orientation.w = 1;
		goal.target_pose.pose.position = list[0];

		goal.target_pose.header.frame_id = 1;
		goal.target_pose.header.stamp = ros::Time::now();
		goal.target_pose.header.seq = 0;


		if(getMoveState() != actionlib::SimpleClientGoalState::ACTIVE){
			send(goal);

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
		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1481545714198) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
