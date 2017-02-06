/*
 * TTBPointOfInterestntOfInterests.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#ifndef CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_
#define CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_

#include "SystemConfig.h"
#include "PointOfInterest.h"

namespace ttb {
class TTBWorldModel;
}

namespace ttb {
namespace wm {

class TTBPointOfInterestntOfInterests
{
public:
	TTBPointOfInterestntOfInterests(TTBWorldModel* wm);
	virtual ~TTBPointOfInterestntOfInterests();
	shared_ptr<PointOfInterest> getPointOfInterestByName(string name);
	shared_ptr<PointOfInterest> getPointOfInterestByID(int id);
	shared_ptr<PointOfInterest> getPointOfInterestByUnaryASPPredicate(string aspPredicate);
	shared_ptr<PointOfInterest> getCopyRoom();
	shared_ptr<PointOfInterest> getCopyRoomDoor1();
	shared_ptr<PointOfInterest> getCopyRoomDoor2();
	shared_ptr<PointOfInterest> getFloor1();
	shared_ptr<PointOfInterest> getFloor1Door1();
	shared_ptr<PointOfInterest> getFloor1Door2();
	shared_ptr<PointOfInterest> getFloor1Door3();
	shared_ptr<PointOfInterest> getFloor1Door4();
	shared_ptr<PointOfInterest> getFloor2Door1();
	shared_ptr<PointOfInterest> getFloor2Door2();
	shared_ptr<PointOfInterest> getFloor2Door3();
	shared_ptr<PointOfInterest> getFloor2Door4();
	shared_ptr<PointOfInterest> getFloor2Door5();
	shared_ptr<PointOfInterest> getFloor2Door6();
	shared_ptr<PointOfInterest> getFloor2Door7();
	shared_ptr<PointOfInterest> getFloor2Door8();
	shared_ptr<PointOfInterest> getFloor2Door9();
	shared_ptr<PointOfInterest> getFloor3Door1();
	shared_ptr<PointOfInterest> getFloor3Door2();
	shared_ptr<PointOfInterest> getFloor3Door3();
	shared_ptr<PointOfInterest> getFloor3Door4();
	shared_ptr<PointOfInterest> getFloor4();
	shared_ptr<PointOfInterest> getFloor4Door1();
	shared_ptr<PointOfInterest> getFloor4Door2();
	shared_ptr<PointOfInterest> getHiWiDoor1();
	shared_ptr<PointOfInterest> getHiWiDoor2();
	shared_ptr<PointOfInterest> getHiwiRoom();
	shared_ptr<PointOfInterest> getKicker();
	shared_ptr<PointOfInterest> getKitchen();
	shared_ptr<PointOfInterest> getMeetingRoom();
	shared_ptr<PointOfInterest> getRoom1403();
	shared_ptr<PointOfInterest> getRoom1403Door();
	shared_ptr<PointOfInterest> getRoom1406AFront();
	shared_ptr<PointOfInterest> getRoom1406AWindow();
	shared_ptr<PointOfInterest> getRoom1406BFront();
	shared_ptr<PointOfInterest> getRoom1406BWindow();
	shared_ptr<PointOfInterest> getRoom1406C();
	shared_ptr<PointOfInterest> getRoom1408A();
	shared_ptr<PointOfInterest> getRoom1408BFront();
	shared_ptr<PointOfInterest> getRoom1408BWindow();
	shared_ptr<PointOfInterest> getRoom1408CFront();
	shared_ptr<PointOfInterest> getRoom1408CWindow();
	shared_ptr<PointOfInterest> getSecreteriat();
	shared_ptr<PointOfInterest> getSecreteriatDoor1();
	shared_ptr<PointOfInterest> getSecreteriatDoor2();
	shared_ptr<PointOfInterest> getSecreteriatDoor3();
	shared_ptr<PointOfInterest> getStudentLab1();
	shared_ptr<PointOfInterest> getStudentLab2();
	shared_ptr<PointOfInterest> getStudentLabDoor1();
	shared_ptr<PointOfInterest> getStudentLabDoor2();
	shared_ptr<PointOfInterest> getWorkShopDoor1();
	shared_ptr<PointOfInterest> getWorkShopDoor2();
	shared_ptr<PointOfInterest> getWorkShopDoor3();
	shared_ptr<PointOfInterest> getWorkShopDoor4();
	shared_ptr<PointOfInterest> getWorkShopLeft();
	shared_ptr<PointOfInterest> getWorkShopRight();

private:
	TTBWorldModel* wm;
	::supplementary::SystemConfig* sc;
	void readPointOfInterests();
	vector<shared_ptr<PointOfInterest>> PointOfInterests;
	shared_ptr<PointOfInterest> floor1;
	shared_ptr<PointOfInterest> hiwiRoom;
	shared_ptr<PointOfInterest> studentLab1;
	shared_ptr<PointOfInterest> kicker;
	shared_ptr<PointOfInterest> studentLab2;
	shared_ptr<PointOfInterest> studentLabDoor1;
	shared_ptr<PointOfInterest> studentLabDoor2;
	shared_ptr<PointOfInterest> hiWiDoor1;
	shared_ptr<PointOfInterest> hiWiDoor2;
	shared_ptr<PointOfInterest> floor1Door1;
	shared_ptr<PointOfInterest> floor1Door2;
	shared_ptr<PointOfInterest> workShopDoor1;
	shared_ptr<PointOfInterest> workShopDoor2;
	shared_ptr<PointOfInterest> workShopDoor3;
	shared_ptr<PointOfInterest> workShopRight;
	shared_ptr<PointOfInterest> workShopDoor4;
	shared_ptr<PointOfInterest> workShopLeft;
	shared_ptr<PointOfInterest> floor1Door3;
	shared_ptr<PointOfInterest> floor2Door1;
	shared_ptr<PointOfInterest> floor2Door2;
	shared_ptr<PointOfInterest> room1408A;
	shared_ptr<PointOfInterest> floor2Door3;
	shared_ptr<PointOfInterest> room1408BFront;
	shared_ptr<PointOfInterest> room1408BWindow;
	shared_ptr<PointOfInterest> floor2Door4;
	shared_ptr<PointOfInterest> room1408CFront;
	shared_ptr<PointOfInterest> room1408CWindow;
	shared_ptr<PointOfInterest> floor2Door5;
	shared_ptr<PointOfInterest> room1406AFront;
	shared_ptr<PointOfInterest> room1406AWindow;
	shared_ptr<PointOfInterest> floor2Door6;
	shared_ptr<PointOfInterest> room1406BFront;
	shared_ptr<PointOfInterest> room1406BWindow;
	shared_ptr<PointOfInterest> floor2Door7;
	shared_ptr<PointOfInterest> floor2Door8;
	shared_ptr<PointOfInterest> room1406C;
	shared_ptr<PointOfInterest> floor2Door9;
	shared_ptr<PointOfInterest> floor3Door1;
	shared_ptr<PointOfInterest> floor3Door2;
	shared_ptr<PointOfInterest> floor1Door4;
	shared_ptr<PointOfInterest> kitchen;
	shared_ptr<PointOfInterest> floor4;
	shared_ptr<PointOfInterest> floor4Door1;
	shared_ptr<PointOfInterest> floor3Door3;
	shared_ptr<PointOfInterest> floor4Door2;
	shared_ptr<PointOfInterest> meetingRoom;
	shared_ptr<PointOfInterest> copyRoom;
	shared_ptr<PointOfInterest> copyRoomDoor1;
	shared_ptr<PointOfInterest> copyRoomDoor2;
	shared_ptr<PointOfInterest> secreteriatDoor1;
	shared_ptr<PointOfInterest> secreteriatDoor2;
	shared_ptr<PointOfInterest> floor3Door4;
	shared_ptr<PointOfInterest> secreteriatDoor3;
	shared_ptr<PointOfInterest> room1403Door;
	shared_ptr<PointOfInterest> room1403;
	shared_ptr<PointOfInterest> secreteriat;
};
}
}
#endif /* CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_ */
