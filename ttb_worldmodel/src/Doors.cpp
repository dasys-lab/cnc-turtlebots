/*
 * Doors.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: stefan
 */

#include "Doors.h"


namespace ttb
{
	Doors::Doors(TTBWorldModel* wm)
	{
		this->wm = wm;
		this->sc = supplementary::SystemConfig::getInstance();
		this->readDoors();
		this->doors = make_shared<map<string, bool>>();

	}

	Doors::~Doors()
	{
		// TODO Auto-generated destructor stub
	}

	void Doors::readDoors()
	{
		this->readDoor("doorClosed(studentArea, mainHallA)");
		this->readDoor("doorClosed(r1411, studentArea)");
		this->readDoor("doorClosed(r1411A, studentArea)");
		this->readDoor("doorClosed(r1411C, studentArea)");
		this->readDoor("doorClosed(r1411, r1411C)");
		this->readDoor("doorClosed(r1411A, r1411C)");
		this->readDoor("doorClosed(workshop, mainHallA)");
		this->readDoor("doorClosed(r1410, workshop)");
		this->readDoor("doorClosed(r1410A, workshop)");
		this->readDoor("doorClosed(r1410B, workshop)");
		this->readDoor("doorClosed(r1410, r1410A)");
		this->readDoor("doorClosed(r1410, r1410B)");
		this->readDoor("doorClosed(offices, mainHallA)");
		this->readDoor("doorClosed(offices, mainHallB)");
		this->readDoor("doorClosed(offices, utility)");
		this->readDoor("doorClosed(r1407, offices)");
		this->readDoor("doorClosed(r1408A, offices)");
		this->readDoor("doorClosed(r1408B, offices)");
		this->readDoor("doorClosed(r1408C, offices)");
		this->readDoor("doorClosed(r1406A, offices)");
		this->readDoor("doorClosed(r1406B, offices)");
		this->readDoor("doorClosed(r1406C, offices)");
		this->readDoor("doorClosed(r1407, r1408A)");
		this->readDoor("doorClosed(r1407, r1408B)");
		this->readDoor("doorClosed(r1407, r1408C)");
		this->readDoor("doorClosed(r1407, r1406A)");
		this->readDoor("doorClosed(r1407, r1406B)");
		this->readDoor("doorClosed(r1407, r1406C)");
		this->readDoor("doorClosed(mainHallA, studentArea)");
		this->readDoor("doorClosed(mainHallA, mainHallB)");
		this->readDoor("doorClosed(mainHallA, workshop)");
		this->readDoor("doorClosed(mainHallB, mainHallA)");
		this->readDoor("doorClosed(mainHallB, offices)");
		this->readDoor("doorClosed(mainHallB, utility)");
		this->readDoor("doorClosed(mainHallB, organization)");
		this->readDoor("doorClosed(utility, mainHallB)");
		this->readDoor("doorClosed(utility, organization)");
		this->readDoor("doorClosed(utility, offices)");
		this->readDoor("doorClosed(r1405, utility)");
		this->readDoor("doorClosed(r1405A, utility)");
		this->readDoor("doorClosed(r1405B, utility)");
		this->readDoor("doorClosed(r1403C, utility)");
		this->readDoor("doorClosed(r1405, r1405A)");
		this->readDoor("doorClosed(r1405A, r1405B)");
		this->readDoor("doorClosed(r1405A, r1403C)");
		this->readDoor("doorClosed(organization, mainHallB)");
		this->readDoor("doorClosed(organization, utility)");
		this->readDoor("doorClosed(r1403, organization)");
		this->readDoor("doorClosed(r1403A, organization)");
		this->readDoor("doorClosed(r1403B, organization)");
		this->readDoor("doorClosed(r1403A, r1403B)");
		this->readDoor("doorClosed(r1403B, r1403)");

	}

	void Doors::openDoor(string doorPredicate)
	{
		changeDoorValue(doorPredicate, false);
	}

	void Doors::closeDoor(string doorPredicate)
	{
		changeDoorValue(doorPredicate, true);
	}

	void Doors::changeDoorValue(string doorPredicate, bool value)
	{
		for(auto pair : *(this->doors))
		{
			if(pair.first.compare(doorPredicate) == 0)
			{
				pair.second = value;
				break;
			}
		}
	}

	void Doors::readDoor(string door)
	{
		stringstream ss;
		ss << "Externals." << door;

		this->doors->insert(
				pair<string, bool>(door, (*sc)["External"]->get<bool>(ss.str().c_str(), NULL)));
	}

	shared_ptr<map<string, bool> > Doors::getDoors()
	{
		return doors;
	}
}


