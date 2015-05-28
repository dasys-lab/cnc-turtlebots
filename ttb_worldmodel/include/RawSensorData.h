/*
 * RawSensorData.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_
#define CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_

#include <vector>

#include "nav_msgs/Odometry.h"
#include "container/CNPosition.h"
#include "container/CNVelocity2D.h"

#include "RingBuffer.h"
#include "InformationElement.h"


using namespace std;

namespace ttb
{

	class TTBWorldModel;
	class RawSensorData
	{
	public:
		RawSensorData(TTBWorldModel* wm, int ringBufferLength);
		virtual ~RawSensorData();
		void processOdometryData(nav_msgs::OdometryConstPtr odometryData);

	private:
		int ownID;
		TTBWorldModel* wm;
		RingBuffer<InformationElement<geometry::CNPosition>> ownPositionMotion;
		RingBuffer<InformationElement<geometry::CNVelocity2D>> ownVelocityMotion;

	};

} /* namespace ttb */

#endif /* CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_ */
