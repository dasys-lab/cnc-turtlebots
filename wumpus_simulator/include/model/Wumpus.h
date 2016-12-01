/*
 * Wumpus.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_WUMPUS_H_
#define INCLUDE_MODEL_WUMPUS_H_

#include <model/Movable.h>

namespace wumpus_simulator
{

	class Wumpus : public Movable
	{
	public:
		Wumpus();
		virtual ~Wumpus();
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_WUMPUS_H_ */
