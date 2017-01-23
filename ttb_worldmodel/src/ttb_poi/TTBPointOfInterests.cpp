/*
 * TTBPointOfInterests.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#include <ttb_poi/TTBPointOfInterests.h>

namespace ttb {
namespace wm {
TTBPointOfInterests::TTBPointOfInterests(TTBWorldModel* wm)
{
	this->wm = wm;
	this->sc = supplementary::SystemConfig::getInstance();
	this->readPOIs();
}

TTBPointOfInterests::~TTBPointOfInterests()
{
}

shared_ptr<POI> TTBPointOfInterests::getPOIByName(string name)
{
	shared_ptr<POI> ret = nullptr;
	for (auto poi : this->pois)
	{
		if (poi->name.compare(name) == 0)
		{
			ret = poi;
			break;
		}
	}
	return ret;
}

shared_ptr<POI> TTBPointOfInterests::getPOIByID(int id)
{
	shared_ptr<POI> ret = nullptr;
	for (auto poi : this->pois)
	{
		if (poi->id == id)
		{
			ret = poi;
			break;
		}
	}
	return ret;
}

shared_ptr<POI> TTBPointOfInterests::getPOIByUnaryASPPredicate(string aspPredicate)
{

	size_t start = aspPredicate.find("(");
	size_t end = aspPredicate.find(")", start);
	string p = aspPredicate.substr(start + 1, end - start - 1);

	shared_ptr<POI> ret = nullptr;
	for (auto poi : this->pois)
	{
		if (poi->name.compare(p) == 0)
		{
			ret = poi;
			break;
		}
	}
	return ret;
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

void TTBPointOfInterests::readPOIs()
{
	string currentPoi = "floor1";
	this->floor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor1);

	currentPoi = "hiwiRoom";
	this->hiwiRoom =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->hiwiRoom);

	currentPoi = "studentLab1";
	this->studentLab1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->studentLab1);

	currentPoi = "kicker";
	this->kicker =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->kicker);

	currentPoi = "studentLab2";
	this->studentLab2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->studentLab2);

	currentPoi = "studentLabDoor1";
	this->studentLabDoor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->studentLabDoor1);

	currentPoi = "studentLabDoor2";
	this->studentLabDoor2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->studentLabDoor2);

	currentPoi = "hiWiDoor1";
	this->hiWiDoor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->hiWiDoor1);

	currentPoi = "hiWiDoor2";
	this->hiWiDoor2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->hiWiDoor2);

	currentPoi = "floor1Door1";
	this->floor1Door1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor1Door1);

	currentPoi = "floor1Door2";
	this->floor1Door2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor1Door2);

	currentPoi = "workShopDoor1";
	this->workShopDoor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopDoor1);

	currentPoi = "workShopDoor2";
	this->workShopDoor2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopDoor2);

	currentPoi = "workShopDoor3";
	this->workShopDoor3 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopDoor3);

	currentPoi = "workShopRight";
	this->workShopRight =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopRight);

	currentPoi = "workShopDoor4";
	this->workShopDoor4 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopDoor4);

	currentPoi = "workShopLeft";
	this->workShopLeft =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->workShopLeft);

	currentPoi = "floor1Door3";
	this->floor1Door3 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor1Door3);

	currentPoi = "floor2Door1";
	this->floor2Door1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door1);

	currentPoi = "floor2Door2";
	this->floor2Door2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door2);

	currentPoi = "room1408A";
	this->room1408A =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1408A);

	currentPoi = "floor2Door3";
	this->floor2Door3 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door3);

	currentPoi = "room1408BFront";
	this->room1408BFront =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1408BFront);

	currentPoi = "room1408BWindow";
	this->room1408BWindow =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1408BWindow);

	currentPoi = "floor2Door4";
	this->floor2Door4 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door4);

	currentPoi = "room1408CFront";
	this->room1408CFront =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1408CFront);

	currentPoi = "room1408CWindow";
	this->room1408CWindow =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));

	currentPoi = "floor2Door5";
	this->floor2Door5 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door5);

	currentPoi = "room1406AFront";
	this->room1406AFront =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1406AFront);

	currentPoi = "room1406AWindow";
	this->room1406AWindow =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1406AWindow);

	currentPoi = "floor2Door6";
	this->floor2Door6 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door6);

	currentPoi = "room1406BFront";
	this->room1406BFront =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1406BFront);

	currentPoi = "room1406BWindow";
	this->room1406BWindow =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1406BWindow);

	currentPoi = "floor2Door7";
	this->floor2Door7 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door7);

	currentPoi = "floor2Door8";
	this->floor2Door8 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door8);

	currentPoi = "room1406C";
	this->room1406C =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1406C);

	currentPoi = "floor2Door9";
	this->floor2Door9 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor2Door9);

	currentPoi = "floor3Door1";
	this->floor3Door1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor3Door1);

	currentPoi = "floor3Door2";
	this->floor3Door2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor3Door2);

	currentPoi = "floor1Door4";
	this->floor1Door4 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor1Door4);

	currentPoi = "kitchen";
	this->kitchen =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->kitchen);

	currentPoi = "floor4";
	this->floor4 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor4);

	currentPoi = "floor4Door1";
	this->floor4Door1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor4Door1);

	currentPoi = "floor3Door3";
	this->floor3Door3 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor3Door3);

	currentPoi = "floor4Door2";
	this->floor4Door2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor4Door2);

	currentPoi = "meetingRoom";
	this->meetingRoom =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->meetingRoom);

	currentPoi = "copyRoom";
	this->copyRoom =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->copyRoom);

	currentPoi = "copyRoomDoor1";
	this->copyRoomDoor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->copyRoomDoor1);

	currentPoi = "copyRoomDoor2";
	this->copyRoomDoor2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->copyRoomDoor2);

	currentPoi = "secreteriatDoor1";
	this->secreteriatDoor1 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->secreteriatDoor1);

	currentPoi = "secreteriatDoor2";
	this->secreteriatDoor2 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->secreteriatDoor2);

	currentPoi = "floor3Door4";
	this->floor3Door4 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->floor3Door4);

	currentPoi = "secreteriatDoor3";
	this->secreteriatDoor3 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->secreteriatDoor3);

	currentPoi = "room1403Door";
	this->room1403Door =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1403Door);

	currentPoi = "room1403";
	this->room1403 =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->room1403);

	currentPoi = "secreteriat";
	this->secreteriat =
			make_shared < POI
					> ((*this->sc)["POI"]->get<int>("POI.Points", currentPoi.c_str(), "ID", NULL), currentPoi.c_str(), (*this->sc)["POI"]->get<
							float>("POI.Points", currentPoi.c_str(), "X", NULL), (*this->sc)["POI"]->get<float>(
							"POI.Points", currentPoi.c_str(), "Y", NULL));
	this->pois.push_back(this->secreteriat);
}
}
}

