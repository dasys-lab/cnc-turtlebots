using namespace std;
#include "Plans/Behaviours/SimpleDrive.h"

/*PROTECTED REGION ID(inccpp1432735451661) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1432735451661) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	SimpleDrive::SimpleDrive() :
			DomainBehaviour("SimpleDrive")
	{
		/*PROTECTED REGION ID(con1432735451661) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	SimpleDrive::~SimpleDrive()
	{
		/*PROTECTED REGION ID(dcon1432735451661) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void SimpleDrive::run(void* msg)
	{
		/*PROTECTED REGION ID(run1432735451661) ENABLED START*/ //Add additional options here
		geometry_msgs::Twist tw;
		tw.linear.x = 1.0;
		tw.linear.y = 0.0;
		tw.linear.z = 0.0;

		tw.angular.x = 0.0;
		tw.angular.y = 0.0;
		tw.angular.z = 0.0;
		send(tw);
		/*PROTECTED REGION END*/
	}
	void SimpleDrive::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1432735451661) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1432735451661) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
