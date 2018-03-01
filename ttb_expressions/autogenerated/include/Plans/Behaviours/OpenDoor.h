#ifndef OpenDoor_H_
#define OpenDoor_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1519913953735) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class OpenDoor : public DomainBehaviour
    {
    public:
        OpenDoor();
        virtual ~OpenDoor();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1519913953735) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1519913953735) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1519913953735) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* OpenDoor_H_ */
