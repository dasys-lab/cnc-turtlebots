/*
 * TTBWorldModel.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef TTBWORLDMODEL_H_
#define TTBWORLDMODEL_H_


#include <list>
#include <iostream>
#include <tuple>
#include <mutex>
#include <string>

#include <ros/ros.h>

#include "SystemConfig.h"
#include "RawSensorData.h"
#include "Robots.h"
#include "EventTrigger.h"

namespace supplementary {
	class SystemConfig;
}

using namespace std;

namespace ttb
{

	class TTBWorldModel
	{
	public:
		static TTBWorldModel* get(); /**< Singleton Getter */

		virtual ~TTBWorldModel();
		int getRingBufferLength();

		// Public Data Access Classes
		RawSensorData rawSensorData;
		Robots robots;

	private:

		TTBWorldModel(); /**< Private Singleton Constructor */

		supplementary::SystemConfig* sc;

		int ownID;
		int ringBufferLength;

		mutex wmMutex;


		// ROS Stuff
		ros::NodeHandle n;
		ros::AsyncSpinner* spinner;
		string odometryTopic;
		ros::Subscriber odometrySub;

		void onOdometryData(nav_msgs::OdometryConstPtr odometryData);

	protected:

	};

} /* namespace ttb */

#endif /* TTBWORLDMODEL_H_ */
