#include "ttb/wm/topology/AnnotatedGrid.h"
#include <SystemConfig.h>
#include <iostream>

namespace ttb
{
namespace wm
{

AnnotatedGrid::AnnotatedGrid(ttb::TTBWorldModel *wm)
    : wm(wm)
{
    auto sc = supplementary::SystemConfig::getInstance();
    std::string annotatedGridTopic = (*sc)["TTBWorldModel"]->get<std::string>("AnnotatedGrid.annotatedGridTopic", NULL);
    std::string gridTopic = (*sc)["TTBWorldModel"]->get<std::string>("AnnotatedGrid.gridTopic", NULL);
    ros::NodeHandle n;
    this->annotatedGridSubscriber =
        n.subscribe(annotatedGridTopic, 10, &AnnotatedGrid::receiveAnnotatedGridPoints, (AnnotatedGrid *)this);
    this->gridPublisher = n.advertise<ttb_msgs::Grid>(gridTopic, 5, false);

    this->sendGridPoints();
}

AnnotatedGrid::~AnnotatedGrid()
{
}

void AnnotatedGrid::sendGridPoints()
{
    auto gridPoints = this->generateGridPoints();

    ttb_msgs::Grid grid;
    for (auto point : gridPoints)
    {
        grid.points.push_back(point);
    }
    this->gridPublisher.publish(grid);
}

std::vector<geometry::CNPointAllo> AnnotatedGrid::generateGridPoints()
{
    std::vector<geometry::CNPointAllo> gridPoints;
    // TODO: fill vector with grid points

    // MockUp for testing
    geometry::CNPointAllo p;
    p.x = 10;
    p.y = 11;
    gridPoints.push_back(p);

    return gridPoints;
}

void AnnotatedGrid::receiveAnnotatedGridPoints(ttb_msgs::AnnotatedGridPtr annotatedGrid)
{
    this->gridMap.clear();
    for (int i = 0; i < annotatedGrid->points.size(); i++)
    {
        auto room = this->wm->topologicalModel.getRoom(annotatedGrid->annotatedRooms[i]);

        if (!room)
        {
            std::cerr << "AnnotatedGrid: Received room " << annotatedGrid->annotatedRooms[i] << " is unknown!" << std::endl;
            continue;
        }

        auto mapEntry = this->gridMap.find(annotatedGrid->annotatedRooms[i]);
        if (mapEntry != this->gridMap.end())
        {
            mapEntry->second.push_back(AnnotatedGridPoint(room, annotatedGrid->points[i]));
        }
        else
        {
            this->gridMap.emplace(room->name, vector<ttb::wm::AnnotatedGridPoint>());
            mapEntry->second.push_back(AnnotatedGridPoint(room, annotatedGrid->points[i]));
        }
    }
}

std::vector<ttb::wm::AnnotatedGridPoint> AnnotatedGrid::getGridOfRoom(std::shared_ptr<ttb::wm::Room> room)
{
    auto mapEntry = this->gridMap.find(room->name);
    if (mapEntry != this->gridMap.end())
    {
        return mapEntry->second;
    }
    else
    {
        std::cerr << "AnnotatedGrid: Requested room " << room->name << " is unknown!" << std::endl;
        return vector<ttb::wm::AnnotatedGridPoint>();
    }
}

} /* namespace wm */
} /* namespace ttb */
