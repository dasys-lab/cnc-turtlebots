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
		void setTrap(bool value);
		void setStench(bool value);
		void setGold(bool value);
		shared_ptr<Wumpus> getWumpus();
		void setWumpus(shared_ptr<Wumpus> wumpus);
		void setBreeze(bool hasBreeze);

		bool getTrap();
		bool getGold();
		bool getStench();
		bool hasWumpus();
		bool getBreeze();

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
