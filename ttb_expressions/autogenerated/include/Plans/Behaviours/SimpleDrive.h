#ifndef SimpleDrive_H_
#define SimpleDrive_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1432735451661) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class SimpleDrive : public DomainBehaviour
    {
    public:
        SimpleDrive();
        virtual ~SimpleDrive();
        virtual void run(void* msg);
	int counter;
        /*PROTECTED REGION ID(pub1432735451661) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1432735451661) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1432735451661) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* SimpleDrive_H_ */
