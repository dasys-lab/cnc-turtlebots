/*
 * Movable.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_MOVABLE_H_
#define INCLUDE_MODEL_MOVABLE_H_

#include <memory>
#include "GroundTile.h"
#include <QString>

using namespace std;

namespace wumpus_simulator
{

	class Movable
	{
	public:
		Movable();
		virtual ~Movable();
		QString getType();
		shared_ptr<GroundTile> getTile();
		void setTile(shared_ptr<GroundTile> tile);

	protected:
		shared_ptr<GroundTile> tile;
		QString type;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_MOVABLE_H_ */
