#include <QVBoxLayout>

#include "TurtlePanel.h"

using kobuki_msgs::SensorState;

namespace ttb_rviz_plugin {

TurtlePanel::TurtlePanel(QWidget *parent)
	: rviz::Panel(parent)
{
	// layout setup
	QVBoxLayout *layout = new QVBoxLayout;

	RobotBox *box;

	box = new RobotBox("raphael", parent);
	robotBoxes.push_back(box);
	layout->addWidget(box);

	box = new RobotBox("donatello", parent);
	robotBoxes.push_back(box);
	layout->addWidget(box);

	setLayout(layout);
}

TurtlePanel::~TurtlePanel()
{
	for (RobotBox *b : robotBoxes) {
		delete b;
	}
}

} // namespace ttb_rviz_plugin

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(ttb_rviz_plugin::TurtlePanel, rviz::Panel)
