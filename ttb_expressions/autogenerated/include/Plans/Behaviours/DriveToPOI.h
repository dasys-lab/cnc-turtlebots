#ifndef DriveToPOI_H_
#define DriveToPOI_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1454329856163) ENABLED START*/ //Add additional includes here
#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <topology/POI.h>
#include <supplementary/InformationElement.h>
#include <ttb_msgs/ServeTask.h>
/*PROTECTED REGION END*/
namespace alica
{
    class DriveToPOI : public DomainBehaviour
    {
    public:
        DriveToPOI();
        virtual ~DriveToPOI();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1454329856163) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1454329856163) ENABLED START*/ //Add additional protected methods here
        int poiID;
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1454329856163) ENABLED START*/ //Add additional private methods here
        actionlib::ClientGoalHandle<move_base_msgs::MoveBaseAction> goalHandle;
        std::shared_ptr<ttb::wm::POI> nextPOI;
        std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> currentTask;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DriveToPOI_H_ */
