#ifndef GENETIC_H
#define GENETIC_H

#include <iostream>
#include <QColor>
using namespace std;

/**
 * @brief The Genetic class is for the genetic algorithm
 */
class Genetic
{
public:
    int width = 0;
    int heigh = 0;

    Genetic();

    // sabiendo que el array no va a crecer mas alla de los valores de w y h, usar esas dimensiones en los bucles
    QColor arr[500][500];

    void GeneratePopulation(int w, int h);
    void Fitness(int w, int h);
    void Select(int w, int h);
    void Cross(int w, int h);
    void mutate(int w, int h);
    void Ivert(int w, int h);
    int randomNumber();

};

#endif // GENETIC_H
