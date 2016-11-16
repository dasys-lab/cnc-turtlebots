#ifndef SearchForDockingStationAsp_H_
#define SearchForDockingStationAsp_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1470041810334) ENABLED START*/ //Add additional includes here
#include <kdl_conversions/kdl_msg.h>
#include <ecl/geometry/pose2d.hpp>
#include <kobuki_dock_drive/dock_drive.hpp>
#include <engine/constraintmodul/ConstraintQuery.h>
#include <memory>
#include "POI.h"
#include <alica_asp_solver/AnnotatedValVec.h>
//#define testWithoutTTB
/*PROTECTED REGION END*/
namespace alica
{
    class SearchForDockingStationAsp : public DomainBehaviour
    {
    public:
        SearchForDockingStationAsp();
        virtual ~SearchForDockingStationAsp();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1470041810334) ENABLED START*/ //Add additional public methods here
        vector<alica::reasoner::AnnotatedValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1470041810334) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1470041810334) ENABLED START*/ //Add additional private methods here
#ifdef testWithoutTTB
        kobuki::DockDrive dock;
#endif
        shared_ptr<alica::ConstraintQuery> query;
        string getPOIName(string predicate);
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* SearchForDockingStationAsp_H_ */
