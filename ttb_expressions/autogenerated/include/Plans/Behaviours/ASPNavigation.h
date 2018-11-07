#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1475693360605) ENABLED START*/
// Add additional includes here
#include <asp_commons/AnnotatedValVec.h>
#include <engine/constraintmodul/Query.h>
#include <fstream>
#include <memory>
/*PROTECTED REGION END*/

namespace alica
{
class ASPNavigation : public DomainBehaviour
{
public:
    ASPNavigation();
    virtual ~ASPNavigation();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1475693360605) ENABLED START*/
    // Add additional public methods here
    vector<::reasoner::AnnotatedValVec*> result;
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1475693360605) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1475693360605) ENABLED START*/
    // Add additional private methods here
    shared_ptr<alica::Query> query;
    int iterationCounter;
    fstream resultfile;
    /*PROTECTED REGION END*/
};
} /* namespace alica */
