#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553249791474) ENABLED START*/
#include <engine/constraintmodul/Query.h>
#include <supplementary/InformationElement.h>

#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ttb_msgs/ServeTask.h>

#include <memory>
namespace ttb
{
namespace wm
{
class POI;
}
} // namespace ttb
/*PROTECTED REGION END*/

namespace alica
{
class DriveToPOI : public DomainBehaviour
{
public:
    DriveToPOI();
    virtual ~DriveToPOI();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1553249791474) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1553249791474) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1553249791474) ENABLED START*/
    bool isMoveBaseDone();
    std::shared_ptr<alica::Query> query;
    std::vector<BBIdent> result;
    actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
    std::shared_ptr<ttb::wm::POI> goalPOI;
    /*PROTECTED REGION END*/
};
} /* namespace alica */
