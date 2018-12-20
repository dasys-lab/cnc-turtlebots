#include "Plans/Behaviours/PKVRHackedBehaviour.h"
#include <memory>

using std::make_shared;
using std::shared_ptr;

/*PROTECTED REGION ID(inccpp1520437499749) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1520437499749) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

    PKVRHackedBehaviour::PKVRHackedBehaviour()
            : DomainBehaviour("PKVRHackedBehaviour")
    {
        /*PROTECTED REGION ID(con1520437499749) ENABLED START*/
        // Add additional options here
        /*PROTECTED REGION END*/
    }
    PKVRHackedBehaviour::~PKVRHackedBehaviour()
    {
        /*PROTECTED REGION ID(dcon1520437499749) ENABLED START*/
        // Add additional options here
        /*PROTECTED REGION END*/
    }
    void PKVRHackedBehaviour::run(void* msg)
    {
        /*PROTECTED REGION ID(run1520437499749) ENABLED START*/
        // Add additional options here
        std::cout << "Ich laufe" << std::endl;
        /*PROTECTED REGION END*/
    }
    void PKVRHackedBehaviour::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1520437499749) ENABLED START*/
        // Add additional options here

        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1520437499749) ENABLED START*/
// Add additional methods here
/*PROTECTED REGION END*/

} /* namespace alica */
