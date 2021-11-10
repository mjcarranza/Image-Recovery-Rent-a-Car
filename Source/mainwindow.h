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
    QString fileName;
    QImage image;
    QColor pixArray[500][500];

    void cut(int x,int y, int w, int h);
    QColor getpixel(int i,int j);

// private slots
private slots:
    void on_Open_triggered();
    void on_Cut_triggered();
    void on_Recover_triggered();
    void on_Show_previous_solutions_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
