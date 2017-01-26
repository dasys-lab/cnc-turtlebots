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
		hasGold = false;
		this->heading = WumpusEnums::heading::up;
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

	WumpusEnums::heading Agent::getHeading()
	{
		return heading;
	}

	void Agent::setHeading(WumpusEnums::heading heading)
	{
		this->heading = heading;
	}

	void wumpus_simulator::Agent::setHasGold(bool value)
	{
		this->hasGold = hasGold;
	}

	bool wumpus_simulator::Agent::getHasGold()
	{
		return hasGold;
	}


} /* namespace wumpus_simulator */

