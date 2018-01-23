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
}

Robot::~Robot()
{
}

} /* namespace ttb */
