#include "DomainBehaviour.h"

#include <engine/AlicaEngine.h>
#include <ttb/TTBWorldModel.h>
#include <TurtleBot.h>
#include <SystemConfig.h>

namespace alica
{
	DomainBehaviour::DomainBehaviour(std::string name) :
			BasicBehaviour(name)
	{
		sc = supplementary::SystemConfig::getInstance();
		wm = ttb::TTBWorldModel::get();
		turtleBot = ttb::TurtleBot::get(wm);
	}

	DomainBehaviour::~DomainBehaviour()
	{
	}
} /* namespace alica */

