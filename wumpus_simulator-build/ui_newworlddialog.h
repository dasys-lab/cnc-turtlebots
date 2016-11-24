/********************************************************************************
** Form generated from reading UI file 'newworlddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORLDDIALOG_H
#define UI_NEWWORLDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *sizePlayground;
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
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 191);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 148, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 224, 31));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        sizePlayground = new QLineEdit(verticalLayoutWidget);
        sizePlayground->setObjectName(QStringLiteral("sizePlayground"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sizePlayground->sizePolicy().hasHeightForWidth());
        sizePlayground->setSizePolicy(sizePolicy);
        sizePlayground->setMaximumSize(QSize(100, 25));

        horizontalLayout->addWidget(sizePlayground);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 221, 31));
        horizontalLayout_2 = new QHBoxLayout(verticalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        traps = new QLineEdit(verticalLayoutWidget_2);
        traps->setObjectName(QStringLiteral("traps"));
        sizePolicy.setHeightForWidth(traps->sizePolicy().hasHeightForWidth());
        traps->setSizePolicy(sizePolicy);
        traps->setMaximumSize(QSize(100, 25));

        horizontalLayout_2->addWidget(traps);

        verticalLayoutWidget_3 = new QWidget(Dialog);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 70, 221, 31));
        horizontalLayout_3 = new QHBoxLayout(verticalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        wumpus = new QLineEdit(verticalLayoutWidget_3);
        wumpus->setObjectName(QStringLiteral("wumpus"));
        sizePolicy.setHeightForWidth(wumpus->sizePolicy().hasHeightForWidth());
        wumpus->setSizePolicy(sizePolicy);
        wumpus->setMaximumSize(QSize(100, 25));

        horizontalLayout_3->addWidget(wumpus);

        arrow = new QCheckBox(Dialog);
        arrow->setObjectName(QStringLiteral("arrow"));
        arrow->setGeometry(QRect(110, 110, 131, 22));
        randomButton = new QPushButton(Dialog);
        randomButton->setObjectName(QStringLiteral("randomButton"));
        randomButton->setGeometry(QRect(40, 150, 121, 27));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label->setText(QApplication::translate("Dialog", "Playground Size: ", 0));
        label_2->setText(QApplication::translate("Dialog", "Traps:", 0));
        label_3->setText(QApplication::translate("Dialog", "Wumpus:", 0));
        arrow->setText(QApplication::translate("Dialog", "Arrow (Agent)", 0));
        randomButton->setText(QApplication::translate("Dialog", "Random Values", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORLDDIALOG_H
