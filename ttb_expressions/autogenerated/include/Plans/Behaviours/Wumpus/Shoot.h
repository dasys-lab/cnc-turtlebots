#ifndef Shoot_H_
#define Shoot_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1489674675135) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Shoot : public DomainBehaviour
    {
    public:
        Shoot();
        virtual ~Shoot();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1489674675135) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1489674675135) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1489674675135) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Shoot_H_ */
