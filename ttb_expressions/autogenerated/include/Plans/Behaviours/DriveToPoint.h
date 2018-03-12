#ifndef DriveToPoint_H_
#define DriveToPoint_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1520850811997) ENABLED START*/ //Add additional includes here#include <engine/constraintmodul/Query.h>
#include <supplementary/InformationElement.h>

#include <engine/constraintmodul/Query.h>

#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ttb_msgs/ServeTask.h>

#include <string>
#include <memory>
/*PROTECTED REGION END*/
namespace alica
{
    class DriveToPoint : public DomainBehaviour
    {
    public:
        DriveToPoint();
        virtual ~DriveToPoint();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1520850811997) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1520850811997) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1520850811997) ENABLED START*/ //Add additional private methods here
        std::shared_ptr<alica::Query> query;
        std::vector<std::string> result;
        actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
        bool isMoveBaseDone();
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DriveToPoint_H_ */
