#include "Robot.h"

namespace ttb
{

Robot *Robot::get()
{
    static Robot instance;
    return &instance;
}

Robot::Robot()
{
	this->movement = new robot::Movement();
	this->simulatedArm = new robot::SimulatedArm();
}

Robot::~Robot()
{
}

} /* namespace ttb */
