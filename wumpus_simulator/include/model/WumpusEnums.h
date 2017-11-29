/**
 * Collection of all enums used in the simulator
 */

#ifndef INCLUDE_MODEL_WUMPUSENUMS_H_
#define INCLUDE_MODEL_WUMPUSENUMS_H_

class WumpusEnums
{
public:
	/**
	 * Possible action an agent can perform
	 */
	enum actions
	{
		move, turnLeft, turnRight, shoot, pickUpGold, leave
	};

	/**
	 * Responses given from the simulator according to the actions
	 */
	enum responses
	{
		bump, scream, silence, goldFound, exited, notAllowed, drafty, stinky, shiny, dead, otherAgent, killedAgent, yourTurn
	};

	/**
	 * Orientation of agent and movement direction for wumpus
	 */
	enum heading
	{
		up, left, down, right
	};
};

#endif /* INCLUDE_MODEL_WUMPUSENUMS_H_ */
