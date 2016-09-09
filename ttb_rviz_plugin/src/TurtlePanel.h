#ifndef TURTLE_PANEL
#define TURTLE_PANEL

#include <ros/ros.h>
#include <rviz/panel.h>
#include <kobuki_msgs/SensorState.h>
#include <vector>

#include "RobotBox.h"

class QLabel;
class QPushButton;

namespace ttb_rviz_plugin {

class TurtlePanel : public rviz::Panel {

Q_OBJECT
public:

	TurtlePanel(QWidget *parent = 0);
	~TurtlePanel();

	// TODO: for configurable robots
//	virtual void load(const rviz::Config& config);
//	virtual void save(rviz::Config config);

protected:
	// TODO: addRobot, removeRobot

	std::vector<RobotBox*> robotBoxes;
};


} // namespace ttb_rviz_plugin

#endif // TURTLE_PANEL
