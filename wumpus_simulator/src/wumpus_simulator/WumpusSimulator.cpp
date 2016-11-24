#include "../../include/wumpus_simulator/WumpusSimulator.h"

#include <qfiledialog.h>
#include <qdebug.h>

namespace wumpus_simulator
{
	WumpusSimulator::WumpusSimulator() : rqt_gui_cpp::Plugin(), widget_(0), guiUpdateTimer_(nullptr)
	{
		setObjectName("WumpusSimulator");
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
}
