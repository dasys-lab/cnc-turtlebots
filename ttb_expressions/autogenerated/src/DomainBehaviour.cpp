#include "DomainBehaviour.h"

#include <engine/AlicaEngine.h>
#include <TTBWorldModel.h>
#include <Robot.h>
#include <SystemConfig.h>

namespace alica
{
	DomainBehaviour::DomainBehaviour(std::string name) :
			BasicBehaviour(name)
	{
		sc = supplementary::SystemConfig::getInstance();
		wm = ttb::TTBWorldModel::get();
		robot = ttb::Robot::get();
	}

	DomainBehaviour::~DomainBehaviour()
	{
	}
} /* namespace alica */

