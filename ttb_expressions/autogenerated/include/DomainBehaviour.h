#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include <engine/BasicBehaviour.h>
#include <ros/ros.h>
#include <string>

namespace supplementary {
	class SystemConfig;
}

namespace ttb {
	class TTBWorldModel;
	class Robot;
}

namespace alica
{
	class DomainBehaviour : public BasicBehaviour
	{
	public:
		DomainBehaviour(std::string name);
		virtual ~DomainBehaviour();

	protected:
		supplementary::SystemConfig* sc;
		ttb::TTBWorldModel* wm;
		ttb::Robot* robot;
	};
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

