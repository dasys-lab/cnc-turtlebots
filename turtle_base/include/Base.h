/*
 * Base.h
 *
 *  Created on: 22.10.2014
 *      Author: endy
 *
 *  Extended on: 04.11.2014
 *      Author: Jonas Scherbaum
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

#include "engine/AlicaEngine.h"
#include "BehaviourCreator.h"
#include "ConditionCreator.h"
#include "UtilityFunctionCreator.h"
#include "ConstraintCreator.h"
#include "TurtleWorldModel.h"

using namespace std;

namespace turtle
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
		TurtleWorldModel* tm;

	protected:
		//blabla...
	};

} /* namespace turtle */

#endif /* BASE_H_ */
