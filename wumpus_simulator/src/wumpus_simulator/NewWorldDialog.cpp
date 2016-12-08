#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <wumpus_simulator/NewWorldDialog.h>
#include <wumpus_simulator/WumpusSimulator.h>

namespace wumpus_simulator
{
	NewWorldDialog::NewWorldDialog(QWidget * parent, WumpusSimulator* sim) :
			QDialog(parent)
	{
		this->setModal(true);
		this->setWindowModality(Qt::WindowModal);
		this->sim = sim;
		this->NewWorldView.setupUi(this);
		//Connect the ok button to a method
		connect(this->NewWorldView.buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),
				SLOT(buttonBox_acc()));
		connect(this->NewWorldView.buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()),
				SLOT(buttonBox_rej()));
		connect(this->NewWorldView.randomButton, SIGNAL(clicked()),
				SLOT(randomButton()));


	}

	void NewWorldDialog::randomButton()
	{
		//Calculate the field size, number of traps and wumpus randomly
		srand(time(NULL));
		int fieldSize = rand() % 16 + 4; //Adjust the % value to set the upper bounce
		srand(time(NULL));
		int traps = rand() % (int)(pow(fieldSize, 2) / 4) + 1;
		srand(time(NULL));
		int wumpus = rand() % fieldSize + 1;

		//Set the fields in the gt ui with the random values
		this->NewWorldView.sizePlayground->setText(QString::number(fieldSize));
		this->NewWorldView.traps->setText(QString::number(traps));
		this->NewWorldView.wumpus->setText(QString::number(wumpus));
		if (fieldSize % 2 == 0)
		{
			this->NewWorldView.arrow->toggle();
		}
	}

	void NewWorldDialog::buttonBox_acc()
	{
		if(this->NewWorldView.sizePlayground->text().size() == 0 ||
				this->NewWorldView.wumpus->text().size() == 0 ||
				this->NewWorldView.traps->text().size() == 0)
		{
			return;
		}
		this->sim->mainwindow.arrowActiveLabel->setText(
				this->NewWorldView.arrow->isChecked() ? "Arrow: true" : "Arrow: false");
		this->sim->mainwindow.fieldSizeLabel->setText(
				QString("Size: ").append(this->NewWorldView.sizePlayground->text()).append(" x ").append(
						this->NewWorldView.sizePlayground->text()));
		this->sim->mainwindow.trapLabel->setText(
				QString("Traps: ").append(this->NewWorldView.traps->text()));
		this->sim->mainwindow.wumpusLabel->setText(
				QString("Wumpus: ").append(this->NewWorldView.wumpus->text()));

		this->sim->createWorld(this->NewWorldView.arrow->isChecked(),
							   this->NewWorldView.sizePlayground->text().toStdString(),
							   this->NewWorldView.traps->text().toStdString(),
							   this->NewWorldView.wumpus->text().toStdString());

		this->close();
	}

	void NewWorldDialog::buttonBox_rej()
	{
		this->close();
	}
}
