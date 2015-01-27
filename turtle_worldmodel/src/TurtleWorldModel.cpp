/*
 * TurtleWorldModel.cpp
 *
 *  Created on: 27.10.2014
 *      Author: endy
 *
 *  Extended on: 04.11.2014
 *      Author: Jonas Scherbaum
 */

#include "../include/TurtleWorldModel.h"

/**
 * Start the turtle namespace
 */
namespace turtle
{

        /**
         * The only true way of getting a Thread-Save Singleton Pattern in c++
         */
	TurtleWorldModel* TurtleWorldModel::get()
	{
		static TurtleWorldModel instance;
		return &instance;
	}

	/**
	 * Declare the WorldModel Constructor
	 */
	TurtleWorldModel::TurtleWorldModel()
	{
		ownID = supplementary::SystemConfig::getOwnRobotID();
		spinner = new ros::AsyncSpinner(4);
//		SubscriptionManager* subManager = SubscriptionManager::get();
		SubscriptionManager* subManager = new SubscriptionManager();
		spinner->start();
	}

	/**
	 * Declare the WorldModel Destructor
	 */
	TurtleWorldModel::~TurtleWorldModel()
	{
		spinner->stop();
		delete spinner;
	}

//	/**
//	 * returns x,y orientation:
//	 * (0,0) Is the field center
//	 * positive y = right side of the field (playing direction from yellow to blue)
//	 * negative x = blue goal
//	 * orientation of -pi = towards blue side
//	 *
//	 */
//	tuple<double, double, double> TurtleWorldModel::getOwnPosition()
//	{
//
//		double x, y, oriantation;
//		if (simData.size() > 0)
//		{
//			auto data = *simData.begin();
//			for (auto& r : data->detection.robots_yellow)
//			{
//				if (r.robot_id == ownID)
//				{
//					x = r.x;
//					y = r.y;
//					oriantation = r.orientation;
//				}
//			}
//		}
//		return make_tuple(x, y, oriantation);
//	}
//
//	pair<double, double> TurtleWorldModel::getBallPosition()
//	{
//		pair<double, double> ret;
//		if (simData.size() > 0)
//		{
//			auto data = *simData.begin();
//			if (data->detection.balls.size() > 0)
//			{
//				ret.first = data->detection.balls.begin()->x;
//				ret.second = data->detection.balls.begin()->y;
//			}
//		}
//		return ret;
//	}

} /* namespace turtle */
