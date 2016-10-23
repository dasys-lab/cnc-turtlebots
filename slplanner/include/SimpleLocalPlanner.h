/*
 * SimpleLocalPlanner.h
 *
 *  Created on: 21 Oct 2016
 *      Author: Stephan Opfer
 */

#ifndef SRC_SIMPLELOCALPLANNER_H_
#define SRC_SIMPLELOCALPLANNER_H_

#include <nav_core/base_local_planner.h>
#include <base_local_planner/local_planner_util.h>
#include <geometry_msgs/Twist.h>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

namespace ttb_path_planner
{

	class SimpleLocalPlanner : public nav_core::BaseLocalPlanner
	{
	public:
		SimpleLocalPlanner();
		virtual ~SimpleLocalPlanner();

		/**
		 * @brief  Given the current position, orientation, and velocity of the robot, compute velocity commands to send to the base
		 * @param cmd_vel Will be filled with the velocity command to be passed to the robot base
		 * @return True if a valid velocity command was found, false otherwise
		 */
		bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);

		/**
		 * @brief  Check if the goal pose has been achieved by the local planner
		 * @return True if achieved, false otherwise
		 */
		bool isGoalReached();

		/**
		 * @brief  Set the plan that the local planner is following
		 * @param plan The plan to pass to the local planner
		 * @return True if the plan was updated successfully, false otherwise
		 */
		bool setPlan(const std::vector<geometry_msgs::PoseStamped>& plan);

		/**
		 * @brief  Constructs the local planner
		 * @param name The name to give this instance of the local planner
		 * @param tf A pointer to a transform listener
		 * @param costmap_ros The cost map to use for assigning costs to local plans
		 */
		void initialize(std::string name, tf::TransformListener* tf, costmap_2d::Costmap2DROS* costmap_ros);

	private:
		std::vector<geometry_msgs::PoseStamped> globalPlan;
		std::shared_ptr<base_local_planner::LocalPlannerUtil> localPlannerUtil;

	};

} /* namespace ttb_path_planner */

#endif /* SRC_SIMPLELOCALPLANNER_H_ */
