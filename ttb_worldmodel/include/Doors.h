/*
 * Doors.h
 *
 *  Created on: Oct 11, 2016
 *      Author: stefan
 */

#ifndef SRC_DOORS_H_
#define SRC_DOORS_H_

#include "SystemConfig.h"

namespace ttb {
	class TTBWorldModel;
}

namespace ttb { namespace wm
{


	class Doors
	{
	public:
		Doors(TTBWorldModel* wm);
		virtual ~Doors();
		void openDoor(string doorPredicate);
		void closeDoor(string doorPredicate);
		shared_ptr<map<string, bool>> getDoors();

	private:
		void changeDoorValue(string doorPredicate, bool value);
		TTBWorldModel* wm;
		supplementary::SystemConfig* sc;
		void readDoors();
		void readDoor(string door);

		shared_ptr<map<string, bool>> doors;
	};
}}

#endif /* SRC_DOORS_H_ */
