#ifndef Rotate_H_
#define Rotate_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1447068205139) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Rotate : public DomainBehaviour
    {
    public:
        Rotate();
        virtual ~Rotate();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1447068205139) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1447068205139) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1447068205139) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Rotate_H_ */
