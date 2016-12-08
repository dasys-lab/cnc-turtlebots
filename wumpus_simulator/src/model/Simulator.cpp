/*
 * Simulator.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <model/Simulator.h>
#include <model/Wumpus.h>
#include <model/GroundTile.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

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
			this->playGround.push_back(vector<shared_ptr<GroundTile>>());
		}
		for (int i = 0; i < this->playGroundSize; i++)
		{
			for (int j = 0; j < this->playGroundSize; j++)
			{
				this->playGround.at(i).push_back(make_shared<GroundTile>(i, j));
			}
		}
		// Place given number of traps on field
		/* initialize random seed: */
		srand(time(NULL));
		for (int i = 0; i < trapCount; i++)
		{
			int randx = rand() % (playGroundSize - 1);
			int randy = rand() % (playGroundSize - 1);

			if (!playGround.at(randx).at(randy)->getTrap())
			{
				playGround.at(randx).at(randy)->setTrap(true);
				setBreeze(randx, randy);
			}
			else
			{
				i--;
			}
		}
		// Place Wumpus on field
		for (int i = 0; i < wumpusCount; i++)
		{
			int randx = rand() % (playGroundSize - 1);
			int randy = rand() % (playGroundSize - 1);

			if (playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasWumpus())
			{
				i--;
			}
			else
			{
				auto wumpus = make_shared<Wumpus>(playGround.at(randx).at(randy));
				movableObjects.push_back(wumpus);
				playGround.at(randx).at(randy)->setWumpus(wumpus);
				setStench(randx, randy);
			}

		}

		// Place Gold on field
		bool placed = false;
		while (!placed)
		{
			int randx = rand() % (playGroundSize - 1);
			int randy = rand() % (playGroundSize - 1);

			if (!(playGround.at(randx).at(randy)->getTrap() || playGround.at(randx).at(randy)->hasWumpus()))
			{
				playGround.at(randx).at(randy)->setGold(true);
				placed = true;
			}
		}
		cout << "Simulator: Finished initiating the playground!" << endl;
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
	}

	void Simulator::setBreeze(int x, int y)
	{
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setBreeze(true);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setBreeze(true);

		}
		else
		{
			playGround.at(x - 1).at(y)->setBreeze(true);
			playGround.at(x + 1).at(y)->setBreeze(true);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setBreeze(true);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setBreeze(true);
		}
	}

	void Simulator::setStench(int x, int y)
	{
		if (x == 0)
		{
			playGround.at(x + 1).at(y)->setStench(true);

		}
		else if (x == playGroundSize - 1)
		{
			playGround.at(x - 1).at(y)->setStench(true);

		}
		else
		{
			playGround.at(x - 1).at(y)->setStench(true);
			playGround.at(x + 1).at(y)->setStench(true);
		}

		if (y > 0)
		{
			playGround.at(x).at(y - 1)->setStench(true);
		}

		if (y < playGroundSize - 1)
		{
			playGround.at(x).at(y + 1)->setStench(true);
		}
	}

} /* namespace wumpus_simulator */
