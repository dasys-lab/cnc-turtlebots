#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include "ui_newworlddialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_randomButton_clicked();

private:
    Ui::MainWindow *ui;

    QDialog *newWorldForm;
    Ui::Dialog NewWorldView;
};

#endif // MAINWINDOW_H
