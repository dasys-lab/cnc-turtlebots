/*
 * SettingsDialog.h
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#ifndef INCLUDE_WUMPUS_SIMULATOR_SETTINGSDIALOG_H_
#define INCLUDE_WUMPUS_SIMULATOR_SETTINGSDIALOG_H_

#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <rqt_gui_cpp/plugin.h>

#include <ui_settingsdialog.h>

using namespace std;

namespace wumpus_simulator
{
	class WumpusSimulator;
	class SettingsDialog : public QDialog
	{
	Q_OBJECT

	public:
		SettingsDialog(QWidget * parent, WumpusSimulator* sim);
		virtual ~SettingsDialog();

	private slots:
		void on_newBtn();
		void on_loadBtn();
		void on_saveBtn();

	private:
		Ui::SettingsDialog settingsDialog;
		QWidget * parent;
		WumpusSimulator* sim;
	};
}
#endif /* INCLUDE_WUMPUS_SIMULATOR_SETTINGSDIALOG_H_ */
