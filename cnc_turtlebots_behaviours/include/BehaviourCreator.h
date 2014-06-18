/*
 * BehaviourRegistrator.h
 *
 *  Created on: Jun 17, 2014
 *      Author: Stephan Opfer
 */

#ifndef BEHAVIOURCREATOR_H_
#define BEHAVIOURCREATOR_H_

#include <string>
#include <memory>

#include <engine/IBehaviourCreator.h>

namespace alica {
	class BasicBehaviour;
}

namespace turtlebots
{
	class BehaviourCreator : public alica::IBehaviourCreator
	{
	public:
		BehaviourCreator();
		virtual ~BehaviourCreator() {};
		unique_ptr<alica::BasicBehaviour> createBehaviour(string behaviourName);
	};

} /* namespace alica */

#endif /* BEHAVIOURCREATOR_H_ */
