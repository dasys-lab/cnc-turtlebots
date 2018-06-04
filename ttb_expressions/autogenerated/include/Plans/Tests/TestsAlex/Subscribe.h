#ifndef Subscribe_H_
#define Subscribe_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1528125245680) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Subscribe : public DomainBehaviour
    {
    public:
        Subscribe();
        virtual ~Subscribe();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1528125245680) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1528125245680) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1528125245680) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Subscribe_H_ */
