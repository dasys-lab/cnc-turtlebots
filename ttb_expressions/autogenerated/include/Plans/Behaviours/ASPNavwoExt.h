#ifndef ASPNavwoExt_H_
#define ASPNavwoExt_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1477229760910) ENABLED START*/ //Add additional includes here
#include <engine/constraintmodul/Query.h>
#include <memory>
#include <asp_commons/AnnotatedValVec.h>
#include <fstream>
/*PROTECTED REGION END*/
namespace alica
{
    class ASPNavwoExt : public DomainBehaviour
    {
    public:
        ASPNavwoExt();
        virtual ~ASPNavwoExt();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1477229760910) ENABLED START*/ //Add additional public methods here
        vector<::reasoner::AnnotatedValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1477229760910) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1477229760910) ENABLED START*/ //Add additional private methods here
        shared_ptr<alica::Query> query;
        string doorConfig;
        int iterationCounter;
        fstream resultfile;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* ASPNavwoExt_H_ */
