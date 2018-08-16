#ifndef ASPMinimizePath_H_
#define ASPMinimizePath_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1477125924367) ENABLED START*/ //Add additional includes here
#include <engine/constraintmodul/Query.h>
#include <asp_commons/AnnotatedValVec.h>

#include <memory>
/*PROTECTED REGION END*/
namespace alica
{
    class ASPMinimizePath : public DomainBehaviour
    {
    public:
        ASPMinimizePath();
        virtual ~ASPMinimizePath();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1477125924367) ENABLED START*/ //Add additional public methods here
        vector<::reasoner::AnnotatedValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1477125924367) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1477125924367) ENABLED START*/ //Add additional private methods here
        shared_ptr<alica::Query> query;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* ASPMinimizePath_H_ */
