#ifndef GENETIC_H
#define GENETIC_H

#include <iostream>
#include <QColor>
#include <cmath>
#include "xmlgenerator.h"
#include <QWidget>

using namespace std;

/**
 * @brief The Genetic class is for the genetic algorithm
 */
class Genetic
{
public:

    xmlGenerator* xml = new xmlGenerator();

    int width = 0;
    int heigh = 0;
    int xPos = 0;
    int yPos = 0;
    QColor first, second, newCross, newMut, newInv;
    QColor colorArray[300][300];
    QColor ideal[300][300];
    QImage img;
    int fitness[300][300];
    int selecArray[300][300];
    int sumaColor = 0;
    int sumaIdeal = 0;
    int pop = 0;
    int cruce = 0;
    int mut = 0;
    int inv = 0;
    int contSelect = 0;
    int stop;
    // Constructor
    Genetic(int w, int h, int x, int y, int stp){
        this->width = w;
        this->heigh = h;
        this->xPos = x;
        this->yPos = y;
        this->stop = stp;
    }
    // Methods
    void GeneratePopulation(int w, int h);
    void Fitness();
    void Select();
    void Cross();
    void mutate();
    void invert();
    int randomNumber();
    void fillIdeal(int i, int j, int r, int g, int b);
    void keepRunnig();
    int finalResult(int i, int j, int r, int g, int b);
    void setStopGen(int stp);

};

#endif // GENETIC_H
