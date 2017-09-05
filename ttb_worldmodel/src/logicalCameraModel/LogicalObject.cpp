/*
 * LogicalObject.cpp
 *
 *  Created on: Jan 9, 2017
 *      Author: lab-user
 */

#include <logicalCameraModel/LogicalObject.h>
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
	InfoTime time = logicalCameraData->timeStamp.sec * 1000000000UL + logicalCameraData->timeStamp.nsec;
	auto poseDataPtr = make_shared<geometry_msgs::Pose2D>();
	poseDataPtr->x = logicalCameraData->pose.x;
	poseDataPtr->y = logicalCameraData->pose.y;
	poseDataPtr->theta = logicalCameraData->pose.theta;
	shared_ptr<InformationElement<geometry_msgs::Pose2D>> poseInfo = make_shared<
			InformationElement<geometry_msgs::Pose2D>>(poseDataPtr, time);
	poses.add(poseInfo);
}

}
}
