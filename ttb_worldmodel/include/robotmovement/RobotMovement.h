/*
 * RobotMovement.h
 *
 *  Created on: 17.12.2014
 *      Author: tobi
 */

#ifndef CNC_TTB_TTB_WORLDMODEL_SRC_ROBOTMOVEMENT_ROBOTMOVEMENT_H_
#define CNC_TTB_TTB_WORLDMODEL_SRC_ROBOTMOVEMENT_ROBOTMOVEMENT_H_

#include <memory>

using namespace std;


namespace ttb {
class CNPoint2D;
	class RobotMovement {
	public:
		virtual ~RobotMovement();
		static void readConfigParameters();
		static double defaultTranslation;
		static double defaultRotateP;
		static double interceptCarfullyRotateP;
	};
}

#endif /* CNC_TTB_TTB_WORLDMODEL_SRC_ROBOTMOVEMENT_ROBOTMOVEMENT_H_ */
