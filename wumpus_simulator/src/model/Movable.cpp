/*
 * Movable.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Movable.h>

namespace wumpus_simulator
{

	Movable::Movable()
	{
		type = "unknown";
	}

	Movable::~Movable()
	{
	}

	QString Movable::getType()
	{
		return type;
	}

	shared_ptr<GroundTile> Movable::getTile()
	{
		return tile;
	}

	void Movable::setTile(shared_ptr<GroundTile> tile)
	{
		this->tile = tile;
	}

} /* namespace wumpus_simulator */
