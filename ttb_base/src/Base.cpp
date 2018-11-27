#include "Base.h"

#include <BehaviourCreator.h>
#include <ConditionCreator.h>
#include <ConstraintCreator.h>
#include <UtilityFunctionCreator.h>
#include <clock/AlicaROSClock.h>
#include <communication/AlicaRosCommunication.h>
#include <engine/AlicaEngine.h>
#include <ttb/TTBWorldModel.h>

#include <alica/reasoner/SimpleSolver.h>
#include <asp_commons/IASPSolver.h>
#include <asp_solver/ASPSolver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <supplementary/AgentIDManager.h>

#include <ros/ros.h>

#include <chrono>
#include <iostream>
#include <thread>

namespace ttb
{

Base::Base(std::string roleSetName, std::string masterPlanName, std::string roleSetDir, bool sim)
{
    ae = new alica::AlicaEngine(new supplementary::AgentIDManager(new supplementary::AgentIDFactory()), roleSetName, masterPlanName, false);
    bc = new alica::BehaviourCreator();
    cc = new alica::ConditionCreator();
    uc = new alica::UtilityFunctionCreator();
    crc = new alica::ConstraintCreator();
    ae->setAlicaClock(new alicaRosProxy::AlicaROSClock());
    ae->setCommunicator(new alicaRosProxy::AlicaRosCommunication(ae));
    wm = TTBWorldModel::get();
    if (sim) {
        wm->enableUsingSimulator();
    }
    wm->setEngine(ae);
    wm->init();
    // "clingo", "-W", "no-atom-undefined",  "--number=0", nullptr
//    std::vector<char const*> args{"clingo", nullptr};
    auto aspSolver = new ::reasoner::ASPSolver({});
    auto solverWrapper = new alica::reasoner::ASPSolverWrapper(ae, {});
    solverWrapper->init(aspSolver);
    ae->addSolver<alica::reasoner::ASPSolverWrapper>(solverWrapper);

    auto SimpleSolver = new alica::reasoner::SimpleSolver(ae);
    ae->addSolver<alica::reasoner::SimpleSolver>(SimpleSolver);
    ae->init(bc, cc, uc, crc);
}

void Base::start()
{
    ae->start();
}

Base::~Base()
{
    ae->shutdown();
    delete ae->getAlicaClock();
    delete ae->getCommunicator();
    delete ae;
    delete cc;
    delete bc;
    delete uc;
    delete crc;
}

} /* namespace ttb */

void printUsage()
{
    std::cout << "Usage: ./msl_base -m \"Masterplan\" [-rd \"RoleSetDirectory\"] [-rset \"RoleSet\"] [-sim]" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printUsage();
        return 0;
    }

    std::cout << "Initialising ROS" << std::endl;

    ros::init(argc, argv, supplementary::SystemConfig::getInstance()->getHostname() + "_Base");

    std::cout << "Parsing command line parameters:" << std::endl;

    std::string masterplan = "";
    std::string rolesetdir = ".";
    std::string roleset = "";
    bool sim = false;

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-m" || std::string(argv[i]) == "-masterplan") {
            masterplan = argv[i + 1];
            i++;
        }

        if (std::string(argv[i]) == "-rd" || std::string(argv[i]) == "-rolesetdir") {
            rolesetdir = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-r" || std::string(argv[i]) == "-roleset") {
            roleset = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-sim") {
            sim = true;
        }
    }
    if (masterplan.size() == 0 || rolesetdir.size() == 0) {
        printUsage();
        return 0;
    }
    std::cout << "\tMasterplan is:       \"" << masterplan << "\"" << std::endl;
    std::cout << "\tRolset Directory is: \"" << rolesetdir << "\"" << std::endl;
    std::cout << "\tRolset is:           \"" << (roleset.empty() ? "Default" : roleset) << "\"" << std::endl;
    std::cout << "\tUsing Simulator:     \"" << (sim ? "TRUE" : "FALSE") << "\"" << std::endl;

    std::cout << "\nConstructing Base ..." << std::endl;
    ttb::Base* base = new ttb::Base(roleset, masterplan, rolesetdir, sim);

    std::cout << "\nStarting Base ..." << std::endl;
    base->start();

    while (ros::ok()) {
        std::chrono::milliseconds dura(500);
        std::this_thread::sleep_for(dura);
    }

    return 0;
}
