/**
 * Encapsulates all necessary information for current simulation.
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
		/**
		 * Returns model singleton
		 * @return Model*
		 */
		static Model* get();
		virtual ~Model();
		/**
		 * Creates a new model and initializes it with the given values.
		 * @param agentHasArrow bool Determines if the agents can shoot an arrow
		 * @param wumpusCount int the number of wumpus that will be spawned
		 * @param trapCount int the number of traps that will be spawned
		 * @param playGroundSize int edge length of square field
		 */
		void init(bool agentHasArrow, int wumpusCount, int trapCount, int playGroundSize);

		/**
		 * Returns the tile located at x and y
		 * @return shared_ptr<GroundTile>
		 */
		shared_ptr<GroundTile> getTile(int x, int y);

		// Getters
		bool getAgentHasArrow();
		int getPlayGroundSize();
		int getTrapCount();
		int getWumpusCount();
		vector<vector<shared_ptr<GroundTile>>> getPlayGround();

		/**
		 * A vector of all wumpus and agents
		 */
		vector<shared_ptr<Movable>> movables;

		/**
		 * Returns the agent with the given ID. Returns null if not found.
		 */
		shared_ptr<Agent> getAgentByID(int id);

		/**
		 * Returns the wumpus with the given ID. Returns null if not found.
		 */
		shared_ptr<Wumpus> getWumpusByID(int id);

		/**
		 * Serializes the complete model to a QJsoinObject
		 */
		QJsonObject toJSON();

		/**
		 * Create a new model from a given QJsonObject.
		 */
		void fromJSON(QJsonObject root);

		/**
		 * Removes only the visual representation of given agent
		 */
		void removeAgent(shared_ptr<Agent> agent);

		/**
		 * Completely removes given agent from model
		 */
		void exit(shared_ptr<Agent> agent);

		/**
		 * Removes only the visual representation of given wumpus
		 */
		void removeWumpus(shared_ptr<Wumpus> wumpus);

		/**
		 * Sets stench at given coordinates
		 */
		void setStench(int x, int y);

	private:
		ros::NodeHandle* rosNode;
		Model();
		int playGroundSize;
		int wumpusCount;
		int trapCount;
		bool agentHasArrow;
		vector<vector<shared_ptr<GroundTile>>> playGround;

		/**
		 * Sets breeze at given coordinates
		 */
		void setBreeze(int x, int y);

	};

} /* namespace wumpus_simulator */

#endif /* INCLUDE_MODEL_MODEL_H_ */
