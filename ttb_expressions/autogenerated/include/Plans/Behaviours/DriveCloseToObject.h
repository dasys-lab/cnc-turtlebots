#ifndef DriveCloseToObject_H_
#define DriveCloseToObject_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1520521852939) ENABLED START*/ //Add additional includes here
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
        /*PROTECTED REGION ID(pub1520521852939) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1520521852939) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1520521852939) ENABLED START*/ //Add additional private methods here
        std::shared_ptr<alica::Query> query;
        std::vector<std::string> result;
        std::string object;
        actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
        bool isMoveBaseDone();
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DriveCloseToObject_H_ */
