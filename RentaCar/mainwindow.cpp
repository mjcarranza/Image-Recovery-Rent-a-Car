#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

  //  QPushButton *train_button = new QPushButton(this);
   // train_button->setText(tr("something"));
   // train_button->move(0, 0);
  //  setCentralWidget(train_button);

    int DIAMETER = 50;

    int PosX = 0;
    int PosY = 0;
    int PosX2 = 250;
    int PosY2 = 100;
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(PosX , PosY, DIAMETER, DIAMETER);
   // circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    circle->setBrush(Qt::green);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem("A",circle);
    QFont f;
    f.setPointSize(25);
    text->setFont(f);
    text->setPos(15,0);

    cout<<circle->x();

    circle->scenePos();



    QGraphicsLineItem *path;
    path = new QGraphicsLineItem;
    path->setLine (PosX+25, PosY+25,PosX2, PosY2);
    ui->Lienso->setScene(scene);

    QGraphicsSimpleTextItem *peso = new QGraphicsSimpleTextItem("30");
    QFont fv;
    fv.setPointSize(15);
    peso->setFont(fv);
    peso->setPos((PosX+25+PosX2)/2,(PosY+25+PosY2)/2);

    scene->addItem(path);

    scene->addItem(circle);

    scene->addItem(peso);








}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createGrafic(){
    int PosX;
    int PosY;
    int DIAMETER = 50;
    int n = 500;
    QString x;
    QChar y;
  //  QGraphicsEllipseItem *circle;
    QGraphicsSimpleTextItem *text;
    for(int i = 0; i< (*Grafo).nodes.size(); i++){
        PosX = (rand() % ( n ));
        PosY = (rand() % ( n ));
        this->nodesG.push_back(new QGraphicsEllipseItem(PosX , PosY, DIAMETER, DIAMETER));
        nodesG[i]->setBrush(Qt::green);

        x="";
        y=(*Grafo).nodes[i];
        x+=y;


        text = new QGraphicsSimpleTextItem(x,nodesG[i]);
        QFont f;
        f.setPointSize(25);
        text->setFont(f);
        text->setPos(15,0);


        scene->addItem(nodesG[i]);

    }



}



void MainWindow::CreateGraph(int n){
//Grafo = new graph(n);



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
   // CreateGraph(6);

   // BestPath('a','f');
   // paint();

    createGrafic();
}


