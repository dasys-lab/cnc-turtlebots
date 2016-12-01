/*
 * Agent.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_AGENT_H_
#define INCLUDE_MODEL_AGENT_H_

#include <model/Movable.h>

namespace wumpus_simulator
{

	class Agent : public Movable
	{
	public:
		Agent();
		virtual ~Agent();
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_AGENT_H_ */
