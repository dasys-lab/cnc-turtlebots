/*
 * GroundTile.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/GroundTile.h>
#include <model/Wumpus.h>

namespace wumpus_simulator
{

	GroundTile::GroundTile(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->startAgentID = -1;
		this->hasGold = false;
		this->hasTrap = false;
		this->hasStench = false;
		this->hasBreeze = false;
		this->isStartpoint = false;
		this->movable = nullptr;
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

	bool GroundTile::getGold()
	{
		return hasGold;
	}

	bool GroundTile::getStench()
	{
		return hasStench;
	}

	bool GroundTile::getTrap()
	{
		return hasTrap;
	}

	int GroundTile::getStartAgentID()
	{
		return startAgentID;
	}

	void GroundTile::setStartAgentID(int value)
	{
		startAgentID = value;
	}

	void GroundTile::setStartpoint(bool value)
	{
		isStartpoint = value;
	}

	bool GroundTile::getStartpoint()
	{
		return isStartpoint;
	}

	void GroundTile::setGold(bool value)
	{
		hasGold = value;
	}

	void GroundTile::setTrap(bool value)
	{
		hasTrap = value;
	}

	void GroundTile::setStench(bool value)
	{
		hasStench = value;
	}

	bool GroundTile::hasMovable()
	{
		if (movable != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	shared_ptr<Movable> GroundTile::getMovable()
	{
		return movable;
	}

	void GroundTile::setMovable(shared_ptr<Movable> movable)
	{
		this->movable = movable;
	}

	bool GroundTile::getBreeze()
	{
		return hasBreeze;
	}

	void GroundTile::setBreeze(bool hasBreeze)
	{
		this->hasBreeze = hasBreeze;
	}

	bool GroundTile::hasWumpus()
	{
		if(!this->hasMovable())
		{
			return false;
		}
		else
		{
			return dynamic_pointer_cast<Wumpus>(this->movable) != nullptr;
		}
	}

} /* namespace wumpus_simulator */


