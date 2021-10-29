#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

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

void MainWindow::cut(int x, int y, int w, int h)
{
    int row = 0;
    int col = 0;
    // recortar recuadro
    for (int i=0; i<sizeX; i++) {
        for (int j=0; j<sizeY; j++) {
            if ((i>=x) && (i<x+w) && (j>=y) && (j<y+h)){

                // get erased pixel colors (rgb)
                QColor clrCurrent( image.pixel( i, j ) );
                pixArray[row][col] = clrCurrent;
                cout<<"("<<pixArray[row][col].red()<<", "<<pixArray[row][col].green()<<", "<<pixArray[row][col].blue()<<")"<<endl;

                // set white color to pixel
                image.setPixel(i, j, qRgb(255,255,255));
                col ++;
            }
            if ((i>=x) && (i<x+w) && (j==y+h)){
                row ++;
            }
        }
        col = 0;
    }
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_Open_triggered()
{
    // path to the file
    fileName = QFileDialog::getOpenFileName(this,"Open File","","Text File(*.jpg)");

    image = QImage(fileName);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_Cut_triggered()
{
     QMessageBox* msg;

    // get text from each line edit
    QString xline = ui->xlineEdit->text();
    QString yline = ui->ylineEdit->text();
    QString wline = ui->wlineEdit->text();
    QString hline = ui->hlineEdit->text();

    // convert text to string data type
    string xstr = xline.toStdString();
    string ystr = yline.toStdString();
    string wstr = wline.toStdString();
    string hstr = hline.toStdString();

    // creating a QMessageBox for warning
    msg = new QMessageBox();
    msg->setWindowTitle("WARNING");
    msg->setIcon(QMessageBox::Warning);
    msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");

    if(xstr==""){
        msg->setText("X Cutting Value Required!");
        msg->show();
    }
    else if(ystr==""){
        msg->setText("Y Cutting Value Required!");
        msg->show();
    }
    else if(wstr==""){
        msg->setText("Width Cutting Value Required!");
        msg->show();
    }
    else if(hstr==""){
        msg->setText("High Cutting Value Required!");
        msg->show();
    }
    else{
        // convert to integer data type
        int x = stoi(xstr);
        int y = stoi(ystr);
        int w = stoi(wstr);
        int h = stoi(hstr);

        ui->xlineEdit->setText("");
        ui->ylineEdit->setText("");
        ui->wlineEdit->setText("");
        ui->hlineEdit->setText("");

        // send data to main window
        cut(x,y,w,h);
    }
}


void MainWindow::on_Show_previous_solutions_triggered()
{
    // call genetic class
    int a =9; int b =8;
    int c = a+b;
    cout<<c<<endl;
    cout<<"this is excecuting"<<endl;
    cout<<"("<<pixArray[0][0].red()<<", "<<pixArray[0][0].green()<<", "<<pixArray[0][0].blue()<<")"<<endl;
}


void MainWindow::on_Recover_triggered()
{

}

