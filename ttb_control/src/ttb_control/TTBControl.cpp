#include <pluginlib/class_list_macros.h>
#include <ros/master.h>

#include <ttb_control/TTBControl.h>

#include <SystemConfig.h>
#include <process_manager/RobotExecutableRegistry.h>

#include <QMenu>
#include <sstream>
#include <iostream>

namespace ttb_control
{

std::chrono::duration<double> TTBControl::msgTimeOut = std::chrono::duration<double>(0);

TTBControl::TTBControl()
    : rqt_gui_cpp::Plugin()
    , widget_(0)
    , guiUpdateTimer(nullptr)
{
    setObjectName("TTBControl");
    rosNode = new ros::NodeHandle();

    this->sc = supplementary::SystemConfig::getInstance();
    TTBControl::msgTimeOut = std::chrono::duration<double>(
        (*this->sc)["ProcessManaging"]->get<unsigned long>("PMControl.timeLastMsgReceivedTimeOut", NULL));
    this->pmRegistry = supplementary::RobotExecutableRegistry::get();

    /* Initialise the registry data structure for better performance
     * with data from Globals.conf and Processes.conf file. */

    // Register robots from Globals.conf
    auto robotNames = (*this->sc)["Globals"]->getSections("Globals.Team", NULL);
    for (auto robotName : (*robotNames))
    {
        this->pmRegistry->addRobot(robotName);
    }

    // TODO: needs to be expanded for arbitrary new robots (when discovery module is ready)
}

void TTBControl::initPlugin(qt_gui_cpp::PluginContext &context)
{
    widget_ = new QWidget();
    widget_->setAttribute(Qt::WA_AlwaysShowToolTips, true);
    robotControlWidget_.setupUi(widget_);

    this->widget_->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    QObject::connect(this->widget_, SIGNAL(customContextMenuRequested(const QPoint &)), this,
                     SLOT(showContextMenu(const QPoint &)));

    if (context.serialNumber() > 1)
    {
        widget_->setWindowTitle(widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
    }
    context.addWidget(widget_);

    for (auto robot : this->pmRegistry->getRobots())
    {
        this->checkAndInit(robot.second->agentID);
    }

    // Initialise the ROS Communication
    topologicalInfoSub =
        rosNode->subscribe("/TopologicalInfo", 10, &TTBControl::receiveTopologicalInfo, (TTBControl *)this);

    // Initialise the GUI refresh timer
    this->guiUpdateTimer = new QTimer();
    QObject::connect(guiUpdateTimer, SIGNAL(timeout()), this, SLOT(run()));
    this->guiUpdateTimer->start(200);
}

void TTBControl::showContextMenu(const QPoint &pos)
{
    /* HINT: remember, if there are some problems that way:
     * For QAbstractScrollArea and derived classes you would use:
     * QPoint globalPos = myWidget->viewport()->mapToGlobal(pos); */

    QPoint globalPos = this->widget_->mapToGlobal(pos);

    QMenu myMenu;
    for (auto &robot : this->pmRegistry->getRobots())
    {
        std::stringstream ss;
        ss << *(robot.second->agentID);
        QIcon icon;
        if (this->controlledRobotsMap[robot.first]->isHidden())
        {
            icon = QIcon::fromTheme("user-offline", QIcon("user-offline"));
        }
        else
        {
            icon = QIcon::fromTheme("user-available", QIcon("user-available"));
        }
        auto tmpAction = myMenu.addAction(icon, std::string(robot.second->name + " (" + ss.str() + ")").c_str());
    }

    QAction *selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {

        std::string name = selectedItem->iconText().toStdString().substr();
        name = name.substr(0, name.find('(') - 1);

        std::cout << "RC: '" << name << "'" << endl;

        const supplementary::AgentID *robotId = this->pmRegistry->getRobotId(name);
        if (robotId != nullptr)
        {
            this->controlledRobotsMap[robotId]->toggle();
        }
        else
        {
            std::cerr << "RC: Chosen robot is not known in the robot registry!" << endl;
        }
    }
    else
    {
        std::cout << "RC: Nothing chosen!" << endl;
    }
}

/**
 * The worker method of TTBControl. It processes the received ROS messages and afterwards updates the GUI.
 */
void TTBControl::run()
{
    processMessages();

    updateGUI();
}

/**
 * Updates the GUI, after ROS process stat message have been processed.
 */
void TTBControl::updateGUI()
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    for (auto controlledRobotEntry : this->controlledRobotsMap)
    {
        controlledRobotEntry.second->updateGUI(now);
    }
}

void TTBControl::receiveTopologicalInfo(ttb_msgs::TopologicalInfoPtr topoInfo)
{
    std::lock_guard<std::mutex> lck(topologicalInfoMsgQueueMutex);
    this->topologicalInfoMsgQueue.emplace(std::chrono::system_clock::now(), topoInfo);
}

/**
 * Processes all queued messages from the processStatMsgsQueue and the alicaInfoMsgQueue.
 */
void TTBControl::processMessages()
{
    {
        std::lock_guard<std::mutex> lck(topologicalInfoMsgQueueMutex);
        while (!this->topologicalInfoMsgQueue.empty())
        {
            // unqueue the ROS kicker stat info message
            auto timeTopoInfoPair = topologicalInfoMsgQueue.front();
            topologicalInfoMsgQueue.pop();

            auto agentID = this->pmRegistry->getRobotId(timeTopoInfoPair.second->sender.id);
            this->checkAndInit(agentID);
            this->controlledRobotsMap[agentID]->handleTopologicalInfo(timeTopoInfoPair);
        }
    }
}

/**
 * If the given robot ID is already known, nothing is done.
 * Otherwise a new entry in the controlled robot map is created.
 */
void TTBControl::checkAndInit(const supplementary::AgentID *robotId)
{
    auto pmEntry = this->controlledRobotsMap.find(robotId);
    if (pmEntry == this->controlledRobotsMap.end())
    { // robot is not known, so create a corresponding instance
        std::string robotName;
        if (this->pmRegistry->getRobotName(robotId, robotName))
        {
            std::cout << "RC: Create new ControlledRobot with ID " << robotId << " and host name " << robotName << "!"
                 << endl;
            Robot *controlledRobot = new Robot(robotName, robotId, this);
            this->controlledRobotsMap.emplace(robotId, controlledRobot);
        }
        else
        {
            std::cerr << "RC: Received message from unknown robot with sender id " << robotId << endl;
        }
    }
}

void TTBControl::shutdownPlugin()
{
}

void TTBControl::saveSettings(qt_gui_cpp::Settings &plugin_settings, qt_gui_cpp::Settings &instance_settings) const
{
}

void TTBControl::restoreSettings(const qt_gui_cpp::Settings &plugin_settings,
                                 const qt_gui_cpp::Settings &instance_settings)
{
}
}

PLUGINLIB_EXPORT_CLASS(ttb_control::TTBControl, rqt_gui_cpp::Plugin)
