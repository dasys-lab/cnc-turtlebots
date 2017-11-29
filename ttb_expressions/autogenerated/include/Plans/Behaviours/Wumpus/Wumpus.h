#ifndef Wumpus_H_
#define Wumpus_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1489674662469) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Wumpus : public DomainBehaviour
    {
    public:
        Wumpus();
        virtual ~Wumpus();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1489674662469) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1489674662469) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1489674662469) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Wumpus_H_ */
