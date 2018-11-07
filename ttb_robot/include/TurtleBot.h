#pragma once

#include "robot/Movement.h"
#include "robot/SimulatedArm.h"
#include "robot/Speech.h"

namespace ttb
{

class TurtleBot
{
public:
    virtual ~TurtleBot();
    static TurtleBot* get(ttb::TTBWorldModel* wm); /**< Singleton Getter */

    robot::SimulatedArm* simulatedArm;
    robot::Movement* movement;
    robot::Speech* speech;

private:
    TurtleBot(ttb::TTBWorldModel* wm);
};

} /* namespace ttb */
