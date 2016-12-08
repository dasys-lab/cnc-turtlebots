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
		this->hasGold = false;
		this->hasTrap = false;
		this->hasStench = false;
		this->hasBreeze = false;
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

	void GroundTile::setGold(bool value) {
		hasGold = value;
	}

	void GroundTile::setTrap(bool value) {
		hasTrap = value;
	}

	void GroundTile::setStench(bool value) {
		hasStench = value;
	}

	bool GroundTile::hasWumpus(){
		if(wumpus) {
			return true;
		} else {
			return false;
		}
	}

	shared_ptr<Wumpus> GroundTile::getWumpus()
	{
		return wumpus;
	}

	void GroundTile::setWumpus(shared_ptr<Wumpus> wumpus)
	{
		this->wumpus = wumpus;
	}

	bool GroundTile::getBreeze()
	{
		return hasBreeze;
	}

	void GroundTile::setBreeze(bool hasBreeze)
	{
		this->hasBreeze = hasBreeze;
	}

} /* namespace wumpus_simulator */
