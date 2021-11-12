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

void MainWindow::CreateGraph(int n){
Grafo = new graph(n);


//createGafic(&Grafo);


}
bool MainWindow::is_not_on_path(char node,vector<char> *path){
    for (int i = 0 ; i < (*path).size() ;i++){

        if ((*path)[i] == node){
            return false;
            }
    }
    return true;
}

void MainWindow::BestPath(char source, char target){
    vector<char> path;
    vector<char> Bestpath;
    int Temp;
    int Best;
    BestPath_aux( &Bestpath,&Best,&path,&Temp,source,target);
    cout<<"prueba"<<endl;

    for(int i = 0; i < Bestpath.size() ; i++){
        cout<<"prueba2"<<endl;
        cout<<Bestpath[i]<<endl;
    }

     cout<<"prueba2"<<endl;

}


void updateMin(vector<char> *Bestpath,int *Best,vector<char> *path,int *Temp){
    if (*Temp<*Best){
        *Bestpath = *path;
        *Best = *Temp;
    }


}
void MainWindow::updateTemp(int n ,int *Temp){
    if (n<(*Temp)){
        *Temp= n;
    }

}


void MainWindow::BestPath_aux(vector<char> *Bestpath,int *Best,vector<char> *path,int *Temp,char source,char target){
    vector<int> lista =  (*Grafo).getRelationof(source); // relaciones, exceo node
    (*path).push_back(source);
    char node;

    for(int i = 0; i < lista.size() ; i++){
        node = (*Grafo).getnodePos(i);
        if(lista[i]>0){
            if (is_not_on_path(node,path)){
                updateTemp(lista[i],Temp);
                if (node == target ){
                (*path).push_back(target);
                 updateMin(Bestpath,Best,path,Temp);
                }
                else{
                    BestPath_aux(Bestpath,Best,path,Temp,node,target);
                }
            }
        }
    }(*path).pop_back();
}


void MainWindow::on_pushButton_clicked()
{
    CreateGraph(6);

    BestPath('a','f');
}

