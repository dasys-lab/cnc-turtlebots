#include <QVBoxLayout>

#include <QLineEdit>
#include <QRegExpValidator>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMap>

#include "TurtlePanel.h"

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
	QRegExp rx("[a-zA-Z]+");
	QValidator *validator = new QRegExpValidator(rx, this);
	robotLineEdit->setValidator(validator);
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

	rviz::Config rc = config.mapGetChild(CONFIG_NAME);

	for (auto iter = rc.mapIterator(); iter.isValid(); iter.advance()) {
		const QString& rname = iter.currentKey();

		RobotBox* rb = addRobot(rname);
		if (rb == nullptr)
			continue;

		auto hc = iter.currentChild().mapGetChild("Home");
		if (hc.isValid()) {
			geometry_msgs::PoseStamped h;
			QVariant v;

			hc.mapGetValue("x", &v);
			h.pose.position.x = v.toDouble();
			hc.mapGetValue("y", &v);
			h.pose.position.y = v.toDouble();
			hc.mapGetValue("z", &v);
			h.pose.position.z = v.toDouble();
			hc.mapGetValue("qx", &v);
			h.pose.orientation.x = v.toDouble();
			hc.mapGetValue("qy", &v);
			h.pose.orientation.y = v.toDouble();
			hc.mapGetValue("qz", &v);
			h.pose.orientation.z = v.toDouble();
			hc.mapGetValue("qw", &v);
			h.pose.orientation.z = v.toDouble();

			h.header.frame_id = "map";
			rb->setHome(h);
		}

	}
}

void TurtlePanel::save(rviz::Config config) const {
	rviz::Config rcs = config.mapMakeChild(CONFIG_NAME);

	for(auto const &relem: robotBoxes) {
		const QString& rname = relem.first;
		RobotBox* r = relem.second;

		auto rc = rcs.mapMakeChild(rname);

		if (r->hasHome()) {
			auto h = r->getHome();
			auto hc = rc.mapMakeChild("Home");

			hc.mapSetValue("x", h->pose.position.x);
			hc.mapSetValue("y", h->pose.position.y);
			hc.mapSetValue("z", h->pose.position.z);

			hc.mapSetValue("qx", h->pose.orientation.x);
			hc.mapSetValue("qy", h->pose.orientation.y);
			hc.mapSetValue("qz", h->pose.orientation.z);
			hc.mapSetValue("qw", h->pose.orientation.w);
		}

	}

	rviz::Panel::save(config);
}

RobotBox *TurtlePanel::addRobot(const QString &name) {
	if (robotBoxes.count(name) < 1 && !name.isEmpty()) {
		RobotBox *box = new RobotBox(name, parent);
		robotBoxes[name] = box;
		boxesLayout->addWidget(box);
		connect(box, SIGNAL(deletePressed(QString)), this, SLOT(removeRobotClicked(QString)));
		return box;
	}
	return nullptr;
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
