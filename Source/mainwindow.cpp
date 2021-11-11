#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "Genetic.h"
Genetic *gen;

/**
 * @brief MainWindow::MainWindow ui constructor
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**
 * @brief MainWindow::~MainWindow Destructor of the ui
 */
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::cut cut the loaded image
 * @param x x position indicates where to start cutting in x axes
 * @param y y position indicates where to start cutting in y axes
 * @param w width of the cutting rectangle
 * @param h heigh of the cuuting rectangle
 */
void MainWindow::cut(int x, int y, int w, int h)
{
    int row = 0;
    int col = 0;
    // recortar recuadro
    for (int i=0; i<sizeY; i++) {
        for (int j=0; j<sizeX; j++) {
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

void MainWindow::showSolution(int i, int j, int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
    xPos = i;
    yPos =j;
    cout<<xPos<<","<<yPos<<endl;
    QColor clrCurr( image.pixel( 10, 10 ) );
    cout << clrCurr.red();
    image.setPixel(10, 10, qRgb(45,164,200));
}

void MainWindow::endProcess()
{
    QMessageBox* msg;
    msg = new QMessageBox();
    msg->setWindowTitle("INFORMATION");
    msg->setIcon(QMessageBox::Warning);
    msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");
    msg->setText("Process Finished!");
    msg->show();

}
/**
 * @brief MainWindow::on_Open_triggered open an image
 */
void MainWindow::on_Open_triggered()
{
    // gets the path to the file
    fileName = QFileDialog::getOpenFileName(this,"Open File","","Text File(*.jpg)");

    // creates a new image
    image = QImage(fileName);

    // create a new scene to show the loaded image
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);
}

/**
 * @brief MainWindow::on_Cut_triggered cuts the selected section
 */
void MainWindow::on_Cut_triggered()
{
    // message in case a cutting parameter is empty
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

    // show message if value is invalid
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
        xPos = stoi(xstr);
        yPos = stoi(ystr);
        int w = stoi(wstr);
        width = w;
        int h = stoi(hstr);
        heigh = h;

        // save width and heigh cutting values
        width = w;
        heigh = h;

        if (w>500){
            msg->setText("The maximun value for width is 500!");
            msg->show();
        }
        else if (h>500){
            msg->setText("The maximun value for height is 500!");
            msg->show();
        }
        else{
            // erase the inserted values
            ui->xlineEdit->setText("");
            ui->ylineEdit->setText("");
            ui->wlineEdit->setText("");
            ui->hlineEdit->setText("");

            // send data to main window
            cut(xPos,yPos,w,h);
        }
    }
}

/**
 * @brief MainWindow::on_Recover_triggered recover the deleted image
 */
void MainWindow::on_Recover_triggered()
{
    // generate population
    cout<<xPos<<","<<yPos<<endl;
    gen = new Genetic(width, heigh, xPos, yPos);

    // call genetic class
    for (int i=0; i<width; i++){
        for (int j=0; j<heigh; j++){
            gen->fillIdeal(i,j,pixArray[i][j].red(),pixArray[i][j].green(), pixArray[i][j].blue());
        }
    }

    gen->GeneratePopulation(width, heigh);
}



void MainWindow::on_Keep_Recovering_triggered()
{
    cout<<"activado111";
    gen->Fitness();
}


//void MainWindow::on_Current_Solution_triggered()
//{
//    cout<<"activado";
//    QColor clrCurr( image.pixel( 0, 0 ) );
//    cout<<clrCurr.red();
//    //gen->finalResult();
//}


void MainWindow::on_Show_Current_Solution_triggered()
{
    int row = 0;
    int col = 0;
    for (int i=0; i<sizeY; i++) {
        for (int j=0; j<sizeX; j++) {
            if ((i>=xPos) && (i<xPos+width) && (j>=yPos) && (j<yPos+heigh)){
                // set color to pixel
                int redVal = gen->finalResult(row,col,1,0,0);
                int greenVal = gen->finalResult(row,col,0,1,0);
                int blueVal = gen->finalResult(row,col,0,0,1);
                image.setPixel(i, j, qRgb(redVal,greenVal,blueVal));
                col ++;
            }
            if ((i>=xPos) && (i<xPos+width) && (j==yPos+heigh)){
                row ++;
            }
        }
        col = 0;
    }
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);
}

