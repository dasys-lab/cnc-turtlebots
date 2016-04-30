/*
 * TTBPointOfInterests.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#include <ttb_poi/TTBPointOfInterests.h>

namespace ttb
{
	TTBPointOfInterests::TTBPointOfInterests(TTBWorldModel* wm)
	{
		this->wm = wm;
		this->sc = supplementary::SystemConfig::getInstance();
		this->readPOIs();
	}

	TTBPointOfInterests::~TTBPointOfInterests()
	{
	}

	shared_ptr<POI> TTBPointOfInterests::getCopyRoom()
	{
		return this->copyRoom;
	}

	shared_ptr<POI> TTBPointOfInterests::getCopyRoomDoor1()
	{
		return this->copyRoomDoor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getCopyRoomDoor2()
	{
		return this->copyRoomDoor2;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor1()
	{
		return this->floor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor1Door1()
	{
		return this->floor1Door1;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor1Door2()
	{
		return this->floor1Door2;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor1Door3()
	{
		return this->floor1Door3;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor1Door4()
	{
		return this->floor1Door4;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door1()
	{
		return this->floor2Door1;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door2()
	{
		return this->floor2Door2;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door3()
	{
		return this->floor2Door3;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door4()
	{
		return this->floor2Door4;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door5()
	{
		return this->floor2Door5;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door6()
	{
		return this->floor2Door6;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door7()
	{
		return this->floor2Door7;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door8()
	{
		return this->floor2Door8;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor2Door9()
	{
		return this->floor2Door9;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor3Door1()
	{
		return this->floor3Door1;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor3Door2()
	{
		return this->floor3Door2;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor3Door3()
	{
		return this->floor3Door3;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor3Door4()
	{
		return this->floor3Door4;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor4()
	{
		return this->floor4;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor4Door1()
	{
		return this->floor4Door1;
	}

	shared_ptr<POI> TTBPointOfInterests::getFloor4Door2()
	{
		return this->floor4Door2;
	}

	shared_ptr<POI> TTBPointOfInterests::getHiWiDoor1()
	{
		return this->hiWiDoor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getHiWiDoor2()
	{
		return this->hiWiDoor2;
	}

	shared_ptr<POI> TTBPointOfInterests::getHiwiRoom()
	{
		return this->hiwiRoom;
	}

	shared_ptr<POI> TTBPointOfInterests::getKicker()
	{
		return this->kicker;
	}

	shared_ptr<POI> TTBPointOfInterests::getKitchen()
	{
		return this->kitchen;
	}

	shared_ptr<POI> TTBPointOfInterests::getMeetingRoom()
	{
		return this->meetingRoom;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1403()
	{
		return this->room1403;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1403Door()
	{
		return this->room1403Door;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1406AFront()
	{
		return this->room1406AFront;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1406AWindow()
	{
		return this->room1406AWindow;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1406BFront()
	{
		return this->room1406BFront;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1406BWindow()
	{
		return this->room1406BWindow;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1406C()
	{
		return this->room1406C;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1408A()
	{
		return this->room1408A;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1408BFront()
	{
		return this->room1408BFront;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1408BWindow()
	{
		return this->room1408BWindow;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1408CFront()
	{
		return this->room1408CFront;
	}

	shared_ptr<POI> TTBPointOfInterests::getRoom1408CWindow()
	{
		return this->room1408CWindow;
	}

	shared_ptr<POI> TTBPointOfInterests::getSecreteriat()
	{
		return this->secreteriat;
	}

	shared_ptr<POI> TTBPointOfInterests::getSecreteriatDoor1()
	{
		return this->secreteriatDoor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getSecreteriatDoor2()
	{
		return this->secreteriatDoor2;
	}

	shared_ptr<POI> TTBPointOfInterests::getSecreteriatDoor3()
	{
		return this->secreteriatDoor3;
	}

	shared_ptr<POI> TTBPointOfInterests::getStudentLab1()
	{
		return this->studentLab1;
	}

	shared_ptr<POI> TTBPointOfInterests::getStudentLab2()
	{
		return this->studentLab2;
	}

	shared_ptr<POI> TTBPointOfInterests::getStudentLabDoor1()
	{
		return this->studentLabDoor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getStudentLabDoor2()
	{
		return this->studentLabDoor2;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopDoor1()
	{
		return this->workShopDoor1;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopDoor2()
	{
		return this->workShopDoor2;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopDoor3()
	{
		return this->workShopDoor3;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopDoor4()
	{
		return this->workShopDoor4;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopLeft()
	{
		return this->workShopLeft;
	}

	shared_ptr<POI> TTBPointOfInterests::getWorkShopRight()
	{
		return this->workShopRight;
	}

	void ttb::TTBPointOfInterests::readPOIs()
	{
		string currentPoi = "Floor1";
		this->floor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "HiwiRoom";
		this->hiwiRoom = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "StudentLab1";
		this->studentLab1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Kicker";
		this->kicker = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "StudentLab2";
		this->studentLab2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "StudentLabDoor1";
		this->studentLabDoor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "studentLabDoor2";
		this->studentLabDoor2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "HiWiDoor1";
		this->hiWiDoor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "HiWiDoor2";
		this->hiWiDoor2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor1Door1";
		this->floor1Door1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor1Door2";
		this->floor1Door2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopDoor1";
		this->workShopDoor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopDoor2";
		this->workShopDoor2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopDoor3";
		this->workShopDoor3 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopRight";
		this->workShopRight = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopDoor4";
		this->workShopDoor4 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "WorkShopLeft";
		this->workShopLeft = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor1Door3";
		this->floor1Door3 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door1";
		this->floor2Door1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door2";
		this->floor2Door2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1408A";
		this->room1408A = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door3";
		this->floor2Door3 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1408BFront";
		this->room1408BFront = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1408BWindow";
		this->room1408BWindow = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door4";
		this->floor2Door4 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1408CFront";
		this->room1408CFront = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1408CWindow";
		this->room1408CWindow = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door5";
		this->floor2Door5 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1406AFront";
		this->room1406AFront = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1406AWindow";
		this->room1406AWindow = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door6";
		this->floor2Door6 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1406BFront";
		this->room1406BFront = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1406BWindow";
		this->room1406BWindow = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door7";
		this->floor2Door7 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door8";
		this->floor2Door8 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1406C";
		this->room1406C = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor2Door9";
		this->floor2Door9 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor3Door1";
		this->floor3Door1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor3Door2";
		this->floor3Door2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor1Door4";
		this->floor1Door4 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Kitchen";
		this->kitchen = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor4";
		this->floor4 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL),	currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor4Door1";
		this->floor4Door1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor3Door3";
		this->floor3Door3 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor4Door2";
		this->floor4Door2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "MeetingRoom";
		this->meetingRoom = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "CopyRoom";
		this->copyRoom = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "CopyRoomDoor1";
		this->copyRoomDoor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "CopyRoomDoor2";
		this->copyRoomDoor2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "SecreteriatDoor1";
		this->secreteriatDoor1 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "SecreteriatDoor2";
		this->secreteriatDoor2 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Floor3Door4";
		this->floor3Door4 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "SecreteriatDoor3";
		this->secreteriatDoor3 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1403Door";
		this->room1403Door = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Room1403";
		this->room1403 = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));

		currentPoi = "Secreteriat";
		this->secreteriat = make_shared<POI>(
				(*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "X", NULL),
				(*this->sc)["POI"]->get<float>("POI.Points", currentPoi.c_str(), "Y", NULL));
	}
}

