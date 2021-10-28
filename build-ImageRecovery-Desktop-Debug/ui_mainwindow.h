/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Open;
    QAction *Save;
    QAction *Cut;
    QAction *Recover;
    QAction *Show_previous_solutions;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *wlineEdit;
    QLineEdit *ylineEdit;
    QLineEdit *hlineEdit;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *xlineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(695, 675);
        MainWindow->setMaximumSize(QSize(700, 675));
        Open = new QAction(MainWindow);
        Open->setObjectName(QString::fromUtf8("Open"));
        Save = new QAction(MainWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        Cut = new QAction(MainWindow);
        Cut->setObjectName(QString::fromUtf8("Cut"));
        Recover = new QAction(MainWindow);
        Recover->setObjectName(QString::fromUtf8("Recover"));
        Show_previous_solutions = new QAction(MainWindow);
        Show_previous_solutions->setObjectName(QString::fromUtf8("Show_previous_solutions"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(675, 460));
        graphicsView->setMaximumSize(QSize(675, 460));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 57 20pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        wlineEdit = new QLineEdit(centralwidget);
        wlineEdit->setObjectName(QString::fromUtf8("wlineEdit"));

        gridLayout->addWidget(wlineEdit, 2, 3, 1, 1);

        ylineEdit = new QLineEdit(centralwidget);
        ylineEdit->setObjectName(QString::fromUtf8("ylineEdit"));

        gridLayout->addWidget(ylineEdit, 1, 3, 1, 1);

        hlineEdit = new QLineEdit(centralwidget);
        hlineEdit->setObjectName(QString::fromUtf8("hlineEdit"));

        gridLayout->addWidget(hlineEdit, 3, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        xlineEdit = new QLineEdit(centralwidget);
        xlineEdit->setObjectName(QString::fromUtf8("xlineEdit"));

        gridLayout->addWidget(xlineEdit, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 57 15pt \"aakar\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(label, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 695, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addAction(Open);
        menuFile->addAction(Save);
        menuEdit->addAction(Cut);
        menuTools->addAction(Recover);
        menuTools->addAction(Show_previous_solutions);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Cut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        Recover->setText(QCoreApplication::translate("MainWindow", "Recover", nullptr));
        Show_previous_solutions->setText(QCoreApplication::translate("MainWindow", "Show previous solutions", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CUTTING DIMENTIONS:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Position Y", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "High", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Position X", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
