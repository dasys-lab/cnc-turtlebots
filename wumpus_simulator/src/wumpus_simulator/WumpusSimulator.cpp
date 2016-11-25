#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <qfiledialog.h>
#include <qdebug.h>
#include <pluginlib/class_list_macros.h>
#include <ros/master.h>

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() :
			rqt_gui_cpp::Plugin(), widget_(0), guiUpdateTimer_(nullptr)
	{
		setObjectName("WumpusSimulator");
		rosNode = new ros::NodeHandle();
	}

	WumpusSimulator::~WumpusSimulator()
	{
	}

	void WumpusSimulator::on_actionNew_triggered()
	{
		//Open the new world dialog
//		NewWorldDialog* newWorldForm = new NewWorldDialog(this);
//		newWorldForm->exec();
	}

	void WumpusSimulator::on_actionLoad_triggered()
	{

//		Open load file dialog to select a pregenerated wumpus world
		QString filename = QFileDialog::getOpenFileName(this->widget_, tr("Load World"), QDir::currentPath(),
														tr("Wumpus World File (*.wumpus)"), 0,
														QFileDialog::DontUseNativeDialog);

		//Check if the user selected a correct file
		if (!filename.isNull())
		{

			//TODO: Do magic things
			qDebug(filename.toLatin1());

		}
	}

	void WumpusSimulator::on_actionSave_triggered()
	{
		//Open save file dialog to select a pregenerated wumpus world
		QString filename = QFileDialog::getSaveFileName(this->widget_, tr("Save World"), QDir::currentPath(),
														tr("Wumpus World File (*.wumpus)"), 0,
														QFileDialog::DontUseNativeDialog);

		//Check if the user selected a correct file
		if (!filename.isNull())
		{

			//TODO: Do magic things
			qDebug(filename.toLatin1());

		}
	}

	void WumpusSimulator::initPlugin(qt_gui_cpp::PluginContext& context)
	{
		this->widget_ = new QWidget();
		this->widget_->setAttribute(Qt::WA_AlwaysShowToolTips, true);
		this->mainwindow.setupUi(this->widget_);

		if (context.serialNumber() > 1)
		{
			this->widget_->setWindowTitle(this->widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
		}
		context.addWidget(this->widget_);
		this->guiUpdateTimer_= new QTimer();
		QObject::connect(this->guiUpdateTimer_, SIGNAL(timeout()), this, SLOT(run()));
		this->guiUpdateTimer_->start(200);
	}

	void WumpusSimulator::shutdownPlugin()
	{
	}

	void WumpusSimulator::saveSettings(qt_gui_cpp::Settings& plugin_settings,
										qt_gui_cpp::Settings& instance_settings) const
	{
	}

	void WumpusSimulator::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
											const qt_gui_cpp::Settings& instance_settings)
	{
	}
}

PLUGINLIB_EXPORT_CLASS(wumpus_simulator::WumpusSimulator, rqt_gui_cpp::Plugin)
