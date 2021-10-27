#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    int sizeX = 675;
//    int sizeY = 450;
//    QImage image = QImage("/home/user/Escritorio/descarga.jpg");

//    for (int i=0; i<sizeX; i++) {
//        for (int j=0; j<sizeY; j++) {
//            if (i>=10 && i<=100 && j>=10 && j<=100){
//                image.setPixel(i, j, qRgb(255,255,255));
//            }
//        }
//    }

//    QGraphicsScene *scene = new QGraphicsScene(this);
//    scene->addPixmap(QPixmap::fromImage(image));
//    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Open_triggered()
{
    QString fileName;
    // path to the file
    fileName = QFileDialog::getOpenFileName(this,"Open File","","Text File(*.jpg)");

    QImage image = QImage(fileName);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);
}

