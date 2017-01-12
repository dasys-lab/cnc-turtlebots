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
	class Movable;
	class GroundTile
	{

	public:
		GroundTile(int x, int y);
		virtual ~GroundTile();
		int getX();
		int getY();
		void setStartAgentID(int value);
		void setStartpoint(bool value);
		void setTrap(bool value);
		void setStench(bool value);
		void setGold(bool value);
		shared_ptr<Movable> getMovable();
		void setMovable(shared_ptr<Movable> movable);
		void setBreeze(bool hasBreeze);

		int getStartAgentID();
		bool getTrap();
		bool getGold();
		bool getStench();
		bool hasMovable();
		bool getBreeze();
		bool getStartpoint();

	private :
		int x;
		int y;
		int startAgentID;
		bool hasTrap;
		bool hasGold;
		bool hasStench;
		bool hasBreeze;
		bool isStartpoint;
		shared_ptr<Movable> movable;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_GROUNDTILE_H_ */
