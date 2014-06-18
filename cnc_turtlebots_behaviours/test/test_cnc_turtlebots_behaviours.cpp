using namespace std;

#include <gtest/gtest.h>
#include <FileSystem.h>
#include <SystemConfig.h>
#include <engine/AlicaEngine.h>
#include <engine/model/Behaviour.h>
#include <engine/BasicBehaviour.h>
#include <engine/PlanRepository.h>
#include <engine/IBehaviourPool.h>
#include <BehaviourCreator.h>

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
	EXPECT_TRUE(ae->init(new turtlebots::BehaviourCreator(), "Roleset", "MasterPlan", ".", false)) << "Unable to initialise the Alica Engine!";
	//ae->init(new turtlebots::BehaviourCreator(), "Roleset", "MasterPlan", ".", false);
	cout << "Debug 0" << endl;
	map<long int, alica::Behaviour*> behaviours = ae->getPlanRepository()->getBehaviours();
	cout << "Debug 1" << endl;
	unique_ptr<alica::IBehaviourPool> bp = ae->getBehaviourPool();
	cout << "Debug 2" << endl;
	for(auto behaviourPair : behaviours) {
		cout << "Behaviour: " << behaviourPair.second->getName() << endl;
		EXPECT_TRUE(bp->isBehaviourAvailable(behaviourPair.second)) << "Did not find the Behaviour " << behaviourPair.second->getName();
	}
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
