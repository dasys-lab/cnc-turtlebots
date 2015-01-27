/*
 * Base.cpp
 *
 *  Created on: 22.10.2014
 *      Author: endy
 *
 *  Extended on: 04.11.2014
 *      Author: Jonas Scherbaum
 */

#include <iostream>

#include <thread>
#include <chrono>
#include "ros/ros.h"
#include "Base.h"
#include "clock/AlicaROSClock.h"
#include "communication/AlicaRosCommunication.h"

//using namespace std;
using namespace turtle;

/**
 * beginning with turtle namespace
 */
namespace turtle
{

        /**
         * Declare the Base Class
         */
	Base::Base(string roleSetName, string masterPlanName, string roleSetDir)
	{
	        /**
	         * Instantiate the Alica Engine Stuff
	         */
		ae = new alica::AlicaEngine();
		bc = new alica::BehaviourCreator();
		cc = new alica::ConditionCreator();
		uc = new alica::UtilityFunctionCreator();
		crc = new alica::ConstraintCreator();
		ae->setIAlicaClock(new alicaRosProxy::AlicaROSClock());
		ae->setCommunicator(new alicaRosProxy::AlicaRosCommunication(ae));

		tm = TurtleWorldModel::get();

		/**
		 * Initialize the Alica Engine
		 */
		ae->init(bc, cc, uc, crc, roleSetName, masterPlanName, roleSetDir, false);
	}

	/**
	 * Declare the start() Method of the Base Class
	 */
	void Base::start()
	{
		ae->start();
	}

	/**
	 * Declare the Destructor of the Base Class
	 */
	Base::~Base()
	{
	        // Shutdown the Alica Engine and destroy all Instances
		ae->shutdown();
		delete ae->getIAlicaClock();
		delete ae->getCommunicator();
		delete ae;
		delete cc;
		delete bc;
		delete uc;
		delete crc;
	}

} /* namespace turtle */

/**
 * The main EntryPoint of the turtle_base Node
 */
int main(int argc, char** argv)
{
        // start the Node with the name AlicaEngine
	cout << "Initializing Ros" << endl;
	ros::init(argc, argv, "AlicaEngine");

	// Read the argv Arguments for the Settings
	cout << "Starting Base" << endl;
	if (argc < 2)
	{
		cout << "Usage: Base -m [Masterplan] -rd [rolesetdir]" << endl;
		return 0;
	}

	string masterplan = "";
	string rolesetdir = "";
	string roleset = "";

	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "-m" || string(argv[i]) == "-masterplan")
		{
			masterplan = argv[i + 1];
			i++;
		}

		if (string(argv[i]) == "-rd" || string(argv[i]) == "-rolesetdir")
		{
			rolesetdir = argv[i + 1];
			i++;
		}
		if (string(argv[i]) == "-r" || string(argv[i]) == "-roleset")
		{
			roleset = argv[i + 1];
			i++;
		}
	}
	if (masterplan.size() == 0 || rolesetdir.size() == 0)
	{
		cout << "Usage: Base -m [Masterplan] -rd [rolesetdir]" << endl;
		return 0;
	}
	cout << "Masterplan is: " << masterplan << endl;
	cout << "Rolset Directory is: " << rolesetdir << endl;
	cout << "Rolset is: " << roleset << endl;

	// Now constructing the Base
	cout << "Constructing Base" << endl;
	Base* base = new Base(roleset, masterplan, rolesetdir);

	// Start the Base
	base->start();

	// While ROS is active, do the Node Stuff
	while (ros::ok())
	{
	        // At the moment we are only waiting
		std::chrono::milliseconds dura(500);
		std::this_thread::sleep_for(dura);
	}

	return 0;
}
