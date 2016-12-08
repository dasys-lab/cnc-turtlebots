/*
 * GroundTile.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_GROUNDTILE_H_
#define INCLUDE_MODEL_GROUNDTILE_H_
#include <memory>

using namespace std;

namespace wumpus_simulator
{
	class Wumpus;
	class GroundTile
	{
	public:
		GroundTile(int x, int y);
		virtual ~GroundTile();
		int getX();
		int getY();
		bool getTrap();
		bool getGold();
		bool getStench();
		void setTrap(bool value);
		void setStench(bool value);
		void setGold(bool value);
		bool hasWumpus();
		shared_ptr<Wumpus> getWumpus();
		void setWumpus(shared_ptr<Wumpus> wumpus);
		bool getBreeze();
		void setBreeze(bool hasBreeze);

	private :
		int x;
		int y;
		bool hasTrap;
		bool hasGold;
		bool hasStench;
		bool hasBreeze;
		shared_ptr<Wumpus> wumpus;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_GROUNDTILE_H_ */
