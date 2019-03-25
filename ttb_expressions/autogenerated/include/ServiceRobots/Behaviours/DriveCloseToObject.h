#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553251534505) ENABLED START*/
// Add additional includes here
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
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
