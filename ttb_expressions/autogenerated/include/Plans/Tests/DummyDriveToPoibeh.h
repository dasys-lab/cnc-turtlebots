#ifndef DummyDriveToPoibeh_H_
#define DummyDriveToPoibeh_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1517819089097) ENABLED START*/ //Add additional includes here
#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
/*PROTECTED REGION END*/
namespace alica
{
    class DummyDriveToPoibeh : public DomainBehaviour
    {
    public:
        DummyDriveToPoibeh();
        virtual ~DummyDriveToPoibeh();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1517819089097) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1517819089097) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1517819089097) ENABLED START*/ //Add additional private methods here
        actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DummyDriveToPoibeh_H_ */
