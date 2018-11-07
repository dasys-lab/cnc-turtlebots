#pragma once

#include "LogicalObject.h"

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
    LogicalCameraData(ttb::TTBWorldModel* wm);
    virtual ~LogicalCameraData();

    void addLogicalObject(std::string name, std::shared_ptr<LogicalObject> model);
    void processLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCameraData);
    friend std::ostream& operator<<(std::ostream& os, const LogicalCameraData& camData)
    {
        os << "LogicalCameraData: " << std::endl;
        // write obj to stream
        for (auto& pair : camData.dict) {
            os << pair.first << ": ";
            auto tmpPos = pair.second->getPoseBuffer()->getLastValidContent();
            if (tmpPos) {
                os << "Pos (" << tmpPos->x << ", " << tmpPos->y << ")" << std::endl;
            }
        }

        return os;
    }

    std::list<std::shared_ptr<LogicalObject>> getObjectsOfType(std::string type);
    std::shared_ptr<LogicalObject> getObject(std::string name);

private:
    ttb::TTBWorldModel* wm;
    std::map<std::string, std::shared_ptr<LogicalObject>> dict;
};
} // namespace wm
} // namespace ttb
