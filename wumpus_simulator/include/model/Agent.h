/*
 * Agent.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_AGENT_H_
#define INCLUDE_MODEL_AGENT_H_

#include <model/Movable.h>
#include <memory>

using namespace std;

namespace wumpus_simulator
{

	class Agent : public Movable
	{
	public:
		Agent(shared_ptr<GroundTile> tile);
		virtual ~Agent();

		int getAgentID();
		void setAgentID(int value);
		bool hasArrow();
		void setArrow(bool value);

	private:
		int agentID;
		bool arrow;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_AGENT_H_ */
