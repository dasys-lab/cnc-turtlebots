#pragma once

#include <iostream>

#include "engine/AlicaEngine.h"
#include "BehaviourCreator.h"
#include "ConditionCreator.h"
#include "UtilityFunctionCreator.h"
#include "ConstraintCreator.h"
#include "TTBWorldModel.h"

using namespace std;

namespace ttb
{

	class Base
	{
	public:
		Base(string roleSetName, string masterPlanName, string roleSetDir);
		virtual ~Base();

		void start();

		alica::AlicaEngine* ae;
		alica::BehaviourCreator* bc;
		alica::ConditionCreator* cc;
		alica::UtilityFunctionCreator* uc;
		alica::ConstraintCreator* crc;
		TTBWorldModel* wm;

	protected:
		//blabla...
	};

} /* namespace ttb */
