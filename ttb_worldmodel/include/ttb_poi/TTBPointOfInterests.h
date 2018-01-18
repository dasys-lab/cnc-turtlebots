#pragma once

#include "SystemConfig.h"
#include "ttb_poi/PointOfInterest.h"

namespace ttb {
class TTBWorldModel;
}

namespace ttb {
namespace wm {

class TTBPointOfInterests
{
public:
	TTBPointOfInterests(TTBWorldModel* wm);
	virtual ~TTBPointOfInterests();
	shared_ptr<PointOfInterest> getPOIByName(string name);
	shared_ptr<PointOfInterest> getPOIByID(int id);
	shared_ptr<PointOfInterest> getPOIByUnaryASPPredicate(string aspPredicate);

private:
	TTBWorldModel* wm;
	::supplementary::SystemConfig* sc;
	vector<shared_ptr<PointOfInterest>> pois;
};
}
}
