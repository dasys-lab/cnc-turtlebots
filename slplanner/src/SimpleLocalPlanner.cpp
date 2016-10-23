/*
 * SimpleLocalPlanner.cpp
 *
 *  Created on: 21 Oct 2016
 *      Author: Stephan Opfer
 */

#include "SimpleLocalPlanner.h"
#include <pluginlib/class_list_macros.h>

namespace ttb_path_planner
{

	SimpleLocalPlanner::SimpleLocalPlanner()
	{
		// TODO Auto-generated constructor stub
	}

	SimpleLocalPlanner::~SimpleLocalPlanner()
	{
		// TODO Auto-generated destructor stub
	}

	bool SimpleLocalPlanner::computeVelocityCommands(geometry_msgs::Twist& cmd_vel)
	{
		std::cout << "SLPlanner: computeVelocityCommands called" << std::endl;

//		this->localPlannerUtil->getGoal();

		return true;
	}

	bool SimpleLocalPlanner::isGoalReached()
	{
		// TODO Auto-generated stub
		std::cout << "SLPlanner: isGoalReached called" << std::endl;
		return false;
	}

	bool SimpleLocalPlanner::setPlan(const std::vector<geometry_msgs::PoseStamped>& global_plan)
	{
		std::cout << "SLPlanner: setPlan called" << std::endl;

		// reset global plan
		this->localPlannerUtil->setPlan(global_plan);

		return true;
	}

	void SimpleLocalPlanner::initialize(std::string name, tf::TransformListener* tf,
										costmap_2d::Costmap2DROS* costmap_ros)
	{
		std::cout << "SLPlanner: initialize called" << std::endl;
		this->localPlannerUtil = std::make_shared<base_local_planner::LocalPlannerUtil>();
		this->localPlannerUtil->initialize(tf, costmap_ros->getCostmap(), costmap_ros->getGlobalFrameID());
	}

} /* namespace ttb_path_planner */

//register this planner as a BaseLocalPlanner plugin
PLUGINLIB_EXPORT_CLASS(ttb_path_planner::SimpleLocalPlanner, nav_core::BaseLocalPlanner)
