#include <QVBoxLayout>

#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

#include "TurtlePanel.h"

using kobuki_msgs::SensorState;

#define CONFIG_NAME "Robots"

namespace ttb_rviz_plugin {

TurtlePanel::TurtlePanel(QWidget *parent)
	: rviz::Panel(parent)
{
	// layout setup
	this->parent = parent;
	layout = new QVBoxLayout;
	boxesLayout = new QVBoxLayout;

	setLayout(layout);

	// Add Robot HBox
	addBox = new QHBoxLayout(parent);
	robotLineEdit = new QLineEdit(parent);
	addRobotButton = new QPushButton("Add Robot", parent);
	addBox->addWidget(robotLineEdit);
	addBox->addWidget(addRobotButton);
	connect(addRobotButton, SIGNAL(clicked()), this, SLOT(addRobotClicked()));
	connect(robotLineEdit, SIGNAL(returnPressed()), this, SLOT(addRobotClicked()));

	layout->addLayout(addBox);
	layout->addLayout(boxesLayout);
	layout->addStretch();
}

TurtlePanel::~TurtlePanel()
{
	delete addRobotButton;
	delete robotLineEdit;
	delete addBox;
	delete this->layout;
}

void TurtlePanel::load(const rviz::Config& config) {
	rviz::Panel::load(config);
	QString robots;
	if(config.mapGetString(CONFIG_NAME, &robots)) {
		updateRobots(robots);
	}
}

void TurtlePanel::save(rviz::Config config) const {
	QString allRobots = "";

	for(auto const &robot: robotBoxes) {
		allRobots += robot.first;
		allRobots += ",";
	}

	rviz::Panel::save(config);
	config.mapSetValue(CONFIG_NAME, allRobots);
}

void TurtlePanel::updateRobots(QString robots) {
	QStringList robotList = robots.split(",");

	for (int i = 0; i < robotList.size(); i++) {
		QString name = robotList.at(i);
		if (!name.trimmed().isEmpty())
			addRobot(name);
	}
}


void TurtlePanel::addRobot(QString &name) {
	if (robotBoxes.count(name) < 1) {
		RobotBox *box = new RobotBox(name, parent);
		robotBoxes[name] = box;
		boxesLayout->addWidget(box);
		connect(box, SIGNAL(deletePressed(QString)), this, SLOT(removeRobotClicked(QString)));
	}
}

void TurtlePanel::addRobot(const char *name) {
	QString str(name);
	addRobot(str);
}

void TurtlePanel::removeRobot(QString &name) {
	RobotBox *b = robotBoxes.at(name);
	boxesLayout->removeWidget(b);
	robotBoxes.erase(name);
	delete b;
}

void TurtlePanel::removeRobot(const char *name) {
	QString str(name);
	removeRobot(str);
}

void TurtlePanel::addRobotClicked() {
	QString robotName = robotLineEdit->text();
	robotLineEdit->setText("");
	addRobot(robotName);
}

void TurtlePanel::removeRobotClicked(QString robot) {
	removeRobot(robot);
}

} // namespace ttb_rviz_plugin

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(ttb_rviz_plugin::TurtlePanel, rviz::Panel)
