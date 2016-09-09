#include <QVBoxLayout>

#include "TurtlePanel.h"

using kobuki_msgs::SensorState;

#define CONFIG_NAME "Robots"

namespace ttb_rviz_plugin {

TurtlePanel::TurtlePanel(QWidget *parent)
	: rviz::Panel(parent)
{
	// layout setup
	this->parent = parent;
	this->layout = new QVBoxLayout;

	setLayout(layout);
}

TurtlePanel::~TurtlePanel()
{
}

void TurtlePanel::load(const rviz::Config& config) {
	rviz::Panel::load(config);
	QString robots;
	if(config.mapGetString(CONFIG_NAME, &robots)) {
		updateRobots();
	}
}

void TurtlePanel::save(rviz::Config config) {
	allRobots = "";

	for(auto const &robot: robotBoxes) {
		allRobots += robot.first;
		allRobots += ",";
	}

	rviz::Panel::save(config);
	config.mapSetValue(CONFIG_NAME, allRobots);
}

void TurtlePanel::updateRobots() {
	// TODO: implement
}


void TurtlePanel::addRobot(QString &name) {
	RobotBox *box = new RobotBox(name, parent);
	robotBoxes[name] = box;
	layout->addWidget(box);
}

void TurtlePanel::addRobot(const char *name) {
	QString str(name);
	addRobot(str);
}

void TurtlePanel::removeRobot(QString &name) {
	RobotBox *b = robotBoxes.at(name);
	layout->removeWidget(b);
	robotBoxes.erase(name);
}

void TurtlePanel::removeRobot(const char *name) {
	QString str(name);
	removeRobot(str);
}

} // namespace ttb_rviz_plugin

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(ttb_rviz_plugin::TurtlePanel, rviz::Panel)
