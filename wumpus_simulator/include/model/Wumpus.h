/*
 * Wumpus.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_WUMPUS_H_
#define INCLUDE_MODEL_WUMPUS_H_

#include <model/Movable.h>
#include <memory>

using namespace std;

namespace wumpus_simulator
{
	class GroundTile;
	class Wumpus : public Movable
	{
	public:
		Wumpus(shared_ptr<GroundTile> tile);
		virtual ~Wumpus();
	};


} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_WUMPUS_H_ */
