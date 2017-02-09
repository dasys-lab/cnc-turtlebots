/*
 * Simulator.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_MODEL_MODEL_H_
#define INCLUDE_MODEL_MODEL_H_

#include <vector>
#include "Movable.h"
#include "GroundTile.h"
#include "ros/ros.h"
#include <memory>
#include <qdebug.h>

using namespace std;

namespace wumpus_simulator
{

	class Wumpus;
	class Agent;
	class Model
	{
	public:
		static Model* get();
		virtual ~Model();
		void init(bool agentHasArrow, int wumpusCount, int trapCount, int playGroundSize);

		shared_ptr<GroundTile> getTile(int x, int y);
		bool isAgentHasArrow();
		int getPlayGroundSize();
		int getTrapCount();
		int getWumpusCount();
		vector<vector<shared_ptr<GroundTile>>> getPlayGround();
		vector<shared_ptr<Movable>> movables;

		shared_ptr<Agent> getAgentByID(int id);
		shared_ptr<Wumpus> getWumpusByID(int id);

		QJsonObject toJSON();
		void fromJSON(QJsonObject root);

		void removeAgent(shared_ptr<Agent> agent);
		void exit(shared_ptr<Agent> agent);
		void removeWumpus(shared_ptr<Wumpus> wumpus);
		void setStench(int x, int y, shared_ptr<Wumpus> wumpus);

	private:
		ros::NodeHandle* rosNode;
		Model();
		int playGroundSize;
		int wumpusCount;
		int trapCount;
		bool agentHasArrow;
		vector<vector<shared_ptr<GroundTile>>> playGround;

		void setBreeze(int x, int y);

	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_MODEL_H_ */
