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
    QGraphicsView *genGrapcsView;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextBtn;

    void setupUi(QWidget *showgen)
    {
        if (showgen->objectName().isEmpty())
            showgen->setObjectName(QString::fromUtf8("showgen"));
        showgen->resize(579, 453);
        gridLayout = new QGridLayout(showgen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        genGrapcsView = new QGraphicsView(showgen);
        genGrapcsView->setObjectName(QString::fromUtf8("genGrapcsView"));

        gridLayout->addWidget(genGrapcsView, 1, 0, 1, 1);

        label = new QLabel(showgen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previousBtn = new QPushButton(showgen);
        previousBtn->setObjectName(QString::fromUtf8("previousBtn"));
        previousBtn->setStyleSheet(QString::fromUtf8("font: 57 11pt \"aakar\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(previousBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nextBtn = new QPushButton(showgen);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));
        nextBtn->setStyleSheet(QString::fromUtf8("font: 57 11pt \"aakar\";\n"
"background-color: rgb(238, 238, 236);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(nextBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);


        retranslateUi(showgen);

        QMetaObject::connectSlotsByName(showgen);
    } // setupUi

    void retranslateUi(QWidget *showgen)
    {
        showgen->setWindowTitle(QCoreApplication::translate("showgen", "Form", nullptr));
        label->setText(QCoreApplication::translate("showgen", "Previous Generations...", nullptr));
        previousBtn->setText(QCoreApplication::translate("showgen", "Previous", nullptr));
        nextBtn->setText(QCoreApplication::translate("showgen", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showgen: public Ui_showgen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWGEN_H
