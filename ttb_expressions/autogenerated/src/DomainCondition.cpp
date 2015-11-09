#include "DomainCondition.h"

namespace alica
{
    DomainCondition::DomainCondition() :
            BasicCondition()
    {
    	this->wm = ttb::TTBWorldModel::get();
    }

    DomainCondition::~DomainCondition()
    {
    }
} /* namespace alica */
