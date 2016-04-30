/*
 * TTBPointOfInterests.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#ifndef CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_POI_TTBPOINTOFINTERESTS_H_
#define CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_POI_TTBPOINTOFINTERESTS_H_

#include "SystemConfig.h"
#include "POI.h"

namespace ttb
{

	class TTBWorldModel;
	class TTBPointOfInterests
	{
	public:
		TTBPointOfInterests(TTBWorldModel* wm);
		virtual ~TTBPointOfInterests();
		 shared_ptr<POI> getCopyRoom();
		 shared_ptr<POI> getCopyRoomDoor1();
		 shared_ptr<POI> getCopyRoomDoor2();
		 shared_ptr<POI> getFloor1();
		 shared_ptr<POI> getFloor1Door1();
		 shared_ptr<POI> getFloor1Door2();
		 shared_ptr<POI> getFloor1Door3();
		 shared_ptr<POI> getFloor1Door4();
		 shared_ptr<POI> getFloor2Door1();
		 shared_ptr<POI> getFloor2Door2();
		 shared_ptr<POI> getFloor2Door3();
		 shared_ptr<POI> getFloor2Door4();
		 shared_ptr<POI> getFloor2Door5();
		 shared_ptr<POI> getFloor2Door6();
		 shared_ptr<POI> getFloor2Door7();
		 shared_ptr<POI> getFloor2Door8();
		 shared_ptr<POI> getFloor2Door9();
		 shared_ptr<POI> getFloor3Door1();
		 shared_ptr<POI> getFloor3Door2();
		 shared_ptr<POI> getFloor3Door3();
		 shared_ptr<POI> getFloor3Door4();
		 shared_ptr<POI> getFloor4();
		 shared_ptr<POI> getFloor4Door1();
		 shared_ptr<POI> getFloor4Door2();
		 shared_ptr<POI> getHiWiDoor1();
		 shared_ptr<POI> getHiWiDoor2();
		 shared_ptr<POI> getHiwiRoom();
		 shared_ptr<POI> getKicker();
		 shared_ptr<POI> getKitchen();
		 shared_ptr<POI> getMeetingRoom();
		 shared_ptr<POI> getRoom1403();
		 shared_ptr<POI> getRoom1403Door();
		 shared_ptr<POI> getRoom1406AFront();
		 shared_ptr<POI> getRoom1406AWindow();
		 shared_ptr<POI> getRoom1406BFront();
		 shared_ptr<POI> getRoom1406BWindow();
		 shared_ptr<POI> getRoom1406C();
		 shared_ptr<POI> getRoom1408A();
		 shared_ptr<POI> getRoom1408BFront();
		 shared_ptr<POI> getRoom1408BWindow();
		 shared_ptr<POI> getRoom1408CFront();
		 shared_ptr<POI> getRoom1408CWindow();
		 shared_ptr<POI> getSecreteriat();
		 shared_ptr<POI> getSecreteriatDoor1();
		 shared_ptr<POI> getSecreteriatDoor2();
		 shared_ptr<POI> getSecreteriatDoor3();
		 shared_ptr<POI> getStudentLab1();
		 shared_ptr<POI> getStudentLab2();
		 shared_ptr<POI> getStudentLabDoor1();
		 shared_ptr<POI> getStudentLabDoor2();
		 shared_ptr<POI> getWorkShopDoor1();
		 shared_ptr<POI> getWorkShopDoor2();
		 shared_ptr<POI> getWorkShopDoor3();
		 shared_ptr<POI> getWorkShopDoor4();
		 shared_ptr<POI> getWorkShopLeft();
		 shared_ptr<POI> getWorkShopRight();

	private:
		TTBWorldModel* wm;
		supplementary::SystemConfig* sc;
		void readPOIs();
		shared_ptr<POI> floor1;
		shared_ptr<POI> hiwiRoom;
		shared_ptr<POI> studentLab1;
		shared_ptr<POI> kicker;
		shared_ptr<POI> studentLab2;
		shared_ptr<POI> studentLabDoor1;
		shared_ptr<POI> studentLabDoor2;
		shared_ptr<POI> hiWiDoor1;
		shared_ptr<POI> hiWiDoor2;
		shared_ptr<POI> floor1Door1;
		shared_ptr<POI> floor1Door2;
		shared_ptr<POI> workShopDoor1;
		shared_ptr<POI> workShopDoor2;
		shared_ptr<POI> workShopDoor3;
		shared_ptr<POI> workShopRight;
		shared_ptr<POI> workShopDoor4;
		shared_ptr<POI> workShopLeft;
		shared_ptr<POI> floor1Door3;
		shared_ptr<POI> floor2Door1;
		shared_ptr<POI> floor2Door2;
		shared_ptr<POI> room1408A;
		shared_ptr<POI> floor2Door3;
		shared_ptr<POI> room1408BFront;
		shared_ptr<POI> room1408BWindow;
		shared_ptr<POI> floor2Door4;
		shared_ptr<POI> room1408CFront;
		shared_ptr<POI> room1408CWindow;
		shared_ptr<POI> floor2Door5;
		shared_ptr<POI> room1406AFront;
		shared_ptr<POI> room1406AWindow;
		shared_ptr<POI> floor2Door6;
		shared_ptr<POI> room1406BFront;
		shared_ptr<POI> room1406BWindow;
		shared_ptr<POI> floor2Door7;
		shared_ptr<POI> floor2Door8;
		shared_ptr<POI> room1406C;
		shared_ptr<POI> floor2Door9;
		shared_ptr<POI> floor3Door1;
		shared_ptr<POI> floor3Door2;
		shared_ptr<POI> floor1Door4;
		shared_ptr<POI> kitchen;
		shared_ptr<POI> floor4;
		shared_ptr<POI> floor4Door1;
		shared_ptr<POI> floor3Door3;
		shared_ptr<POI> floor4Door2;
		shared_ptr<POI> meetingRoom;
		shared_ptr<POI> copyRoom;
		shared_ptr<POI> copyRoomDoor1;
		shared_ptr<POI> copyRoomDoor2;
		shared_ptr<POI> secreteriatDoor1;
		shared_ptr<POI> secreteriatDoor2;
		shared_ptr<POI> floor3Door4;
		shared_ptr<POI> secreteriatDoor3;
		shared_ptr<POI> room1403Door;
		shared_ptr<POI> room1403;
		shared_ptr<POI> secreteriat;
	};
}
#endif /* CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_POI_TTBPOINTOFINTERESTS_H_ */
