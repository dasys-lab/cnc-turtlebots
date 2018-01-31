#include "Robot.h"

namespace ttb
{

Robot *Robot::get(ttb::TTBWorldModel* wm)
{
    static Robot instance(wm);
    return &instance;
}

Robot::Robot(ttb::TTBWorldModel* wm)
{
	this->movement = new robot::Movement(wm);
	this->simulatedArm = new robot::SimulatedArm();
	this->speech = new robot::Speech();
}

Robot::~Robot()
{
	delete movement;
	delete simulatedArm;
	delete speech;
}

} /* namespace ttb */
