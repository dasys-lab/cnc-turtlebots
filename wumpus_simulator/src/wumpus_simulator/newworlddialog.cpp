#include "newworlddialog.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

NewWorldDialog::NewWorldDialog(QWidget * parent) : QDialog(parent)
{
    setupUi(this);
    this->setModal(true);
    this->setWindowModality(Qt::WindowModal);

    //Connect the ok button to a method
    connect(this->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), SLOT(on_buttonBox_accepted()));
    connect(this->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), SLOT(on_buttonBox_rejected()));

}

void NewWorldDialog::on_randomButton_clicked()
{
    //Calculate the field size, number of traps and wumpus randomly
    srand(time(NULL));
    int fieldSize = rand() % 16 + 4;    //Adjust the % value to set the upper bounce
    srand(time(NULL));
    int traps = rand() % (int)(pow(fieldSize, 2) / 4) + 1;
    srand(time(NULL));
    int wumpus = rand() % fieldSize + 1;

    //Set the fields in the gt ui with the random values
    this->sizePlayground->setText(QString::number(fieldSize));
    this->traps->setText(QString::number(traps));
    this->wumpus->setText(QString::number(wumpus));
    if(fieldSize % 2 == 0) {
        this->arrow->toggle();
    }
}

void NewWorldDialog::on_buttonBox_accepted()
{



}

void NewWorldDialog::on_buttonBox_rejected()
{
    this->close();
}
