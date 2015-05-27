/*
 * TTBSharedWorldModel.cpp
 *
 *  Created on: 27.05.2015
 *      Author: Stephan Opfer
 */

#include <ios>
#include "sharedworldmodel/TTBSharedWorldModel.h"
#include "TTBWorldModel.h"

using namespace std;

namespace ttb {

TTBSharedWorldModel::TTBSharedWorldModel(TTBWorldModel* wm) {

	this->wm = wm;
	timer = n.createTimer(ros::Duration(0.1), &TTBSharedWorldModel::sendSharedWorldModelData, this);

	sc = supplementary::SystemConfig::getInstance();
	ownID = sc->getOwnRobotID();


}

TTBSharedWorldModel::~TTBSharedWorldModel() {
	// TODO Auto-generated destructor stub
}

void TTBSharedWorldModel::sendSharedWorldModelData(const ros::TimerEvent& e) {
	wm->sendSharedWorldModelData();
}

} /* namespace ttb */
