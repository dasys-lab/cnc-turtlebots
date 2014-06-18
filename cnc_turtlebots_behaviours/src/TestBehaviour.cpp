/*
 * TestBehaviour.cpp
 *
 *  Created on: Jun 8, 2014
 *      Author: Stephan Opfer
 */

#include "TestBehaviour.h"

namespace turtlebots
{

	TestBehaviour::TestBehaviour()
	{
		this->callCounter = 0;
	}

	TestBehaviour::~TestBehaviour()
	{

	}

	void TestBehaviour::run(void* msg)
	{
		cout << "TestBehaviour was called " << callCounter++ << " times!" << endl;
	}
}
