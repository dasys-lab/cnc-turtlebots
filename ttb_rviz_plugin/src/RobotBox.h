#ifndef ROBOT_BOX
#define ROBOT_BOX

#include <ros/ros.h>

#include <QGroupBox>

class QLabel;
class QWidget;
class QString;
class QPushButton;
class QVBoxLayout;

#include <actionlib_msgs/GoalID.h>
#include <kobuki_msgs/SensorState.h>
#include <actionlib_msgs/GoalStatus.h>
#include <actionlib_msgs/GoalStatusArray.h>

namespace ttb_rviz_plugin {

class RobotBox : public QGroupBox {

Q_OBJECT
public:

	RobotBox(const QString& robot, QWidget *parent);
	~RobotBox();

Q_SIGNALS:
	void deletePressed(QString robotName);

protected Q_SLOTS:

	void displayReceived();
	void abortPressed();
	void deleteButtonPressed();
	void toggled(bool on);

protected:

	unsigned long lastReceived;

	void sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg);
	void goalCallback(const actionlib_msgs::GoalStatusArray& msg);

	void displayBaseBattery(int battery);
	void displayBatteryState(int state);

	QString robot;
	std::string goalID;

	QVBoxLayout *layout;
	QLabel *batteryLabel;
	QLabel *batteryStateLabel;
	QLabel *lastReceivedLabel;
	QLabel *goalStatusLabel;
	QPushButton *abortButton;
	QPushButton *deleteButton;

	QTimer *timer;

	ros::Subscriber batterySub;
	ros::Subscriber statusSub;
    	ros::Publisher abortPub;
	ros::NodeHandle nh;
};


} // namespace ttb_rviz_plugin

#endif // ROBOT_BOX
