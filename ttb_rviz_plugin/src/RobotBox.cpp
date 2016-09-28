#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QPushButton>

#include <ctime>

#include <actionlib_msgs/GoalID.h>
#include <actionlib_msgs/GoalStatus.h>

#include "RobotBox.h"

#define BATTERY_TOPIC "mobile_base/sensors/core"
#define STATUS_TOPIC "move_base/status"
#define CANCEL_TOPIC "move_base/cancel"
#define GOAL_TOPIC "move_base_simple/goal"
#define BAT_MAX 16.0

namespace ttb_rviz_plugin {

RobotBox::RobotBox(const QString& robot, QWidget *parent)
	: QGroupBox(robot , parent), lastReceived(0), robot(robot)
{
	setCheckable(true);

	// create widgets
	lastReceivedLabel = new QLabel("No message received yet");
	batteryLabel = new QLabel("Base Battery: Not received yet");
	batteryStateLabel = new QLabel("State: ");
	goalStatusLabel = new QLabel("Goal Status: ");
	goalStatusLabel->setWordWrap(true);
	abortButton = new QPushButton("Abort Movement", parent);
	deleteButton = new QPushButton("x", parent);
	deleteButton->setMaximumWidth(20);
	homeButton = new QPushButton(homeButtonStrings[homeState], parent);

	// layout setup
	topLayout = new QHBoxLayout(parent);
	topLayout->addWidget(lastReceivedLabel);
	topLayout->addWidget(deleteButton);
	
	layout = new QVBoxLayout(parent);
	layout->addLayout(topLayout);

	layout->addWidget(batteryLabel);
	layout->addWidget(batteryStateLabel);
	layout->addWidget(goalStatusLabel);

	buttonLayout = new QHBoxLayout(parent);
	buttonLayout->addWidget(abortButton);
	buttonLayout->addWidget(homeButton);

	layout->addLayout(buttonLayout);
	setLayout(layout);

	// connect gui elements
	connect(abortButton, SIGNAL(clicked()), this, SLOT(abortPressed()));
	connect(homeButton, SIGNAL(clicked()), this, SLOT(homePressed()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonPressed()));
	connect(this, SIGNAL(toggled(bool)), this, SLOT(toggled(bool)));

	// timer for last received message in panel
	timer = new QTimer(parent);
	connect(timer, SIGNAL(timeout()), this, SLOT(displayReceived()));
	timer->start(1000);

	// subscribe and advertise namespaced topics
	const QString batteryTopic = robot + "/" + BATTERY_TOPIC;
	const QString statusTopic = robot + "/" + STATUS_TOPIC;
	const QString goalTopic = robot + "/" + GOAL_TOPIC;
	const QString cancelTopic = robot + "/" + CANCEL_TOPIC;

	batterySub = nh.subscribe(batteryTopic.toLatin1().data(), 1000, &RobotBox::sensorCallback, this);
	statusSub = nh.subscribe(statusTopic.toLatin1().data(), 1000, &RobotBox::goalStatusCallback, this);
	goalSub = nh.subscribe(goalTopic.toLatin1().data(), 1000, &RobotBox::goalCallback, this);

	abortPub = nh.advertise<actionlib_msgs::GoalID>(cancelTopic.toLatin1().data(), 1000);
	goalPub = nh.advertise<geometry_msgs::PoseStamped>(goalTopic.toLatin1().data(), 1000);
}

RobotBox::~RobotBox()
{
	timer->stop();
	delete lastReceivedLabel;
	delete batteryLabel;
	delete batteryStateLabel;
	delete goalStatusLabel;
	delete timer;
	delete deleteButton;
	delete abortButton;
	delete homeButton;
	delete topLayout;
	delete buttonLayout;
	delete layout;
}

void RobotBox::setHome(geometry_msgs::PoseStamped h) {
	homeState = HomeSet;
	home = h;
	homeButton->setText(homeButtonStrings[homeState]);
}

const bool RobotBox::hasHome() {
	return homeState == HomeSet;
}

const geometry_msgs::PoseStamped* RobotBox::getHome() {
	return &home;
}

void RobotBox::displayReceived() {
	time_t now = time(NULL);
	time_t diff;
	QString str;

	if (lastReceived == 0) {
		str = "No message received yet";
	} else {
		diff = now - lastReceived;
		str.sprintf("Message received %ld seconds ago", diff);
	}

	lastReceivedLabel->setText(str);
}

void RobotBox::abortPressed() {
	std::cerr << "Aborting movement with goalID" << goalID << std::endl;
	actionlib_msgs::GoalID msg;
	msg.id = goalID;
	abortPub.publish(msg);
}

void RobotBox::homePressed() {
	if (homeState == NoHome) {
		fprintf(stderr, "Setting home mode!\n");
		homeState = SetHome;
		homeButton->setText(homeButtonStrings[homeState]);
	} else if (homeState == HomeSet) {
		goalPub.publish(home);
	}
}

void RobotBox::deleteButtonPressed() {
	Q_EMIT deletePressed(robot);
}

void RobotBox::sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg) {
	lastReceived = time(NULL);

	displayBaseBattery(msg->battery);
	displayBatteryState(msg->charger);
}

void RobotBox::goalCallback(const geometry_msgs::PoseStamped& msg) {
	if (homeState == SetHome) {
		fprintf(stderr, "Setting home %f %f\n", msg.pose.position.x, msg.pose.position.y);
		home = msg;
		homeState = HomeSet;
		homeButton->setText(homeButtonStrings[homeState]);
	}
}

void RobotBox::goalStatusCallback(const actionlib_msgs::GoalStatusArray& msg) {
	if (msg.status_list.size() < 1)
		return;
	const int i = msg.status_list.size() - 1; // always use latest goal

	goalID = msg.status_list[i].goal_id.id;
	QString goalStatus = "Goal Status: " +
		QString::fromStdString(msg.status_list[i].text);

	goalStatusLabel->setText(goalStatus);
}

void RobotBox::toggled(bool on) {
	lastReceivedLabel->setVisible(on);
	batteryLabel->setVisible(on);
	batteryStateLabel->setVisible(on);
	goalStatusLabel->setVisible(on);
	abortButton->setVisible(on);
	deleteButton->setVisible(on);
	homeButton->setVisible(on);
}

void RobotBox::displayBaseBattery(int battery) {
	double batVoltage;
	QString batString;

	batVoltage = battery / 10.0;

	batString.sprintf("Base Battery: %.1fV/%.1fV",
					batVoltage, BAT_MAX);

	batteryLabel->setText(batString);
}

void RobotBox::displayBatteryState(int state) {
	QString stateText;

	switch (state) {
		case kobuki_msgs::SensorState::DISCHARGING:
			stateText = "Discharging";
			break;
		case kobuki_msgs::SensorState::DOCKING_CHARGED:
			stateText = "Charged on Dock";
			break;
		case kobuki_msgs::SensorState::DOCKING_CHARGING:
			stateText = "Charging on Dock";
			break;
		case kobuki_msgs::SensorState::ADAPTER_CHARGED:
			stateText = "Charged on Adapter";
			break;
		case kobuki_msgs::SensorState::ADAPTER_CHARGING:
			stateText = "Charging on Adapter";
			break;
		default:
			stateText = "Unknown";
			break;
	}

	batteryStateLabel->setText("State: " + stateText);
}

} // namespace ttb_rviz_plugin
