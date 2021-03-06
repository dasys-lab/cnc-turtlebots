using namespace std;
#include "Plans/Behaviours/Wumpus/Move.h"

/*PROTECTED REGION ID(inccpp1489674693144) ENABLED START*/ //Add additional includes here
#include <wumpus_simulator/ActionRequest.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1489674693144) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Move::Move() :
            DomainBehaviour("Move")
    {
        /*PROTECTED REGION ID(con1489674693144) ENABLED START*/ //Add additional options here
        msgSend = false;
        /*PROTECTED REGION END*/
    }
    Move::~Move()
    {
        /*PROTECTED REGION ID(dcon1489674693144) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Move::run(void* msg)
    {
        /*PROTECTED REGION ID(run1489674693144) ENABLED START*/ //Add additional options here
        if (!msgSend)
        {
            wumpus_simulator::ActionRequest msg;
            msg.agentId = this->wm->wumpusData.getOwnId();
            msg.action = this->wm->getTime() % 6;
            send(msg);
            msgSend = true;
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void Move::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1489674693144) ENABLED START*/ //Add additional options here
        msgSend = false;
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1489674693144) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
