/*
 * ActionEnum.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Lab User 5
 */

#ifndef INCLUDE_MODEL_WUMPUSENUMS_H_
#define INCLUDE_MODEL_WUMPUSENUMS_H_

class WumpusEnums
{
public:
	enum actions
	{
		move, turnLeft, turnRight, shoot, pickUpGold, leave
	};

	enum responses
	{
		bump, scream, silence, goldFound, exited, notAllowed, drafty, stinky, shiny, dead, otherAgent, killedAgent, yourTurn
	};

	enum heading
	{
		up, left, down, right
	};
};

#endif /* INCLUDE_MODEL_WUMPUSENUMS_H_ */
