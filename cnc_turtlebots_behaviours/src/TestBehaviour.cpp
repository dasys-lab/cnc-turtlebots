/*
 * TestBehaviour.cpp
 *
 *  Created on: Jun 8, 2014
 *      Author: Stephan Opfer
 */

#include "TestBehaviour.h"
namespace turtlebots
{
	/**
	 * This static variable guarantees that the behaviour registers itself in the creator map of alica::BasicBehaviour.
	 */
	//alica::DerivedRegister<TestBehaviour> TestBehaviour::reg("TestBehaviour", &TestBehaviour::create);
	//alica::BasicBehaviour::reg("TestBehaviour", &TestBehaviour::create);
	bool TestBehaviour::registered = alica::BasicBehaviour::reg("TestBehaviour", &TestBehaviour::create);

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
