#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553508193766) ENABLED START*/
// Add additional includes here
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
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
