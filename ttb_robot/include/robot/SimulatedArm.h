#pragma once

#include <ttb_msgs/GrabDropObject.h>

#include <ros/ros.h>
#include <string>

namespace supplementary
{
	class SystemConfig;
}

namespace ttb
{
namespace robot
{

class SimulatedArm
{
  public:
    SimulatedArm();
    virtual ~SimulatedArm();
    const std::string &getCarriedObjectName() const;
    bool grabObject(std::string objectName);
    bool drobObject(std::string objectName);
    int mayInteractWithObject();
    void onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg);

  private:
    std::string carriedObjectName;
    ros::Publisher armCmdPub;
    ros::Subscriber armCmdSub;
    /**
     * -1: interaction is not allowed
     *  0: waiting for response
     *  1: interaction is allowed
     */
    int interactWithObject;
    supplementary::SystemConfig* sc;
    std::string robotName;
    ros::AsyncSpinner *spinner;
};

} /* namespace robot */
} /* namespace ttb */
