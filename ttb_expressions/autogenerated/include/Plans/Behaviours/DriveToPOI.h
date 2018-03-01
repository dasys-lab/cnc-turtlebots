#ifndef DriveToPOI_H_
#define DriveToPOI_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1454329856163) ENABLED START*/ //Add additional includes here
#include <actionlib/client/action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <topology/POI.h>
#include <supplementary/InformationElement.h>
#include <ttb_msgs/ServeTask.h>
#include <engine/constraintmodul/Query.h>
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
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1454329856163) ENABLED START*/ //Add additional private methods here
        bool trySetGoalPOI();
        std::shared_ptr<ttb::wm::POI> currentGoalPOI;
        std::shared_ptr<alica::Query> query;
        std::vector<std::string> result;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DriveToPOI_H_ */
