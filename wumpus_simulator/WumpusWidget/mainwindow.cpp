#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

    newWorldForm = new QDialog(0,0);
    newWorldForm->setModal(true);
    NewWorldView.setupUi(newWorldForm);
    newWorldForm->show();


}

void MainWindow::on_actionLoad_triggered()
{

    //Open load file dialog to select a pregenerated wumpus world
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load World"),
                                                    QDir::currentPath(),
                                                    tr("Wumpus World File (*.wumpus)"),
                                                    0,
                                                    QFileDialog::DontUseNativeDialog);

    //Check if the user selected a correct file
    if(!filename.isNull()) {

        //TODO: Do magic things
        qDebug(filename.toAscii());

    }
}

void MainWindow::on_actionSave_triggered()
{
    //Open save file dialog to select a pregenerated wumpus world
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save World"),
                                                    QDir::currentPath(),
                                                    tr("Wumpus World File (*.wumpus)"),
                                                    0,
                                                    QFileDialog::DontUseNativeDialog);

    //Check if the user selected a correct file
    if(!filename.isNull()) {

        //TODO: Do magic things
        qDebug(filename.toAscii());

    }
}

void MainWindow::on_randomButton_clicked()
{
    std::cout << "test" << std::endl;
    srand(time(NULL));
    int random = rand() % 50 + 4;
    srand(time(NULL));
    int random2 = rand() % (random * random);
    srand(time(NULL));
    int random3 = rand() % (int)pow(random - random2, 2);
    NewWorldView.size->setText(QString(random));
    NewWorldView.traps->setText(QString(random2));
    NewWorldView.wumpus->setText(QString(random3));

    if(random % 2 == 0) {

        NewWorldView.arrow->toggle();

    }
}
