#include "TurtleBot.h"

namespace ttb
{

TurtleBot *TurtleBot::get(ttb::TTBWorldModel* wm)
{
    static TurtleBot instance(wm);
    return &instance;
}

TurtleBot::TurtleBot(ttb::TTBWorldModel* wm)
{
	this->movement = new robot::Movement(wm, this);
	this->simulatedArm = new robot::SimulatedArm();
	this->speech = new robot::Speech();
}

TurtleBot::~TurtleBot()
{
	delete movement;
	delete simulatedArm;
	delete speech;
}

} /* namespace ttb */
