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
	enum actions {move, turnLeft, turnRight, shoot, pickUpGold, exit};

	enum responses {bump, scream, silence, goldFound, exited, notAllowed};
};

#endif /* INCLUDE_MODEL_WUMPUSENUMS_H_ */
