#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1552997370653) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
class DriveSearchPattern : public DomainBehaviour
{
public:
    DriveSearchPattern();
    virtual ~DriveSearchPattern();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1552997370653) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1552997370653) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1552997370653) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
