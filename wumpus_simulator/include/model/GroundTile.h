/*
 * GroundTile.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_GROUNDTILE_H_
#define INCLUDE_MODEL_GROUNDTILE_H_

namespace wumpus_simulator
{

	class GroundTile
	{
	public:
		GroundTile(int x, int y);
		virtual ~GroundTile();
		int getX();
		int getY();

	private :
		int x;
		int y;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_GROUNDTILE_H_ */
