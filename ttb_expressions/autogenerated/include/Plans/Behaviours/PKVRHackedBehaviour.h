#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1520437499749) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
    class PKVRHackedBehaviour : public DomainBehaviour
    {
    public:
        PKVRHackedBehaviour();
        virtual ~PKVRHackedBehaviour();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1520437499749) ENABLED START*/
        // Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1520437499749) ENABLED START*/
        // Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1520437499749) ENABLED START*/
        // Add additional private methods here
        /*PROTECTED REGION END*/
    };
} /* namespace alica */
