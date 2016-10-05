#ifndef ASPNavigation_H_
#define ASPNavigation_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1475693360605) ENABLED START*/ //Add additional includes here
#include <engine/constraintmodul/ConstraintQuery.h>
#include <clingo/clingocontrol.hh>
#include <memory>
#include "POI.h"
/*PROTECTED REGION END*/
namespace alica
{
    class ASPNavigation : public DomainBehaviour
    {
    public:
        ASPNavigation();
        virtual ~ASPNavigation();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1475693360605) ENABLED START*/ //Add additional public methods here
        vector<Gringo::ValVec> result;
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1475693360605) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1475693360605) ENABLED START*/ //Add additional private methods here
        shared_ptr<alica::ConstraintQuery> query;
        string extractPOI(string aspPredicate);
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* ASPNavigation_H_ */
