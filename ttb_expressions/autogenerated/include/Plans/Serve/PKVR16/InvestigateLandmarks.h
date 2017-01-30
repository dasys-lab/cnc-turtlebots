#ifndef InvestigateLandmarks_H_
#define InvestigateLandmarks_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1485780420922) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class InvestigateLandmarks : public DomainBehaviour
    {
    public:
        InvestigateLandmarks();
        virtual ~InvestigateLandmarks();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1485780420922) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1485780420922) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1485780420922) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* InvestigateLandmarks_H_ */
