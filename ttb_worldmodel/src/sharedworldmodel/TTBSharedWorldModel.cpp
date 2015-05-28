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

namespace ttb
{

	TTBSharedWorldModel::TTBSharedWorldModel(TTBWorldModel* wm)
	{

		this->wm = wm;

		this->sc = supplementary::SystemConfig::getInstance();
		this->ownID = sc->getOwnRobotID();

	}

	TTBSharedWorldModel::~TTBSharedWorldModel()
	{
	}

} /* namespace ttb */
