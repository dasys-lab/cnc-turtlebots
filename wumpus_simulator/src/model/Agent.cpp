/*
 * Agent.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Agent.h>

namespace wumpus_simulator
{

	Agent::Agent(shared_ptr<GroundTile> tile)
	{
		this->tile = tile;
		type = "agent";
		arrow = false;
	}

	Agent::~Agent()
	{
	}

	bool Agent::hasArrow()
	{
		return arrow;
	}

	void Agent::setArrow(bool value)
	{
		this->arrow = value;
	}

} /* namespace wumpus_simulator */
