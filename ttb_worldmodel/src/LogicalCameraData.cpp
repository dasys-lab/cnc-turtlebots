#include <LogicalCameraData.h>

#include "logicalCameraModel/BlueBook.h"
#include "logicalCameraModel/Box.h"
#include "logicalCameraModel/CokeCan.h"
#include "logicalCameraModel/ContaminatedArea.h"
#include "logicalCameraModel/Cup.h"
#include "logicalCameraModel/Door.h"
#include "logicalCameraModel/Drill.h"
#include "logicalCameraModel/Fire.h"
#include "logicalCameraModel/GreenBook.h"
#include "logicalCameraModel/GreenBook.h"
#include "logicalCameraModel/Hammer.h"
#include "logicalCameraModel/Hammer.h"
#include "logicalCameraModel/Landmark.h"
#include "logicalCameraModel/LargeTable.h"
#include "logicalCameraModel/LogicalObject.h"
#include "logicalCameraModel/MediumTable.h"
#include "logicalCameraModel/MonkeyWrench.h"
#include "logicalCameraModel/RedBook.h"
#include "logicalCameraModel/SmallTable.h"
#include "logicalCameraModel/TrashCan.h"
#include "logicalCameraModel/Victim.h"
#include <TTBWorldModel.h>

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
LogicalCameraData::LogicalCameraData(ttb::TTBWorldModel *wm)
    : wm(wm)
{
}

LogicalCameraData::~LogicalCameraData()
{
}

void LogicalCameraData::processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
    //	std::cout << "logicalCameraData->type = " << logicalCameraData->type << std::endl;
    std::string name = logicalCameraData->modelName;

    auto logicalObject = this->dict.find(name);
    if (logicalObject != this->dict.end())
    {
        logicalObject->second->getPoseBuffer()->add(std::make_shared<supplementary::InformationElement<geometry_msgs::Pose2D>>(
            logicalCameraData->pose, wm->getTime(), logicalObject->second->getMaxValidityDuration(), 1.0));
    }
    else
    {
        this->dict[name] = createLogicalObject(logicalCameraData);
    }
}

std::list<std::shared_ptr<LogicalObject>> LogicalCameraData::getLogicalObjects(std::string type)
{
    std::list<std::shared_ptr<LogicalObject>> ret;
    for (auto pair : this->dict)
    {
        if (pair.first.find(type) != std::string::npos)
        {
            ret.push_back(pair.second);
        }
    }
    return ret;
}

std::shared_ptr<LogicalObject> LogicalCameraData::getLogicalObject(std::string name)
{
    auto logicalObject = this->dict.find(name);
    if (logicalObject != this->dict.end())
    {
        return logicalObject->second;
    }
    return nullptr;
}

std::shared_ptr<LogicalObject> LogicalCameraData::createLogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
    if (logicalCameraData->type.compare("Victim") == 0)
    {
        return std::make_shared<Victim>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Fire") == 0)
    {
        return std::make_shared<Fire>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("ContaminatedArea") == 0)
    {
        return std::make_shared<ContaminatedArea>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Landmark") == 0)
    {
        return std::make_shared<Landmark>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Box") == 0)
    {
        return std::make_shared<Box>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Cup") == 0)
    {
        return std::make_shared<Cup>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Coke_Can") == 0)
    {
        return std::make_shared<CokeCan>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Blue_Book") == 0)
    {
        return std::make_shared<BlueBook>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Red_Book") == 0)
    {
        return std::make_shared<RedBook>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Green_Book") == 0)
    {
        return std::make_shared<GreenBook>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Drill") == 0)
    {
        return std::make_shared<Drill>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Hammer") == 0)
    {
        return std::make_shared<Hammer>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Monkey_Wrench") == 0)
    {
        return std::make_shared<MonkeyWrench>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Trash_Can") == 0)
    {
        return std::make_shared<TrashCan>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Small_Table") == 0)
    {
        return std::make_shared<SmallTable>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Mediuml_Table") == 0)
    {
        return std::make_shared<MediumTable>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("LargeTable") == 0)
    {
        return std::make_shared<LargeTable>(logicalCameraData);
    }
    else if (logicalCameraData->type.compare("Door") == 0)
    {
        return std::make_shared<Door>(logicalCameraData);
    }
    else
    {
        std::cerr << "LogicalCameraData::createLogicalObject: Unknown Logical Camera Object Type " << logicalCameraData->type << "!" << std::endl;
        return nullptr;
    }
}
}
}
