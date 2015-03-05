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
#include "clock/AlicaROSClock.h"
#include "communication/AlicaRosCommunication.h"
#include "BehaviourCreator.h"
#include "ConditionCreator.h"
#include "UtilityFunctionCreator.h"
#include "ConstraintCreator.h"
#include "TurtleWorldModel.h"

using namespace std;
using namespace alica;

namespace turtle
{

	class Base
	{
	public:
		Base(string roleSetName, string masterPlanName, string roleSetDir)
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

                        cout << "before WorldModel" << endl;

                        tm = TurtleWorldModel::get();

                        cout << "WorldModel finished" << endl;

                        /**
                         * Initialize the Alica Engine
                         */
                        ae->init(bc, cc, uc, crc, roleSetName, masterPlanName, roleSetDir, false);
                        cout << "Constructor finshed" << endl;
                };
		Base(string roleSetName, string masterPlanName, string roleSetDir, ros::NodeHandle &node, ros::NodeHandle &private_nh) : Base(roleSetName, masterPlanName, roleSetDir) {
		  this->node = node;
		  this->private_nh = private_nh;
		};
		~Base()
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
	        };

		void start() { ae->start(); };



	protected:
		// Alica instance Stuff
                AlicaEngine* ae;
                BehaviourCreator* bc;
                ConditionCreator* cc;
                UtilityFunctionCreator* uc;
                ConstraintCreator* crc;
                TurtleWorldModel* tm;

	private:
                ros::NodeHandle node;
                ros::NodeHandle private_nh;
	};

} /* namespace turtle */

#endif /* BASE_H_ */
