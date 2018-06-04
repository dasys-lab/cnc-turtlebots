#ifndef Publish_H_
#define Publish_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1528125228262) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Publish : public DomainBehaviour
    {
    public:
        Publish();
        virtual ~Publish();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1528125228262) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1528125228262) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1528125228262) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Publish_H_ */
