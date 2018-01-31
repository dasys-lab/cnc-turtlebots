#include "LogicalObject.h"

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
{
    supplementary::SystemConfig *sc = supplementary::SystemConfig::getInstance();
    this->maxValidityDuration = (*sc)["LogicalCamera"]->get<supplementary::InfoTime>("LogicalCamera", configSectionName.c_str(),
                                                                                     "ValidityDuration", NULL);
    this->poses = new supplementary::InfoBuffer<geometry_msgs::Pose2D>(
        (*sc)["LogicalCamera"]->get<supplementary::InfoTime>("LogicalCamera", configSectionName.c_str(), "BufferLength", NULL));

    this->processData(logicalCameraData);
}

LogicalObject::~LogicalObject()
{
    delete poses;
}

void LogicalObject::processData(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
    supplementary::InfoTime time = logicalCameraData->timeStamp.sec * 1000000000UL + logicalCameraData->timeStamp.nsec;
    poses->add(std::make_shared<supplementary::InformationElement<geometry_msgs::Pose2D>>(
    		logicalCameraData->pose, time, this->maxValidityDuration, 1.0));
}

supplementary::InfoBuffer<geometry_msgs::Pose2D> *LogicalObject::getPoseBuffer()
{
    return this->poses;
}

std::string LogicalObject::getName()
{
    return this->name;
}

}
}
