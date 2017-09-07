#ifndef ASPRCCTest_H_
#define ASPRCCTest_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1480766583222) ENABLED START*/ //Add additional includes here
#include <engine/constraintmodul/Query.h>
#include <memory>
#include <asp_commons/AnnotatedValVec.h>
#include <fstream>
/*PROTECTED REGION END*/
namespace alica
{
    class ASPRCCTest : public DomainBehaviour
    {
    public:
        ASPRCCTest();
        virtual ~ASPRCCTest();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1480766583222) ENABLED START*/ //Add additional public methods here
        vector<::reasoner::AnnotatedValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1480766583222) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1480766583222) ENABLED START*/ //Add additional private methods here
        shared_ptr<alica::Query> query;
        int iterationCounter;
        fstream resultfile;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* ASPRCCTest_H_ */
