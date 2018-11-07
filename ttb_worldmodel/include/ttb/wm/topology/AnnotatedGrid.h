#pragma once

#include "ttb/wm/topology/AnnotatedGridPoint.h"

#include "ttb/TTBWorldModel.h"

#include <cnc_geometry/CNPointAllo.h>
#include <ttb_msgs/AnnotatedGrid.h>
#include <ttb_msgs/Grid.h>

#include <ros/ros.h>

#include <map>
#include <string>
#include <vector>

namespace ttb
{
namespace wm
{

/**
 * Used for getting a set of search points for sweeping through an area, in order to search some items in it.
 */
class AnnotatedGrid
{
public:
    AnnotatedGrid(ttb::TTBWorldModel* wm);
    virtual ~AnnotatedGrid();
    void receiveAnnotatedGridPoints(ttb_msgs::AnnotatedGridPtr annotatedGrid);

private:
    void sendGridPoints();
    std::vector<geometry::CNPointAllo> generateGridPoints();
    std::vector<ttb::wm::AnnotatedGridPoint> getGridOfRoom(std::shared_ptr<ttb::wm::Room> room);
    ros::Subscriber annotatedGridSubscriber;
    ros::Publisher gridPublisher;
    std::map<std::shared_ptr<ttb::wm::Room>, std::vector<AnnotatedGridPoint>> gridMap;
    ttb::TTBWorldModel* wm;
};

} /* namespace wm */
} /* namespace ttb */
