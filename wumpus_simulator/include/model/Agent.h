/**
 * Agent interacting with the simulator
 */

#ifndef INCLUDE_MODEL_AGENT_H_
#define INCLUDE_MODEL_AGENT_H_

#include <model/Movable.h>
#include <memory>
#include "WumpusEnums.h"

using namespace std;

namespace wumpus_simulator
{

	class Agent : public Movable
	{
	public:
		Agent(shared_ptr<GroundTile> tile);
		virtual ~Agent();

		bool hasArrow();
		void setArrow(bool value);
		WumpusEnums::heading getHeading();
		void setHeading(WumpusEnums::heading heading);
		void setHasGold(bool value);
		bool getHasGold();


	private:
		bool arrow;
		bool hasGold;
		WumpusEnums::heading heading;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_AGENT_H_ */
