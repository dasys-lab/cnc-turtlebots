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
		this->id = -1;
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

	int Movable::getId()
	{
		return id;
	}

	void Movable::setId(int id)
	{
		this->id = id;
	}

} /* namespace wumpus_simulator */
