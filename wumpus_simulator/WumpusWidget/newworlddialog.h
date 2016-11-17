#ifndef NEWWORLDDIALOG_H
#define NEWWORLDDIALOG_H

#include <QDialog>
#include <iostream>
#include "ui_newworlddialog.h"

class NewWorldDialog : public QDialog, public Ui::Dialog
{
    Q_OBJECT

public:
    NewWorldDialog(QWidget * parent = 0);

private slots:

    void on_randomButton_clicked();

private:
    Ui::Dialog NewWorldView;

};

#endif // NEWWORLDDIALOG_H
