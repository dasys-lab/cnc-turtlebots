#include "TopologicalLocalization.h"

#include "TTBWorldModel.h"
#include "LogicalCameraData.h"

#include <memory>


namespace ttb
{
namespace wm
{

TopologicalLocalization::TopologicalLocalization(ttb::TTBWorldModel* wm)
    : supplementary::Worker("TopologicalLocalizationWorker")
	, wm(wm)

{
	//TODO: make the worldmodel run the timer of the localization
}

TopologicalLocalization::~TopologicalLocalization()
{
}

void TopologicalLocalization::run()
{
	auto pois = this->wm->logicalCameraData.getObjectOfType("poi");
	std::vector<std::shared_ptr<LogicalObject>> currentPOIs;
	supplementary::InfoTime maxDiff = 10000000000;
	for (auto poi : pois)
	{
//		auto pose = poi->getPoseBuffer()->getTemporalCloseTo(wm->getTime(), maxDiff);
//		if (pose)
//		{
//			currentPOIs.push_back(poi);
//		}
	}

	//TODO: make some debug output here and implement further stuff


}

} /* namespace wm */
} /* namespace ttb */
