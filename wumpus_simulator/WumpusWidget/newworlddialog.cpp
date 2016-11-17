#include "newworlddialog.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

NewWorldDialog::NewWorldDialog(QWidget * parent) : QDialog(parent)
{
    setupUi(this);
    this->setModal(true);

}

void NewWorldDialog::on_randomButton_clicked()
{
    std::cout << "test" << std::endl;
    srand(time(NULL));
    int random = rand() % 50 + 4;
    srand(time(NULL));
    int random2 = rand() % (random * random);
    srand(time(NULL));
    int random3 = rand() % (int)pow(random - random2, 2);
    this->sizePlayground->setText(QString::number(random));
    this->traps->setText(QString::number(random2));
    this->wumpus->setText(QString::number(random3));

    if(random % 2 == 0) {

        this->arrow->toggle();

    }
}
