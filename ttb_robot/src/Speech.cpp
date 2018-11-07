#include "robot/Speech.h"

#include <SystemConfig.h>

namespace ttb
{
namespace robot
{

Speech::Speech()
{
    sc = supplementary::SystemConfig::getInstance();
}

Speech::~Speech() {}

void Speech::say(std::string text)
{
    this->soundClient.say(text);
}

} /* namespace robot */
} /* namespace ttb */
