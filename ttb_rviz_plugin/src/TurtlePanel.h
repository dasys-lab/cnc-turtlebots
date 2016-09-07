#ifndef Q_MOC_RUN
# include <ros/ros.h>

# include <rviz/panel.h>
#endif

#include <kobuki_msgs/SensorState.h>

class QLabel;
class QPushButton;

namespace ttb_rviz_plugin {

class TurtlePanel : public rviz::Panel {

Q_OBJECT
public:

	TurtlePanel(QWidget *parent = 0); 
	~TurtlePanel(); 

//	virtual void load(const rviz::Config& config);
//	virtual void save(rviz::Config config);

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


