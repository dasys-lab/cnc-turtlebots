/*
 * TTBPointOfInterestntOfInterests.h
 *
 *  Created on: Apr 30, 2016
 *      Author: Stefan Jakob
 */

#ifndef CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_
#define CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_

#include "SystemConfig.h"
#include "tasks/PointOfInterest.h"

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
#endif /* CNC_TURTLEBOTS_TTB_WORLDMODEL_INCLUDE_TTB_PointOfInterest_TTBPointOfInterestNTOFINTERESTS_H_ */
