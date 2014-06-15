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
#include <engine/BasicBehaviour.h>

namespace turtlebots
{
	class TestBehaviour : public virtual alica::BasicBehaviour
	{
	public:
		TestBehaviour();
		virtual ~TestBehaviour();
		virtual void run(void* msg);
		static BasicBehaviour * create() { return new TestBehaviour(); }
	protected:
		int callCounter;
		static bool registered;
		//static alica::DerivedRegister<TestBehaviour> reg;
	private:
	};



}



#endif /* TESTBEHAVIOUR_H_ */
