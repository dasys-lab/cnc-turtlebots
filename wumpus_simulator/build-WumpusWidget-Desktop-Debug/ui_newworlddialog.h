/********************************************************************************
** Form generated from reading UI file 'newworlddialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORLDDIALOG_H
#define UI_NEWWORLDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QAction *actionOnRandomPressed;
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *size;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *traps;
    QWidget *verticalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *wumpus;
    QCheckBox *arrow;
    QPushButton *randomButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 191);
        actionOnRandomPressed = new QAction(Dialog);
        actionOnRandomPressed->setObjectName(QString::fromUtf8("actionOnRandomPressed"));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 148, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 224, 31));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        size = new QLineEdit(verticalLayoutWidget);
        size->setObjectName(QString::fromUtf8("size"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(size->sizePolicy().hasHeightForWidth());
        size->setSizePolicy(sizePolicy);
        size->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(size);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 221, 31));
        horizontalLayout_2 = new QHBoxLayout(verticalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        traps = new QLineEdit(verticalLayoutWidget_2);
        traps->setObjectName(QString::fromUtf8("traps"));
        sizePolicy.setHeightForWidth(traps->sizePolicy().hasHeightForWidth());
        traps->setSizePolicy(sizePolicy);
        traps->setMaximumSize(QSize(100, 25));

        horizontalLayout_2->addWidget(traps);

        verticalLayoutWidget_3 = new QWidget(Dialog);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 70, 221, 31));
        horizontalLayout_3 = new QHBoxLayout(verticalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        wumpus = new QLineEdit(verticalLayoutWidget_3);
        wumpus->setObjectName(QString::fromUtf8("wumpus"));
        sizePolicy.setHeightForWidth(wumpus->sizePolicy().hasHeightForWidth());
        wumpus->setSizePolicy(sizePolicy);
        wumpus->setMaximumSize(QSize(100, 25));

        horizontalLayout_3->addWidget(wumpus);

        arrow = new QCheckBox(Dialog);
        arrow->setObjectName(QString::fromUtf8("arrow"));
        arrow->setGeometry(QRect(110, 110, 131, 22));
        randomButton = new QPushButton(Dialog);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        randomButton->setGeometry(QRect(40, 150, 121, 27));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
        QObject::connect(randomButton, SIGNAL(clicked()), randomButton, SLOT(click()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        actionOnRandomPressed->setText(QApplication::translate("Dialog", "onRandomPressed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOnRandomPressed->setToolTip(QApplication::translate("Dialog", "Random Values", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Dialog", "Playground Size: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Traps:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Wumpus:", 0, QApplication::UnicodeUTF8));
        arrow->setText(QApplication::translate("Dialog", "Arrow (Agent)", 0, QApplication::UnicodeUTF8));
        randomButton->setText(QApplication::translate("Dialog", "Random Values", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORLDDIALOG_H
