#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1447958115909) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
class ChargingDefault : public DomainBehaviour
{
public:
    ChargingDefault();
    virtual ~ChargingDefault();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1447958115909) ENABLED START*/
    // Add additional public methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1447958115909) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1447958115909) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
