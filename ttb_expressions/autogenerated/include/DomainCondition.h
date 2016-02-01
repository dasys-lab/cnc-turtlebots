#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicCondition.h"
#include "TTBWorldModel.h"

namespace alica
{
    class DomainCondition : public BasicCondition
    {
    public:
        DomainCondition();
        virtual ~DomainCondition();
        bool checkLastCommand(robot_control::RobotCommand::_cmd_type rc);

    protected:
        ttb::TTBWorldModel* wm;
    };
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

