#ifndef ROBOT_BOX
#define ROBOT_BOX

#include <ros/ros.h>

#include <QGroupBox>

class QLabel;
class QWidget;
class QString;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

#include <actionlib_msgs/GoalStatusArray.h>
#include <kobuki_msgs/SensorState.h>
#include <geometry_msgs/PoseStamped.h>

namespace ttb_rviz_plugin {

class RobotBox : public QGroupBox {

enum HomeState { NoHome = 0, SetHome, HomeSet };
const char *homeButtonStrings[3] = {"Set Home", "Send Nav to set Home", "Come Home"};

Q_OBJECT
public:
	RobotBox(const QString& robot, QWidget *parent);
	~RobotBox();

	void setHome(geometry_msgs::PoseStamped h);
	const bool hasHome();
	const geometry_msgs::PoseStamped* getHome();

Q_SIGNALS:
	void deletePressed(QString robotName);

protected Q_SLOTS:

	void displayReceived();
	void abortPressed();
	void homePressed();
	void deleteButtonPressed();
	void toggled(bool on);

protected:
	unsigned long lastReceived;

	void sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg);
	void goalStatusCallback(const actionlib_msgs::GoalStatusArray& msg);
	void goalCallback(const geometry_msgs::PoseStamped& msg);

	void displayBaseBattery(int battery);
	void displayBatteryState(int state);

	QString robot;
	std::string goalID;

	enum HomeState homeState = NoHome;
	geometry_msgs::PoseStamped home;

	QVBoxLayout *layout;
	QHBoxLayout *topLayout;
	QHBoxLayout *buttonLayout;

	QLabel *batteryLabel;
	QLabel *batteryStateLabel;
	QLabel *lastReceivedLabel;
	QLabel *goalStatusLabel;
	QPushButton *abortButton;
	QPushButton *homeButton;
	QPushButton *deleteButton;

	QTimer *timer;

	ros::Subscriber batterySub;
	ros::Subscriber statusSub;
    	ros::Subscriber goalSub;
    	ros::Publisher abortPub;
    	ros::Publisher goalPub;
	ros::NodeHandle nh;
};

} // namespace ttb_rviz_plugin

#endif // ROBOT_BOX
