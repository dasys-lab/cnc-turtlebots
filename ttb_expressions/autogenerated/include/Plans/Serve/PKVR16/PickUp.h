#ifndef PickUp_H_
#define PickUp_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1486381476387) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class PickUp : public DomainBehaviour
    {
    public:
        PickUp();
        virtual ~PickUp();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1486381476387) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1486381476387) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1486381476387) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* PickUp_H_ */
