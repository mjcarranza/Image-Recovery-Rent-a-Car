#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class main class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
// public variables and methos
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int sizeX = 675;
    int sizeY = 450;
    int width;
    int heigh;
    int xPos = 0;
    int yPos = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    int stopgen;
    QString fileName;
    QImage image;
    QImage imageSol;
    QColor pixArray[500][500];

    void cut(int x,int y, int w, int h);
    void showSolution(int i, int j, int r, int g, int b);
    void endProcess();
    QImage getImage();

// private slots
private slots:
    void on_Open_triggered();
    void on_Cut_triggered();
    void on_Recover_triggered();
    void on_Keep_Recovering_triggered();
    void on_Show_Current_Solution_triggered();
    void on_Show_Previous_Solutions_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
