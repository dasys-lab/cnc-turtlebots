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
