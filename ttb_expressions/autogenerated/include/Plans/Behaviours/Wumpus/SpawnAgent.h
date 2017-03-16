#ifndef SpawnAgent_H_
#define SpawnAgent_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1489673519312) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class SpawnAgent : public DomainBehaviour
    {
    public:
        SpawnAgent();
        virtual ~SpawnAgent();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1489673519312) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1489673519312) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1489673519312) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* SpawnAgent_H_ */
