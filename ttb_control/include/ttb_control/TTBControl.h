#pragma once

#include <rqt_gui_cpp/plugin.h>

#include "ros/ros.h"
#include <ros/macros.h>
#include <essentials/Identifier.h>
#include <ttb_control/Robot.h>
#include <ttb_msgs/TopologicalInfo.h>

#include <QDialog>
#include <QWidget>
#include <QtGui>
#include <ui_TTBControl.h>

#include <chrono>
#include <mutex>
#include <queue>
#include <utility>

namespace essentials
{
class SystemConfig;
class RobotExecutableRegistry;
} // namespace supplementary

namespace ttb_control
{

class TTBControl : public rqt_gui_cpp::Plugin
{

    Q_OBJECT

public:
    TTBControl();
    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

    void addRobot();
    void removeRobot();

    static std::chrono::duration<double> msgTimeOut;

    Ui::RobotControlWidget robotControlWidget_;
    QWidget* widget_;

    essentials::RobotExecutableRegistry* pmRegistry;
    ros::NodeHandle* rosNode;

private:
    essentials::SystemConfig* sc;
    ros::Subscriber topologicalInfoSub;

    std::map<const essentials::Identifier*, Robot*> controlledRobotsMap;
    std::mutex topologicalInfoMsgQueueMutex;
    std::queue<std::pair<std::chrono::system_clock::time_point, ttb_msgs::TopologicalInfoPtr>> topologicalInfoMsgQueue;

    void receiveTopologicalInfo(ttb_msgs::TopologicalInfoPtr topoInfo);
    void processMessages();
    void checkAndInit(const essentials::Identifier* robotId);

    QTimer* guiUpdateTimer;

public Q_SLOTS:
    void run();
    void updateGUI();
    void showContextMenu(const QPoint& pos);
};
} // namespace ttb_control
