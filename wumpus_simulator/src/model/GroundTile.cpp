/*
 * GroundTile.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/GroundTile.h>

namespace wumpus_simulator
{

	GroundTile::GroundTile(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	GroundTile::~GroundTile()
	{
		// TODO Auto-generated destructor stub
	}

	int GroundTile::getX()
	{
		return x;
	}

	int GroundTile::getY()
	{
		return y;
	}

} /* namespace wumpus_simulator */
