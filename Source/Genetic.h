#ifndef GENETIC_H
#define GENETIC_H

#include <iostream>
#include <QColor>
#include <cmath>
using namespace std;

/**
 * @brief The Genetic class is for the genetic algorithm
 */
class Genetic
{
public:
    int width = 0;
    int heigh = 0;
    QColor first, second, newCross, newMut, newInv;
    QColor colorArray[300][300];
    QColor ideal[300][300];
    int fitness[300][300];
    int selecArray[300][300];
    int sumaColor = 0;
    int sumaIdeal = 0;
    int pop = 0;
    int cruce = 0;
    int mut = 0;
    int inv = 0;
    int contSelect = 0;
    bool stop = false;

    Genetic(int w, int h){
        this->width = w;
        this->heigh = h;
    }
    void GeneratePopulation(int w, int h);
    void Fitness();
    void Select();
    void Cross();
    void mutate();
    void invert();
    int randomNumber();
    void fillIdeal(int row, int col, QColor color);
    void stopRunning();
    void keepRunnig();

};

#endif // GENETIC_H
