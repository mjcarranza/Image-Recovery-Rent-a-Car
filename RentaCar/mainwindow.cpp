#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::CreateGraph(int n){
//Grafo = new graph(n);
//createGafic(&Grafo);
//
//
//}
//bool MainWindow::is_not_on_path(char node,vector<char> *path){
//  for x in (path){
        //if x == node:
//          //return false;
    //}return true;
//}

// void MainWindow::BestPath(char source, char target){
//vector<char> path;
//vector<char> Bestpath;
//int Temp;
//int Best;
// BestPath_aux(vector<int> &Bestpath,&Best,&path,&Temp,source,target);

//  }
//BestPath_aux(vector<char> *Bestpath,int *Best,vector<char> *path,int *Temp,source,target){
//vector<int> lista =  this->*Grafo.getRelationof(char) // relaciones, exceo node

     //   for i in (lista){
       //      if (is_not_on_path(x,path)){
         //       if (i is T ){
        //coompareMin(){
         //       actualizar path y min }
           //     else :
             //       gunc (node);12

        //}
        //}

        //}
