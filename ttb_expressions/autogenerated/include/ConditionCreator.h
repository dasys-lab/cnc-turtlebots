#pragma once

#include <engine/IConditionCreator.h>
#include <iostream>
#include <memory>

using std::exception;
using std::make_shared;
using std::cout;

namespace alica
{
class BasicCondition;

class ConditionCreator : public IConditionCreator
{
  public:
    ConditionCreator();
    virtual ~ConditionCreator();
    shared_ptr<BasicCondition> createConditions(long conditionConfId);
};

} /* namespace alica */
