/*
 * Wumpus.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Wumpus.h>
#include <model/GroundTile.h>

namespace wumpus_simulator
{

	Wumpus::Wumpus(shared_ptr<GroundTile> tile) {
		this->tile = tile;
	}

	Wumpus::~Wumpus()
	{
		// TODO Auto-generated destructor stub
	}

} /* namespace wumpus_simulator */
