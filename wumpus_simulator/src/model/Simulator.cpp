/*
 * Simulator.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Simulator.h>

namespace wumpus_simulator
{

	Simulator* Simulator::get()
	{
		static Simulator instance;
		return &instance;
	}

	void Simulator::init(int playGroundSize, int wumpusCount, int trapCount, bool agentHasArrow)
	{
		this->agentHasArrow = agentHasArrow;
		this->playGroundSize = playGroundSize;
		this->trapCount = trapCount;
		this->wumpusCount = wumpusCount;
		for(int i = 0; i < this->playGroundSize; i++)
		{
			for(int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).at(j) = make_shared<GroundTile>(i,j);
			}
		}
	}

	Simulator::Simulator()
	{
		rosNode = new ros::NodeHandle();
		this->agentHasArrow = false;
		this->playGroundSize = -1;
		this->trapCount = -1;
		this->wumpusCount = -1;

	}

	Simulator::~Simulator()
	{
		// TODO Auto-generated destructor stub
	}

} /* namespace wumpus_simulator */
