/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QLabel *arrowActiveLabel;
    QLabel *wumusLabel;
    QLabel *trapLabel;
    QLabel *fieldSizeLabel;
    QMenuBar *menuBar;
    QMenu *menuWumpus_Simulator;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        gridLayoutWidget = new QWidget(splitter_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter_2->addWidget(gridLayoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        arrowActiveLabel = new QLabel(splitter);
        arrowActiveLabel->setObjectName(QStringLiteral("arrowActiveLabel"));
        arrowActiveLabel->setMaximumSize(QSize(16777215, 25));
        splitter->addWidget(arrowActiveLabel);
        wumusLabel = new QLabel(splitter);
        wumusLabel->setObjectName(QStringLiteral("wumusLabel"));
        wumusLabel->setMinimumSize(QSize(0, 0));
        wumusLabel->setMaximumSize(QSize(16777215, 25));
        splitter->addWidget(wumusLabel);
        trapLabel = new QLabel(splitter);
        trapLabel->setObjectName(QStringLiteral("trapLabel"));
        trapLabel->setMaximumSize(QSize(16777215, 25));
        splitter->addWidget(trapLabel);
        fieldSizeLabel = new QLabel(splitter);
        fieldSizeLabel->setObjectName(QStringLiteral("fieldSizeLabel"));
        fieldSizeLabel->setMaximumSize(QSize(16777215, 25));
        splitter->addWidget(fieldSizeLabel);
        splitter_2->addWidget(splitter);

        gridLayout_2->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        menuWumpus_Simulator = new QMenu(menuBar);
        menuWumpus_Simulator->setObjectName(QStringLiteral("menuWumpus_Simulator"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuWumpus_Simulator->menuAction());
        menuWumpus_Simulator->addAction(actionNew);
        menuWumpus_Simulator->addSeparator();
        menuWumpus_Simulator->addAction(actionLoad);
        menuWumpus_Simulator->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        arrowActiveLabel->setText(QApplication::translate("MainWindow", "Arrow:", 0));
        wumusLabel->setText(QApplication::translate("MainWindow", "Wumpus:", 0));
        trapLabel->setText(QApplication::translate("MainWindow", "Traps:", 0));
        fieldSizeLabel->setText(QApplication::translate("MainWindow", "Size: {{n}}x{{n}}", 0));
        menuWumpus_Simulator->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
