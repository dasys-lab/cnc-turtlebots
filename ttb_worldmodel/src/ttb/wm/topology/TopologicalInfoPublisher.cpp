#include "ttb/wm/topology/TopologicalInfoPublisher.h"

#include "ttb/TTBWorldModel.h"
#include "ttb/wm/topology/Door.h"

#include <SystemConfig.h>
#include <essentials/Identifier.h>
#include <ttb_msgs/TopologicalInfo.h>

namespace ttb
{
namespace wm
{

TopologicalInfoPublisher::TopologicalInfoPublisher(ttb::TTBWorldModel* wm)
        : essentials::Worker("TopologicalInfoPublisher")
        , wm(wm)
{
    essentials::SystemConfig* sc = essentials::SystemConfig::getInstance();
    ros::NodeHandle n;
    this->topoInfoPub = n.advertise<ttb_msgs::TopologicalInfo>((*sc)["TTBWorldModel"]->get<std::string>("Debug.TopologicalInfoPublisher.Topic", NULL), 10);
}

TopologicalInfoPublisher::~TopologicalInfoPublisher() {}

void TopologicalInfoPublisher::run()
{
    ttb_msgs::TopologicalInfo info;
    info.sender.id = this->wm->getOwnId()->toByteVector();
    auto room = this->wm->topologicalLocalization.getRoomBuffer()->getLastValidContent();
    if (room) {
        info.ownRoom = room.value()->name;
    }

    for (auto door : this->wm->topologicalModel.getDoors()) {
        if (door->open) {
            info.openDoors.push_back(door->name);
        }
    }
    this->topoInfoPub.publish(info);
}

} /* namespace wm */
} /* namespace ttb */
