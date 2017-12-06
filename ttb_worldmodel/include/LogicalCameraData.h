#pragma once

#include <logicalCameraModel/LogicalObject.h>
#include <ttb_msgs/LogicalCamera.h>

#include <list>
#include <map>
#include <string>

namespace ttb
{
class TTBWorldModel;
namespace wm
{

/**
 * The public data access class recognised logical camera objects inside the TTBWorldModel.
 */
class LogicalCameraData
{
  public:
    LogicalCameraData(ttb::TTBWorldModel *wm);
    virtual ~LogicalCameraData();

    void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData);
    friend std::ostream &operator<<(std::ostream &os, const LogicalCameraData &camData)
    {
        os << "LogicalCameraData: " << std::endl;
        // write obj to stream
        for (auto &pair : camData.dict)
        {
            os << pair.first << ":" << std::endl;

            for (auto &item : pair.second)
            {
                auto tmpPos = item->getPoseBuffer()->getLast()->getInformation();
                os << "\t" << item->getName() << ": Pos (" << tmpPos.x << ", " << tmpPos.y << ")" << std::endl;
            }
        }

        return os;
    }

    std::list<std::shared_ptr<LogicalObject>> getLogicalObjects(std::string type);

  private:
    ttb::TTBWorldModel *wm;
    std::map<std::string, std::list<std::shared_ptr<LogicalObject>>> dict;
    std::shared_ptr<LogicalObject> createLogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData);
};
}
}
