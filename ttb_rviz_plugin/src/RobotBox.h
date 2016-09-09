#ifndef ROBOT_BOX
#define ROBOT_BOX

#include <kobuki_msgs/SensorState.h>

#include <QGroupBox>
#include <ros/ros.h>

class QLabel;
class QWidget;
class QString;
class QPushButton;

namespace ttb_rviz_plugin {

class RobotBox : public QGroupBox {

Q_OBJECT
public:

	RobotBox(const QString& robot, QWidget *parent);
	~RobotBox();

protected Q_SLOTS:

	void displayReceived();
	void abortPressed();

protected:

	unsigned long lastReceived;

	void sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg);

	void displayBaseBattery(int battery);
	void displayBatteryState(int state);

	QLabel *batteryLabel;
	QLabel *batteryStateLabel;
	QLabel *lastReceivedLabel;
	QPushButton *abortButton;

	QTimer *timer;

	ros::Subscriber batterySub;
	ros::NodeHandle nh;
};


} // namespace ttb_rviz_plugin

#endif // ROBOT_BOX
