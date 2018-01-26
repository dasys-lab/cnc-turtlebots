#include "logicalCameraModel/LogicalObject.h"

#include <SystemConfig.h>
#include <supplementary/InformationElement.h>
#include <ttb_msgs/LogicalCamera.h>

#include <memory>

namespace ttb
{
namespace wm
{

LogicalObject::LogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData, std::string configSectionName)
    : name(logicalCameraData->modelName)
    , size(logicalCameraData->size)
    , maxValidityDuration(0)
    , poses(nullptr)
	, configSectionName(configSectionName)
{
    supplementary::SystemConfig *sc = supplementary::SystemConfig::getInstance();
    this->maxValidityDuration =
        (*sc)["LogicalCamera"]->get<supplementary::InfoTime>("LogicalCamera", configSectionName, "ValidityDuration", NULL);
    this->poses = new supplementary::InfoBuffer<geometry_msgs::Pose2D>(
        (*sc)["LogicalCamera"]->get<supplementary::InfoTime>("LogicalCamera", configSectionName, "BufferLength", NULL));

    this->processData(logicalCameraData);
}

LogicalObject::~LogicalObject()
{
    delete poses;
}

void LogicalObject::processData(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
    supplementary::InfoTime time = logicalCameraData->timeStamp.sec * 1000000000UL + logicalCameraData->timeStamp.nsec;
    geometry_msgs::Pose2D pose;
    pose.x = logicalCameraData->pose.x;
    pose.y = logicalCameraData->pose.y;
    pose.theta = logicalCameraData->pose.theta;
    auto poseInfo = std::make_shared<supplementary::InformationElement<geometry_msgs::Pose2D>>(
        pose, time, this->maxValidityDuration, 1.0);
    poses->add(poseInfo);
}

supplementary::InfoBuffer<geometry_msgs::Pose2D> *LogicalObject::getPoseBuffer()
{
	return this->poses;
}

std::string LogicalObject::getName()
{
	return this->name;
}

supplementary::InfoTime LogicalObject::getMaxValidityDuration() const
{
    return maxValidityDuration;
}

}
}


