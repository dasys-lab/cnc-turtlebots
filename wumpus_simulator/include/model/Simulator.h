/*
 * Simulator.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_SIMULATOR_H_
#define INCLUDE_MODEL_SIMULATOR_H_

#include <vector>
#include "Movable.h"
#include "GroundTile.h"
#include "ros/ros.h"
#include <memory>

using namespace std;

namespace wumpus_simulator
{

	class Simulator
	{
	public:
		static Simulator* get();
		virtual ~Simulator();
		void init(int playGroundSize, int wumpusCount, int trapCount, bool agentHasArrow);

	private:
		ros::NodeHandle* rosNode;
		Simulator();
		int playGroundSize;
		int wumpusCount;
		int trapCount;
		bool agentHasArrow;
		vector<vector<shared_ptr<GroundTile>>> playGround;
		vector<shared_ptr<Movable>> movableObjects;
		void setBreeze(int x, int y);
		void setStench(int x, int y);
	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_SIMULATOR_H_ */
