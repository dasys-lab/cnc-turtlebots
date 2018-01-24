#pragma once

#include "robot/SimulatedArm.h"
#include "robot/Movement.h"
#include "robot/Speech.h"

namespace ttb
{

class Robot
{
  public:
	virtual ~Robot();
	static Robot *get(); /**< Singleton Getter */

	robot::SimulatedArm* simulatedArm;
	robot::Movement* movement;
	robot::Speech* speech;

  private:
	Robot();
};

} /* namespace ttb */
