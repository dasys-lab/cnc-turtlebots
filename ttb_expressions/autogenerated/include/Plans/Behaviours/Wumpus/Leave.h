#ifndef Leave_H_
#define Leave_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1489674647212) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Leave : public DomainBehaviour
    {
    public:
        Leave();
        virtual ~Leave();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1489674647212) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1489674647212) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1489674647212) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Leave_H_ */
