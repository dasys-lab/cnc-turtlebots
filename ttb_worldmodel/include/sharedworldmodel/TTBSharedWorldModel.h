/*
 * TTBSharedWorldModel.h
 *
 *  Created on: 27.05.2015
 *      Author: Stephan Opfer
 */

#ifndef CNC_TURTLEBOTS_TTB_WORLDMODEL_SRC_SHAREDWORLDMODEL_TTBSHAREDWORLDMODEL_H_
#define CNC_TURTLEBOTS_TTB_WORLDMODEL_SRC_SHAREDWORLDMODEL_TTBSHAREDWORLDMODEL_H_

#include <ros/ros.h>
#include "SystemConfig.h"


namespace ttb {

class TTBWorldModel;
class TTBSharedWorldModel {

public:
	TTBSharedWorldModel(TTBWorldModel* wm);
	virtual ~TTBSharedWorldModel();
	void sendSharedWorldModelData(const ros::TimerEvent& e);

private:

	supplementary::SystemConfig* sc;
	TTBWorldModel* wm;

	// ROS-Stuff
	ros::NodeHandle n;

	// Data fields
	int ownID;

};

} /* namespace ttb */

#endif /* CNC_TURTLEBOTS_TTB_WORLDMODEL_SRC_SHAREDWORLDMODEL_TTBSHAREDWORLDMODEL_H_ */
