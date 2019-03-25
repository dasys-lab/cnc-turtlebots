#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553251534505) ENABLED START*/
#include <engine/constraintmodul/Query.h>

#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

#include <memory>
#include <string>
/*PROTECTED REGION END*/

namespace alica
{
class DriveCloseToObject : public DomainBehaviour
{
public:
    DriveCloseToObject();
    virtual ~DriveCloseToObject();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1553251534505) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1553251534505) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1553251534505) ENABLED START*/
    std::shared_ptr<alica::Query> query;
    std::vector<alica::BBIdent> result;
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
    bool isMoveBaseDone();
    /*PROTECTED REGION END*/
};
} /* namespace alica */
