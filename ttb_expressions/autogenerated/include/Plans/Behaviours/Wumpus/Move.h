#ifndef Move_H_
#define Move_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1489674693144) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Move : public DomainBehaviour
    {
    public:
        Move();
        virtual ~Move();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1489674693144) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1489674693144) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1489674693144) ENABLED START*/ //Add additional private methods here
        bool msgSend;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Move_H_ */
