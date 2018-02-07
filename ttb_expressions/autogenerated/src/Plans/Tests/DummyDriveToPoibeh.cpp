using namespace std;
#include "Plans/Tests/DummyDriveToPoibeh.h"

/*PROTECTED REGION ID(inccpp1517819089097) ENABLED START*/ // Add additional includes here
#include <Robot.h>
#include <TTBWorldModel.h>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1517819089097) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
DummyDriveToPoibeh::DummyDriveToPoibeh()
    : DomainBehaviour("DummyDriveToPoibeh")
{
    /*PROTECTED REGION ID(con1517819089097) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
DummyDriveToPoibeh::~DummyDriveToPoibeh()
{
    /*PROTECTED REGION ID(dcon1517819089097) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void DummyDriveToPoibeh::run(void *msg)
{
    /*PROTECTED REGION ID(run1517819089097) ENABLED START*/ // Add additional options here
    auto currentPosition = wm->topologicalModel.getRoom("r1407_room");
    std::cout << "DummyDriveToPoibeh: Current Position: " << currentPosition->toString() << std::endl;
    auto goalPOI = wm->topologicalModel.getPOI(36);
    std::cout << "DummyDriveToPoibeh: Goal POI: " << goalPOI->toString() << std::endl;
    auto nextPOI = this->robot->movement->getNextPOI(currentPosition, goalPOI);
    if (nextPOI)
    {
        //std::cout << "DummyDriveToPoibeh: Next POI to drive to: " << nextPOI->toString() << std::endl;
    }
    else
    {
    	//std::cout << "DummyDriveToPoibeh: Next POI is null" << std::endl;
    }
    /*PROTECTED REGION END*/
}
void DummyDriveToPoibeh::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1517819089097) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1517819089097) ENABLED START*/ // Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
