/*
 * TTBPointOfInterests.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#include <ttb_poi/TTBPointOfInterests.h>

namespace ttb
{
namespace wm
{
TTBPointOfInterests::TTBPointOfInterests(TTBWorldModel *wm)
{
    this->wm = wm;
    this->sc = supplementary::SystemConfig::getInstance();
    auto poiSections = (*this->sc)["POI"]->getSections("POI.Points", NULL);
	for (auto &poiSectionName : (*poiSections))
	{
		shared_ptr<PointOfInterest> currentPOI = make_shared<PointOfInterest>((*this->sc)["POI"]->get<int>("POI.Points", poiSectionName.c_str(), "ID", NULL), poiSectionName,
								   (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "X", NULL),
								   (*this->sc)["POI"]->get<float>("POI.Points", poiSectionName.c_str(), "Y", NULL));
		this->pois.push_back(currentPOI);
	}
}

TTBPointOfInterests::~TTBPointOfInterests()
{
}

shared_ptr<PointOfInterest> TTBPointOfInterests::getPOIByName(string name)
{
    shared_ptr<PointOfInterest> ret = nullptr;
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

shared_ptr<PointOfInterest> TTBPointOfInterests::getPOIByID(int id)
{
    shared_ptr<PointOfInterest> ret = nullptr;
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

shared_ptr<PointOfInterest> TTBPointOfInterests::getPOIByUnaryASPPredicate(string aspPredicate)
{

    size_t start = aspPredicate.find("(");
    size_t end = aspPredicate.find(")", start);
    string name = aspPredicate.substr(start + 1, end - start - 1);

    return this->getPOIByName(name);
}
}
}
