#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QPushButton>

#include <kobuki_msgs/SensorState.h>
#include <ctime>

#include "RobotBox.h"

#define BATTERY_TOPIC "mobile_base/sensors/core"
#define BAT_MAX 16.0

using kobuki_msgs::SensorState;

namespace ttb_rviz_plugin {

RobotBox::RobotBox(const QString& robot, QWidget *parent)
	: QGroupBox(robot , parent), lastReceived(0), robot(robot)
{
	setCheckable(true);
	// create widgets
	lastReceivedLabel = new QLabel("No message received yet");
	batteryLabel = new QLabel("Base Battery: Not received yet");
	batteryStateLabel = new QLabel("State: ");
	abortButton = new QPushButton("Abort Movement", parent);
	deleteButton = new QPushButton("x", parent);
	deleteButton->setMaximumWidth(20);

	// layout setup
	layout = new QVBoxLayout(parent);
	QHBoxLayout *topLayout = new QHBoxLayout(parent);

	topLayout->addWidget(lastReceivedLabel);
	topLayout->addWidget(deleteButton);
	layout->addLayout(topLayout);

	layout->addWidget(batteryLabel);
	layout->addWidget(batteryStateLabel);
	// TODO: Implement goal watching
	//layout->addWidget(abortButton);
	setLayout(layout);

	connect(abortButton, SIGNAL(clicked()), this, SLOT(abortPressed()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonPressed()));
	connect(this, SIGNAL(toggled(bool)), this, SLOT(toggled(bool)));

	// timer for last received
	timer = new QTimer(parent);
	connect(timer, SIGNAL(timeout()), this, SLOT(displayReceived()));
	timer->start(1000);

	QString topic;
	topic.sprintf("%s/%s", robot.toLatin1().data(), BATTERY_TOPIC);

	// ros
	batterySub = nh.subscribe(topic.toLatin1().data(), 1000, &RobotBox::sensorCallback, this);
}

RobotBox::~RobotBox()
{
	timer->stop();

	delete lastReceivedLabel;
	delete batteryLabel;
	delete batteryStateLabel;
	delete timer;
	delete deleteButton;
	delete abortButton;
	delete layout;
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
	lastReceivedLabel->setText("Abort!");
}

void RobotBox::deleteButtonPressed() {
	Q_EMIT deletePressed(robot);
}

void RobotBox::sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg) {
	lastReceived = time(NULL);

	displayBaseBattery(msg->battery);
	displayBatteryState(msg->charger);
}

void RobotBox::toggled(bool on) {
	lastReceivedLabel->setVisible(on);
	batteryLabel->setVisible(on);
	batteryStateLabel->setVisible(on);
	//abortButton->setVisible(on);
	deleteButton->setVisible(on);
}

void RobotBox::displayBaseBattery(int battery) {
	double batVoltage;
	QString batString;

	batVoltage = battery / 10.0;
	// TODO: Calcualte capacity?

	batString.sprintf("Base Battery: %.1fV/%.1fV",
					batVoltage, BAT_MAX);

	batteryLabel->setText(batString);
}

void RobotBox::displayBatteryState(int state) {
	QString stateText;

	switch (state) {
		case SensorState::DISCHARGING:
			stateText = "Discharging";
			break;
		case SensorState::DOCKING_CHARGED:
			stateText = "Charged on Dock";
			break;
		case SensorState::DOCKING_CHARGING:
			stateText = "Charging on Dock";
			break;
		case SensorState::ADAPTER_CHARGED:
			stateText = "Charged on Adapter";
			break;
		case SensorState::ADAPTER_CHARGING:
			stateText = "Charging on Adapter";
			break;
		default:
			stateText = "Unknown";
			break;
	}

	batteryStateLabel->setText("State: " + stateText);
}

} // namespace ttb_rviz_plugin
