#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    NewWorldDialog* newWorldForm = new NewWorldDialog(this);
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
