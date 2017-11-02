/*
 * SettingsDialog.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: stefan
 */

#include <wumpus_simulator/SettingsDialog.h>
#include <wumpus_simulator/NewWorldDialog.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <wumpus_simulator/WumpusSimulator.h>

namespace wumpus_simulator
{
	SettingsDialog::SettingsDialog(QWidget * parent, WumpusSimulator* sim) :
		QDialog(parent)
	{
		this->parent = parent;
		this->sim = sim;
		this->settingsDialog.setupUi(this);
		connect(this->settingsDialog.loadBtn, SIGNAL(released()), SLOT(on_loadBtn()));
		connect(this->settingsDialog.saveBtn, SIGNAL(released()), SLOT(on_saveBtn()));
		connect(this->settingsDialog.newBtn, SIGNAL(released()), SLOT(on_newBtn()));
	}

	SettingsDialog::~SettingsDialog()
	{
	}

	void SettingsDialog::on_newBtn()
	{
		this->close();
		//Open the new world dialog
		NewWorldDialog* newWorldForm = new NewWorldDialog(this->parent, sim);
		newWorldForm->exec();
	}

	void SettingsDialog::on_loadBtn()
	{

//		Open load file dialog to select a pregenerated wumpus world
		this->close();
		QString filename = QFileDialog::getOpenFileName(this->parent, tr("Load World"), QDir::currentPath(),
														tr("Wumpus World File (*.wumpus)"), 0,
														QFileDialog::DontUseNativeDialog);

		//Check if the user selected a correct file
		if (!filename.isNull())
		{

			//TODO: Do magic things
			qDebug(filename.toLatin1());

		}
	}

	void SettingsDialog::on_saveBtn()
	{
		//Open save file dialog to select a pregenerated wumpus world
		this->close();
		QString filename = QFileDialog::getSaveFileName(this->parent, tr("Save World"), QDir::currentPath(),
														tr("Wumpus World File (*.wumpus)"), 0,
														QFileDialog::DontUseNativeDialog);

		//Check if the user selected a correct file
		if (!filename.isNull())
		{

			//TODO: Do magic things
			qDebug(filename.toLatin1());

		}
	}
}
