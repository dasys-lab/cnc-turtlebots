#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <rqt_gui_cpp/plugin.h>

#include "ros/ros.h"
#include <ros/macros.h>
#include <QtGui>
#include <QWidget>
#include <QDialog>

#include <ui_mainwindow.h>


namespace wumpus_simulator
{
	class WumpusSimulator : public rqt_gui_cpp::Plugin
	{
		Q_OBJECT

	public:
		WumpusSimulator();
		~WumpusSimulator();

		virtual void initPlugin(qt_gui_cpp::PluginContext& context);
		virtual void shutdownPlugin();
		virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
		virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

		ros::NodeHandle* rosNode;

		QWidget* widget_;
		QTimer* guiUpdateTimer_;
		Ui::MainWindow mainwindow;

	public Q_SLOTS:

		void on_actionNew_triggered();

		void on_actionLoad_triggered();

		void on_actionSave_triggered();

	private:
	};
}

#endif // MAINWINDOW_H
