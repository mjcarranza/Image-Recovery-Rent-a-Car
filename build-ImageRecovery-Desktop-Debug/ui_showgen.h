/********************************************************************************
** Form generated from reading UI file 'showgen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWGEN_H
#define UI_SHOWGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showgen
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *showgen)
    {
        if (showgen->objectName().isEmpty())
            showgen->setObjectName(QString::fromUtf8("showgen"));
        showgen->resize(579, 453);
        gridLayout = new QGridLayout(showgen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(showgen);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        label = new QLabel(showgen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(showgen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 57 11pt \"aakar\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(showgen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font: 57 11pt \"aakar\";\n"
"background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);


        retranslateUi(showgen);

        QMetaObject::connectSlotsByName(showgen);
    } // setupUi

    void retranslateUi(QWidget *showgen)
    {
        showgen->setWindowTitle(QCoreApplication::translate("showgen", "Form", nullptr));
        label->setText(QCoreApplication::translate("showgen", "Previous Generations...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("showgen", "Previous", nullptr));
        pushButton->setText(QCoreApplication::translate("showgen", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showgen: public Ui_showgen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWGEN_H
