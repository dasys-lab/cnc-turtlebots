#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553508193766) ENABLED START*/
#include <supplementary/InformationElement.h>

#include <engine/constraintmodul/Query.h>

#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ttb_msgs/ServeTask.h>

#include <memory>
#include <string>
/*PROTECTED REGION END*/

namespace alica
{
class DriveToPoint : public DomainBehaviour
{
public:
    DriveToPoint();
    virtual ~DriveToPoint();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1553508193766) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1553508193766) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1553508193766) ENABLED START*/
    std::shared_ptr<alica::Query> query;
    std::vector<alica::BBIdent> result;
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
    bool isMoveBaseDone();
    /*PROTECTED REGION END*/
};
} /* namespace alica */
