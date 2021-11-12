#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <graph.h>
#include <QMainWindow>
#include <iostream>
#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include <QGraphicsLineItem>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public  QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    graph *Grafo;
    vector<QGraphicsEllipseItem*>nodesG;
    void CreateGraph(int);
    bool is_not_on_path(char ,vector<char>*);
    void updateTemp(int,int*);
    void BestPath_aux(vector<char>*,int*,vector<char>*,int*,char,char);
    void BestPath(char , char );
    void createGrafic();
    QGraphicsScene *scene;



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
