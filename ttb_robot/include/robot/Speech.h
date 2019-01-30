#pragma once

#include <sound_play/SoundRequest.h>
#include <sound_play/sound_play.h>

#include <ros/ros.h>

#include <string>

namespace essentials
{
class SystemConfig;
}

namespace ttb
{
namespace robot
{

class Speech
{
public:
    Speech();
    virtual ~Speech();
    void say(std::string text);

protected:
private:
    essentials::SystemConfig* sc;
    sound_play::SoundClient soundClient;
};

} /* namespace robot */
} /* namespace ttb */
