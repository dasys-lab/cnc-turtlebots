/*
 * TTBWorldModel.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef TTBWORLDMODEL_H_
#define TTBWORLDMODEL_H_

#include <ros/ros.h>
#include <list>
#include <iostream>
#include <tuple>
#include <mutex>

#include "SystemConfig.h"
#include "RawSensorData.h"
#include "Robots.h"
#include "EventTrigger.h"


using namespace std;

namespace ttb
{

	class TTBSharedWorldModel;
	class TTBWorldModel
	{
	public:
		static TTBWorldModel* get();

		TTBSharedWorldModel* getSharedWolrdModel();
		unsigned long getTime();
		void sendSharedWorldModelData();
		void getWorldModelData();

		TTBWorldModel();
		virtual ~TTBWorldModel();
		int getRingBufferLength();

		RawSensorData rawSensorData;
		Robots robots;
		supplementary::EventTrigger visionTrigger;

	private:

		int ownID;
		int ringBufferLength;
		double kickerVoltage;
		TTBSharedWorldModel* sharedWolrdModel;

		ros::NodeHandle n;
		ros::Publisher sharedWorldPub;
		ros::AsyncSpinner* spinner;

	protected:

	};

} /* namespace ttb */

#endif /* TTBWORLDMODEL_H_ */
