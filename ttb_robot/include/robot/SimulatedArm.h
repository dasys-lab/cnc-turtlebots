#pragma once

#include <ttb_msgs/DoorCmd.h>
#include <ttb_msgs/GrabDropObject.h>

#include <memory>
#include <ros/ros.h>
#include <string>

namespace supplementary
{
class SystemConfig;
}

namespace ttb
{
class TTBWorldModel;
namespace wm
{
class Door;
}
namespace robot
{

class SimulatedArm
{
  public:
    enum ObjectInteraction
    {
        noInteractionAllowed,
        waiting,
        interactionAllowed
    };
    SimulatedArm();
    virtual ~SimulatedArm();
    const std::string &getCarriedObjectName() const;
    bool grabObject(std::string objectName);
    bool drobObject(std::string objectName);
    SimulatedArm::ObjectInteraction mayInteractWithObject();
    void onOwnArmCmd(ttb_msgs::GrabDropObjectPtr msg);
    bool openDoor(std::string doorName, bool open = true);
    bool openDoor(std::shared_ptr<ttb::wm::Door> door, bool open = true);

  private:
    std::string carriedObjectName;
    std::string requestedObject;
    ros::Publisher armCmdPub;
    ros::Subscriber armCmdSub;
    ros::Publisher doorCmdPub;
    // TODO: implement arm range as soon as logical camera sensor is available
    double armRange;

    ObjectInteraction interactWithObject;
    supplementary::SystemConfig *sc;
    std::string robotName;
    ros::AsyncSpinner *spinner;
    ttb::TTBWorldModel *wm;
};

} /* namespace robot */
} /* namespace ttb */
