#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1468494621581) ENABLED START*/
// Add additional includes here
#include <reasoner/asp/AnnotatedValVec.h>
#include <engine/constraintmodul/Query.h>
/*PROTECTED REGION END*/

namespace alica
{
class Carry : public DomainBehaviour
{
public:
    Carry();
    virtual ~Carry();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1468494621581) ENABLED START*/
    // Add additional public methods here
    std::vector<::reasoner::asp::AnnotatedValVec*> result;
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1468494621581) ENABLED START*/
    // Add additional protected methods here
    std::shared_ptr<alica::Query> query;
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1468494621581) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
