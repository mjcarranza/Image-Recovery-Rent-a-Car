/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Crear_Grafo;
    QGraphicsView *Lienso;
    QLineEdit *TargetG;
    QLineEdit *SourceG;
    QPushButton *Buscar_Ruta;
    QLineEdit *n_grafo;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1261, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Crear_Grafo = new QPushButton(centralwidget);
        Crear_Grafo->setObjectName(QString::fromUtf8("Crear_Grafo"));
        Crear_Grafo->setGeometry(QRect(1170, 10, 80, 25));
        Lienso = new QGraphicsView(centralwidget);
        Lienso->setObjectName(QString::fromUtf8("Lienso"));
        Lienso->setEnabled(true);
        Lienso->setGeometry(QRect(0, 0, 1161, 601));
        TargetG = new QLineEdit(centralwidget);
        TargetG->setObjectName(QString::fromUtf8("TargetG"));
        TargetG->setGeometry(QRect(1170, 150, 81, 24));
        SourceG = new QLineEdit(centralwidget);
        SourceG->setObjectName(QString::fromUtf8("SourceG"));
        SourceG->setGeometry(QRect(1170, 110, 81, 24));
        Buscar_Ruta = new QPushButton(centralwidget);
        Buscar_Ruta->setObjectName(QString::fromUtf8("Buscar_Ruta"));
        Buscar_Ruta->setGeometry(QRect(1170, 80, 80, 25));
        n_grafo = new QLineEdit(centralwidget);
        n_grafo->setObjectName(QString::fromUtf8("n_grafo"));
        n_grafo->setGeometry(QRect(1170, 40, 71, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1170, 270, 80, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1261, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Crear_Grafo->setText(QCoreApplication::translate("MainWindow", "Crear Grafo", nullptr));
        Buscar_Ruta->setText(QCoreApplication::translate("MainWindow", "Buscar ruta", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
