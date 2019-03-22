#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1552997304057) ENABLED START*/
#include <engine/constraintmodul/Query.h>
#include <memory>
#include <string>
/*PROTECTED REGION END*/

namespace alica
{
class PickUp : public DomainBehaviour
{
public:
    PickUp();
    virtual ~PickUp();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1552997304057) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1552997304057) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1552997304057) ENABLED START*/
    std::shared_ptr<alica::Query> query;
    std::vector<BBIdent> result;
    bool isGrabbing;
    /*PROTECTED REGION END*/
};
} /* namespace alica */
