#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1553508167181) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
class PutDown : public DomainBehaviour
{
public:
    PutDown();
    virtual ~PutDown();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1553508167181) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1553508167181) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1553508167181) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
