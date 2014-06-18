/*
 * BehaviourCreator.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: Stephan Opfer
 */

using namespace std;

#include "BehaviourCreator.h"
#include <engine/behaviourpool/BehaviourPool.h>
#include "TestBehaviour.h"

namespace turtlebots
{
	BehaviourCreator::BehaviourCreator()
	{
	}

	unique_ptr<alica::BasicBehaviour> BehaviourCreator::createBehaviour(string behaviourName)
	{
		unique_ptr<alica::BasicBehaviour> beh;

		if ("TestBehaviour" == behaviourName)
		{
			beh.reset(new TestBehaviour());
		} else {
			cerr << "Unknown behaviour requested: " << behaviourName << endl;
			return nullptr;
		}

		return beh;
	}

} /* namespace alica */
