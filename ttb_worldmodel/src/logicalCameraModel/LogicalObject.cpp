#include "logicalCameraModel/LogicalObject.h"

#include <ttb_msgs/LogicalCamera.h>
#include <memory>

namespace ttb {
namespace wm {

LogicalObject::LogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData, int ringBufferLength) :
		name(logicalCameraData->modelName), size(logicalCameraData->size), poses(ringBufferLength)
{
	this->processData(logicalCameraData);
}

LogicalObject::~LogicalObject()
{
}

void LogicalObject::processData(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
	supplementary::InfoTime time = logicalCameraData->timeStamp.sec * 1000000000UL + logicalCameraData->timeStamp.nsec;
	geometry_msgs::Pose2D pose;
	pose.x = logicalCameraData->pose.x;
	pose.y = logicalCameraData->pose.y;
	pose.theta = logicalCameraData->pose.theta;
	auto poseInfo = std::make_shared<supplementary::InformationElement<geometry_msgs::Pose2D>>(pose, time);
	poses.add(poseInfo);
}

}
}
