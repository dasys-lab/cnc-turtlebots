#include "TopologicalInfoPublisher.h"
#include <ttb_msgs/TopologicalInfo.h>
#include <TTBWorldModel.h>
#include <supplementary/AgentID.h>
#include <topology/Door.h>
#include <SystemConfig.h>

namespace ttb
{
namespace wm
{

TopologicalInfoPublisher::TopologicalInfoPublisher(ttb::TTBWorldModel *wm)
    : supplementary::Worker("TopologicalInfoPublisher")
    , wm(wm)
{
	supplementary::SystemConfig* sc = supplementary::SystemConfig::getInstance();
	ros::NodeHandle n;
	this->topoInfoPub = n.advertise<ttb_msgs::TopologicalInfo>((*sc)["TTBWorldModel"]->get<std::string>("Debug.TopologicalInfoPublisher.Topic",NULL), 10);
}

TopologicalInfoPublisher::~TopologicalInfoPublisher()
{
}

void TopologicalInfoPublisher::run()
{
    ttb_msgs::TopologicalInfo info;
    info.sender.id = this->wm->getOwnId()->toByteVector();
    auto room = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (room)
    {
    	info.ownRoom = room.value()->name;
    }

    for (auto door : this->wm->topologicalModel.getDoors())
    {
    	info.openDoors.push_back(door->name);
    }
    this->topoInfoPub.publish(info);
}

} /* namespace wm */
} /* namespace ttb */
