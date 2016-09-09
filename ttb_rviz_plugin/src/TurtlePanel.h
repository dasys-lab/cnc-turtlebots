#ifndef TURTLE_PANEL
#define TURTLE_PANEL

#include <ros/ros.h>
#include <rviz/panel.h>
#include <kobuki_msgs/SensorState.h>
#include <vector>

#include "RobotBox.h"

class QLabel;
class QPushButton;
class QVBoxLayout;

namespace ttb_rviz_plugin {

class TurtlePanel : public rviz::Panel {

Q_OBJECT
public:
	TurtlePanel(QWidget *parent = 0);
	~TurtlePanel();

	virtual void load(const rviz::Config& config);
	virtual void save(rviz::Config config);

protected Q_SLOTS:
	void updateRobots();

protected:
	void addRobot(QString &name);
	void addRobot(const char *name);

	void removeRobot(QString &name);
	void removeRobot(const char *name);

	std::map<QString, RobotBox*> robotBoxes;
	QVBoxLayout *layout;
	QWidget *parent;

	// string containing all robot names seperated by comma(,)
	QString allRobots;
};

} // namespace ttb_rviz_plugin

#endif // TURTLE_PANEL
