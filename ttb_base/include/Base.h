#pragma once

#include <iostream>

namespace alica
{
	class AlicaEngine;
	class BehaviourCreator;
	class ConditionCreator;
	class UtilityFunctionCreator;
	class ConstraintCreator;
}

namespace ttb
{
	class TTBWorldModel;

	class Base
	{
	public:
		Base(std::string roleSetName, std::string masterPlanName, std::string roleSetDir, bool sim);
		virtual ~Base();

		void start();

		alica::AlicaEngine* ae;
		alica::BehaviourCreator* bc;
		alica::ConditionCreator* cc;
		alica::UtilityFunctionCreator* uc;
		alica::ConstraintCreator* crc;
		TTBWorldModel* wm;
	};

} /* namespace ttb */
