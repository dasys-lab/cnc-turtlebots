#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QPushButton>

#include <kobuki_msgs/SensorState.h>
#include <ctime>

#include "TurtlePanel.h"

#define BATTERY_TOPIC "mobile_base/sensors/core"
#define BAT_MAX 16.0

using kobuki_msgs::SensorState;

namespace ttb_rviz_plugin {

TurtlePanel::TurtlePanel(QWidget *parent)
	: rviz::Panel(parent)
{
	// layout setup
	lastReceivedLabel = new QLabel("Message received ? seconds ago");
	batteryLabel = new QLabel("Base Battery: Not received yet");
	batteryStateLabel = new QLabel("State: ");
	abortButton = new QPushButton("Abort Movement", parent);

	QVBoxLayout *layout = new QVBoxLayout;

	layout->addWidget(lastReceivedLabel);
	layout->addWidget(batteryLabel);
	layout->addWidget(batteryStateLabel);
	layout->addWidget(abortButton);
	setLayout(layout);

	connect(abortButton, SIGNAL(clicked()), this, SLOT(abortPressed()));

	// timer for last received
	timer = new QTimer(parent);
	connect(timer, SIGNAL(timeout()), this, SLOT(displayReceived()));
	timer->start(1000);

	// ros
	batterySub = nh.subscribe("raphael" "/" BATTERY_TOPIC, 1000, &TurtlePanel::sensorCallback, this);
}

TurtlePanel::~TurtlePanel()
{
	timer->stop();

	delete lastReceivedLabel;
	delete batteryLabel;
	delete batteryStateLabel;
	delete timer;
}

void TurtlePanel::displayReceived() {
	time_t now = time(NULL);
	time_t diff;
	QString str;

	diff = now - lastReceived;

	str.sprintf("Message received %ld seconds ago", diff);

	lastReceivedLabel->setText(str);
}

void TurtlePanel::abortPressed() {
	lastReceivedLabel->setText("Abort!");
}

void TurtlePanel::sensorCallback(const kobuki_msgs::SensorStateConstPtr& msg) {
	lastReceived = time(NULL);

	displayBaseBattery(msg->battery);
	displayBatteryState(msg->charger);
}

void TurtlePanel::displayBaseBattery(int battery) {
	double batVoltage;
	QString batString;

	batVoltage = battery / 10.0;
	// TODO: Calcualte capacity?

	batString.sprintf("Base Battery: %.1fV/%.1fV",
								batVoltage, BAT_MAX);

	batteryLabel->setText(batString);
}

void TurtlePanel::displayBatteryState(int state) {

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

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(ttb_rviz_plugin::TurtlePanel, rviz::Panel)
