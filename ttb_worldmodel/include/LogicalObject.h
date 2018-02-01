#pragma once

#include <geometry_msgs/Pose2D.h>
#include <ros/message_forward.h>
#include <string>
#include <supplementary/InfoBuffer.h>
#include <ttb_msgs/ObjectSize.h>

namespace ttb_msgs
{
ROS_DECLARE_MESSAGE(LogicalCamera)
}

namespace ttb
{
namespace wm
{
/**
 * Top-Level class for all kind of logical camera objects. Every specific logical object is inheriting from this class.
 */
class LogicalObject
{
  public:
	LogicalObject(std::string modelName, std::string configSectionName);
    LogicalObject(ttb_msgs::LogicalCameraPtr logicalCameraData, std::string configSectionName);
    virtual ~LogicalObject();

    void processData(ttb_msgs::LogicalCameraPtr logicalCameraData);
    supplementary::InfoBuffer<geometry_msgs::Pose2D>* getPoseBuffer();
    std::string getName();

  protected:
    std::string name;
    ttb_msgs::ObjectSize size;
    supplementary::InfoTime maxValidityDuration;
    supplementary::InfoBuffer<geometry_msgs::Pose2D>* poses;
};
}
}
