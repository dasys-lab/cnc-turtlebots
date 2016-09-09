#ifndef Q_MOC_RUN
# include <ros/ros.h>

# include <rviz/panel.h>
#endif

#include <kobuki_msgs/SensorState.h>

#include <QGroupBox>

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