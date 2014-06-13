/*
 * TestBehaviour.h
 *
 *  Created on: Jun 8, 2014
 *      Author: Stephan Opfer
 */

#ifndef TESTBEHAVIOUR_H_
#define TESTBEHAVIOUR_H_

using namespace std;

#include <iostream>

class TestBehaviour
{
public:
	TestBehaviour();
	virtual ~TestBehaviour();
	void Run();

protected:
	int callCounter;
};

#endif /* TESTBEHAVIOUR_H_ */
