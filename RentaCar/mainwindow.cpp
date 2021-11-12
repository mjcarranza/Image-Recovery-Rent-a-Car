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



void MainWindow::createGrafic(){


    scene = new QGraphicsScene(this);

    int DIAMETER = 50;

    int PosX= -250;
    int PosY = -250;
    int PosX2 = 250;
    int PosY2 = 100;
    QString x;
    QChar y;
    int n = 800;
    QPoint point;
    vector<QPoint>nodospos;


            QGraphicsEllipseItem *circle;
            QGraphicsSimpleTextItem *text;
            srand (time(NULL));
            for(int i = 0 ; i<(*Grafo).nodes.size(); i++){
                PosX = (rand() % ( n ));
                PosY = (rand() % ( n ));
                circle = new QGraphicsEllipseItem(PosX , PosY, DIAMETER, DIAMETER);
                circle->setBrush(Qt::green);

                point.setX(PosX);
                point.setY(PosY);
                nodospos.push_back(point);

                x="";
                y=(*Grafo).nodes[i];
                x=x+y;

                text= new QGraphicsSimpleTextItem(x,circle);
                QFont f;
                f.setPointSize(25);
                text->setFont(f);
                text->setPos(PosX+15,PosY);

                this->nodesG.push_back(&*circle);
              //  PosX = PosX+20;

            }

         //   nodesG[0]->setBrush(Qt::blue);


            QGraphicsLineItem *path;
            QGraphicsSimpleTextItem *peso;
            for (int j = 0; j<(*Grafo).edges.size(); j++){
                PosX= (nodospos[(*Grafo).getposNode((*Grafo).edges[j].SnodeName)]).x();
                PosY = (nodospos[(*Grafo).getposNode((*Grafo).edges[j].SnodeName)]).y();

                PosX2 = (nodospos[(*Grafo).getposNode((*Grafo).edges[j].TnodeName)]).x();
                PosY2 = (nodospos[(*Grafo).getposNode((*Grafo).edges[j].TnodeName)]).y();

            path = new QGraphicsLineItem;
            path->setLine (PosX+25, PosY+25,PosX2+25, PosY2+25);

            QString str = QString::fromStdString(to_string((*Grafo).edges[j].value));


            peso = new QGraphicsSimpleTextItem(str);
            QFont fv;
            fv.setPointSize(15);
            peso->setFont(fv);
            peso->setPos((PosX+PosX2)/2,(PosY+PosY2)/2);
            scene->addItem(path);
            scene->addItem(peso);
            }

            for(int k = 0 ; k<nodesG.size(); k++){
                scene->addItem(nodesG[k]);
            }

          //  scene->addItem(circle);


            ui->Lienso->setScene(scene);



}



void MainWindow::CreateGraph(int n){
Grafo = new graph(n);



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
        change_to_yellow((*Grafo).getnodePos(i) );

        Sleep(1000);
    }

     cout<<"prueba2"<<endl;

}


void updateMin(vector<char> *Bestpath,int *Best,vector<char> *path,int *Temp){
    if (*Temp<*Best){
        *Bestpath = *path;
        *Best = *Temp;
    }(*path).pop_back();



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
                    change_to_yellow(node);
                    Sleep(1000);
                    updateMin(Bestpath,Best,path,Temp);
                    change_to_blue(target);

                }
                else{
                    change_to_yellow(node);
                    Sleep(1000);
                    BestPath_aux(Bestpath,Best,path,Temp,node,target);
                }
            }
        }
    }(*path).pop_back();
    change_to_blue(source);
    Sleep(1000);
}

void MainWindow::change_to_yellow(char c){
    int n =  (*Grafo).getnodePos(c);

    nodesG[n]->setBrush(Qt::yellow);

}

void MainWindow::change_to_blue(char c){

   int n =  (*Grafo).getnodePos(c);

   nodesG[n]->setBrush(Qt::blue);

}

void MainWindow::on_pushButton_clicked()
{
    CreateGraph(6);
    createGrafic();
    BestPath('a','f');

}



void MainWindow::on_Crear_Grafo_clicked()
{

    CreateGraph(stoi(ui->n_grafo->text().toStdString()));
    createGrafic();
}


void MainWindow::on_Buscar_Ruta_clicked()
{
    BestPath((ui->SourceG->text().toStdString())[0],(ui->TargetG->text().toStdString())[0]);
}

