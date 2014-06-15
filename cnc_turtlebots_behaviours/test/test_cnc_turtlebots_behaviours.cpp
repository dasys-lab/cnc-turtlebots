#include <engine/AlicaEngine.h>
#include <engine/BasicBehaviour.h>
#include <engine/IBehaviourPool.h>
#include <engine/model/Behaviour.h>
#include <engine/PlanRepository.h>
#include <FileSystem.h>
#include <gtest/gtest.h>
#include <gtest/gtest-message.h>
#include <SystemConfig.h>
#include <TestBehaviour.h>
#include <cstdbool>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>

using namespace std;



/**
 * \brief Tests the behaviour pool
 *
 * Tests the behaviour pool by initialising an AlicaEngine and retrieve the parsed behaviours.
 */
TEST(Turtlebots, behaviourPool)
{
	// determine the path to the test config
	string path = supplementary::FileSystem::getSelfPath();
	int place = path.rfind("devel");
	path = path.substr(0, place);
	path = path + "src/alica/test";

	// bring up the SystemConfig with the corresponding path
	supplementary::SystemConfig* sc = supplementary::SystemConfig::getInstance();
	sc->setRootPath(path);
	sc->setConfigPath(path + "/etc");

	alica::AlicaEngine* ae = alica::AlicaEngine::getInstance();
	ae->init("Roleset", "MasterPlan", ".", false);

	std::map<long int, alica::Behaviour*> behaviours = ae->getPlanRepository()->getBehaviours();

	unique_ptr<alica::IBehaviourPool> bp = ae->getBehaviourPool();
	for(auto behaviourPair : behaviours) {
		cout << "Behaviour: " << behaviourPair.second->getName() << endl;
		EXPECT_TRUE(bp->isBehaviourAvailable(behaviourPair.second)) << "Did not find the Behaviour " << behaviourPair.second->getName();
	}

	turtlebots::TestBehaviour* test = new turtlebots::TestBehaviour();

	cout << "DEBUG: " << endl;
	alica::BasicBehaviour* beh = alica::BasicBehaviour::createInstance("TestBehaviour");
	cout << "DEBUG: 1" << beh << endl;
	beh->run(nullptr);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
