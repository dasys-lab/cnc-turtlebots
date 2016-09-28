#ifndef TURTLE_PANEL
#define TURTLE_PANEL

#include <vector>
#include <rviz/panel.h>
#include <ros/ros.h>
#include <kobuki_msgs/SensorState.h>

#include "RobotBox.h"

class QLabel;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;

namespace ttb_rviz_plugin {

class TurtlePanel : public rviz::Panel {

Q_OBJECT
public:
	TurtlePanel(QWidget *parent = 0);
	~TurtlePanel();

	virtual void load(const rviz::Config& config);
	virtual void save(rviz::Config config) const;

protected Q_SLOTS:
	void addRobotClicked();
	void removeRobotClicked(QString robot);

protected:
	RobotBox *addRobot(const QString &name);
	void addRobot(QString &name, double &x, double &y);
	void addRobot(const char *name);

	void removeRobot(QString &name);
	void removeRobot(const char *name);

	// Add Robot HBox
	QHBoxLayout *addBox;
	QLineEdit *robotLineEdit;
	QPushButton *addRobotButton;

	QVBoxLayout *boxesLayout;
	std::map<QString, RobotBox*> robotBoxes;
	QVBoxLayout *layout;
	QWidget *parent;
};

} // namespace ttb_rviz_plugin

#endif // TURTLE_PANEL
