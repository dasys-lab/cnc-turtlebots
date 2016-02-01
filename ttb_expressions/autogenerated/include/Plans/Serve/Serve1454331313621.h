#ifndef Serve_H_
#define Serve_H_

#include "DomainCondition.h"
#include "engine/BasicUtilityFunction.h"
#include "engine/UtilityFunction.h"
#include "engine/DefaultUtilityFunction.h"
/*PROTECTED REGION ID(incl1454331313621) ENABLED START*/
//Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
    /*PROTECTED REGION ID(meth1454331313621) ENABLED START*/
    //Add other things here
    /*PROTECTED REGION END*/
    class UtilityFunction1454331313621 : public BasicUtilityFunction
    {
        shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
    };

    class TransitionCondition1454331384091 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1454331385501 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1454331503425 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

} /* namespace alica */

#endif