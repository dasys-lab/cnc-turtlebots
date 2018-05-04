#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1520850797525) ENABLED START*/
// Add additional includes here
#include <engine/constraintmodul/Query.h>
#include <memory>
#include <string>
/*PROTECTED REGION END*/

namespace alica
{
class PutDown : public DomainBehaviour
{
  public:
    PutDown();
    virtual ~PutDown();
    virtual void run(void *msg);
    /*PROTECTED REGION ID(pub1520850797525) ENABLED START*/
    // Add additional public methods here
    /*PROTECTED REGION END*/
  protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1520850797525) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
  private:
    /*PROTECTED REGION ID(prv1520850797525) ENABLED START*/
    // Add additional private methods here
    std::shared_ptr<alica::Query> query;
    std::vector<std::string> result;
    bool isPuttingDown;
    /*PROTECTED REGION END*/
};
} /* namespace alica */
