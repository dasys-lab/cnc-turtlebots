#include "ttb/wm/sim/LogicalCameraData.h"

#include "ttb/TTBWorldModel.h"
#include "ttb/wm/sim/LogicalObject.h"

#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <geometry_msgs/Pose2D.h>

#include <algorithm>
#include <iostream>
#include <memory>

namespace ttb
{
namespace wm
{
LogicalCameraData::LogicalCameraData(ttb::TTBWorldModel* wm)
        : wm(wm)
{
}

LogicalCameraData::~LogicalCameraData() {}

void LogicalCameraData::addLogicalObject(std::string name, std::shared_ptr<LogicalObject> model)
{
    auto logicalObjectEntry = this->dict.find(name);
    if (logicalObjectEntry == this->dict.end()) {
        this->dict[name] = model;
    }
}

void LogicalCameraData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
    std::string name = logicalCameraData->modelName;
    auto logicalObjectEntry = this->dict.find(name);
    if (logicalObjectEntry != this->dict.end()) {
        logicalObjectEntry->second->processData(logicalCameraData);
    } else {
        this->dict[name] = std::make_shared<LogicalObject>(logicalCameraData, logicalCameraData->type);
    }
}

std::list<std::shared_ptr<LogicalObject>> LogicalCameraData::getObjectsOfType(std::string type)
{
    std::list<std::shared_ptr<LogicalObject>> ret;
    for (auto pair : this->dict) {
        if (pair.first.find("_" + type) != std::string::npos) {
            ret.push_back(pair.second);
        }
    }
    return ret;
}

std::shared_ptr<LogicalObject> LogicalCameraData::getObject(std::string name)
{
    auto logicalObject = this->dict.find(name);
    if (logicalObject != this->dict.end()) {
        return logicalObject->second;
    }
    return nullptr;
}
} // namespace wm
} // namespace ttb
