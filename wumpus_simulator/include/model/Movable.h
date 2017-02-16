/**
 * Interface for every object that can be moved from outside the simulator
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
		int getId();
		void setId(int id);

	protected:
		int id;
		shared_ptr<GroundTile> tile;
		QString type;
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_MOVABLE_H_ */
