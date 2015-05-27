/*
 * RobotMovement.cpp *
 *
 *  Created on: 17.12.2014
 *      Author: tobi
 */

#include "robotmovement/RobotMovement.h"

#include <SystemConfig.h>

namespace ttb
{
	double RobotMovement::defaultTranslation;
	double RobotMovement::defaultRotateP;
	double RobotMovement::interceptCarfullyRotateP;

	RobotMovement::~RobotMovement()
	{
		// TODO Auto-generated destructor stub
	}

	void RobotMovement::readConfigParameters()
	{
		defaultTranslation = (*supplementary::SystemConfig::getInstance())["Drive"]->get<double>("Drive",
																									"DefaultVelocity",	NULL);
		defaultRotateP = (*supplementary::SystemConfig::getInstance())["Drive"]->get<double>("Drive", "DefaultRotateP", NULL);
		interceptCarfullyRotateP = (*supplementary::SystemConfig::getInstance())["Drive"]->get<double>("Drive", "InterceptCarefullyRotateP", NULL);
	}
}
