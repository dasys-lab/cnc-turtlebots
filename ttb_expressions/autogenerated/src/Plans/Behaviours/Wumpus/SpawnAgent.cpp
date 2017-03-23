using namespace std;
#include "Plans/Behaviours/Wumpus/SpawnAgent.h"

/*PROTECTED REGION ID(inccpp1489673519312) ENABLED START*/ //Add additional includes here
#include <wumpus_simulator/InitialPoseRequest.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1489673519312) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    SpawnAgent::SpawnAgent() :
            DomainBehaviour("SpawnAgent")
    {
        /*PROTECTED REGION ID(con1489673519312) ENABLED START*/ //Add additional options here
        msgSend = false;
        /*PROTECTED REGION END*/
    }
    SpawnAgent::~SpawnAgent()
    {
        /*PROTECTED REGION ID(dcon1489673519312) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void SpawnAgent::run(void* msg)
    {
        /*PROTECTED REGION ID(run1489673519312) ENABLED START*/ //Add additional options here
        if (!msgSend)
        {
            wumpus_simulator::InitialPoseRequest msg;
            msg.agentId = this->wm->wumpusData.getOwnId();
            send(msg);
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void SpawnAgent::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1489673519312) ENABLED START*/ //Add additional options here
        msgSend = false;
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1489673519312) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
