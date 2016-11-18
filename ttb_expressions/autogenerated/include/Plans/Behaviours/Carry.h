#ifndef Carry_H_
#define Carry_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1468494621581) ENABLED START*/ //Add additional includes here
#include <engine/constraintmodul/Query.h>
#include <alica_asp_solver/AnnotatedValVec.h>
/*PROTECTED REGION END*/
namespace alica
{
    class Carry : public DomainBehaviour
    {
    public:
        Carry();
        virtual ~Carry();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1468494621581) ENABLED START*/ //Add additional public methods here
        vector<alica::reasoner::AnnotatedValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1468494621581) ENABLED START*/ //Add additional protected methods here
        shared_ptr<alica::Query> query;
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1468494621581) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Carry_H_ */
