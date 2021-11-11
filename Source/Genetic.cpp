#include "Genetic.h"
#include "mainwindow.h"

/**
 * @brief Genetic::GeneratePopulation function to create a generation
 * @param w X dimention of the needed population
 * @param h Y dimention of the needed population
 */
void Genetic::GeneratePopulation(int w, int h)
{
    pop =1;
    cruce =0;
    mut =0;
    inv =0;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            int rand1 = randomNumber();
            int rand2 = randomNumber();
            int rand3 = randomNumber();
            colorArray[i][j]= QColor(rand1,rand2,rand3);
            cout<<"suma de colores "<<rand1+rand2+rand3<<endl;
        }
    }
    Fitness();
}
/**
 * @brief Genetic::Fitness function to calculate how good is a population
 */
void Genetic::Fitness()
{
    MainWindow mainw;
    stop = 1000;
    while (stop > 0) {
        stop--;
        // mostrar o guardar la poblacion actual y generar el XML
        cout<< "ALGORITHM RUNNING!!!!"<< endl;
        for (int i=0; i<width; i++){
            cout<<"calculando fitness"<< endl;
            for (int j=0; j<heigh; j++){
                sumaColor = colorArray[i][j].red() + colorArray[i][j].green() + colorArray[i][j].blue();
                sumaIdeal = ideal[i][j].red() + ideal[i][j].green() + ideal[i][j].blue();
                fitness[i][j] = abs(sumaColor - sumaIdeal);
            }
        }
        Select();
        // Evaluate if the current population is a solution
    }
    //mostrar mensaje de que se termino
    mainw.endProcess();
}
/**
 * @brief Genetic::Select function to select the best individuals of the population
 */
void Genetic::Select()
{
    // Select two of the best individuals to cross them acoording to its fitness value
    for (int i=0; i<width; i++){
        for (int j=0; j<heigh; j++){
            if (fitness[i][j] <= 10){
                selecArray[i][j] = 1;
            }
            else{
                selecArray[i][j] = 0;
            }
        }
    }
    // look for the individuals in the population and save them
    for (int i=0; i<width; i++){
        for (int j=0; j<heigh; j++){
            if (selecArray[i][j] == 1){
                if(contSelect==0){
                    first = colorArray[i][j];
                    contSelect++;
                }
                else if(contSelect == 1){
                    second = colorArray[i][j];
                    contSelect = 0;
                    break;
                }
            }
        }
    }
    Cross();
}
/**
 * @brief Genetic::Cross function to cross the selected individuals
 */
void Genetic::Cross()
{
    mut =0;
    inv =0;
    cruce =1;
    pop =0;
    // This number selects the color combination
    int rand = randomNumber();

    if (rand == 1){
        int rojo = first.red();
        int verde = second.green();
        int azul= first.blue();
        newCross = QColor(rojo, verde, azul);
    }
    else if (rand == 2){
        int rojo = second.green();
        int verde = first.red();
        int azul= second.blue();
        newCross = QColor(rojo, verde, azul);
    }
    else if (rand == 3){
        int rojo = second.blue();
        int verde = second.red();
        int azul= first.green();
        newCross = QColor(rojo, verde, azul);
    }
    else{
        int rojo = first.green();
        int verde = first.blue();
        int azul= second.red();
        newCross = QColor(rojo, verde, azul);
    }

    mutate();
    invert();

    // After crossing, mutate and invertion, look for an individual`s fitness that is bigger than the generated
    // one and repalce the old color for the new one.
    for (int i=0; i<width; i++){
        for (int j=0; j<heigh; j++){
            // If fitness in the [i][j] possition is bigger then newInv`s fitness, we replace it
            if (fitness[i][j] > 10){
                sumaColor = newInv.red() + newInv.green() + newInv.blue(); // suma de los colores de newInv
                sumaIdeal = ideal[i][j].red() + ideal[i][j].green() + ideal[i][j].blue();
                int newInvFit = abs(sumaColor - sumaIdeal); // Fitness value for newInv

                //If newInv`s fitness is lower tan the color in the [i][j] position, change it for newInv
                if (newInvFit < fitness[i][j]){
                    colorArray[i][j] = newInv;
                }
            }
        }
    }
}
/**
 * @brief Genetic::mutate function to randomly mutate the crossed individuals
 */
void Genetic::mutate()
{
    mut =1;
    inv =0;
    cruce =0;
    pop =0;
    // con random para probabilidad
    int rand = randomNumber();
    if (rand == 10){
        newMut = QColor(randomNumber(), newCross.green(), newCross.blue()); // random between 0-255
    }
    else if (rand == 100){
        newMut = QColor(newCross.red(), randomNumber(), newCross.blue()); // random between 0-255
    }
    else if (rand == 200){
        newMut = QColor(newCross.red(), newCross.green(), randomNumber()); // random between 0-255
    }
}
/**
 * @brief Genetic::Ivert function to randomly invert the genetic code of the idividuals
 */
void Genetic::invert()
{
    mut =0;
    inv =1;
    cruce =0;
    pop =0;
    int rand = randomNumber(); // between 1-1000

    if (rand == 100){
        newInv = QColor(newMut.green(), newMut.blue(), newMut.red());
    }
    else if (rand == 800){
        newInv = QColor(newMut.green(), newMut.blue(), newMut.red());
    }
    else{
        newInv = QColor(newMut.red(), newMut.green(), newMut.blue()); // no invertion
    }
}
/**
 * @brief Game::randomNumber gets a random number from 1 to 5
 * @return returns a number
 */
int Genetic::randomNumber()
{

   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   if (pop == 1){
       return rand() % (255);
   }
   else if(cruce == 1){
       return 1 + rand() % (4);
   }
   else if(mut == 1){
       return rand() % (255);
   }
   else if(inv == 1){
       return rand() % (1000);
   }
   else{
       return 1+rand() % (2);
   }
}

void Genetic::fillIdeal(int i, int j, int r, int g, int b)
{
    ideal[i][j] = QColor(r,g,b);
    cout<< "Color ideal> ("<<ideal[i][j].red()<<", "<<ideal[i][j].green()<<", "<<ideal[i][j].blue()<<")"<<endl;
}


void Genetic::keepRunnig()
{
    stop = false;
    Fitness();
}

int Genetic::finalResult(int i, int j, int r, int g, int b)
{
    int redVal = colorArray[i][j].red();
    int greenVal = colorArray[i][j].green();
    int blueVal = colorArray[i][j].blue();
    if (r==1){
        return redVal;
    }
    else if (g==1) {
        return greenVal;
    }
    else {
        return blueVal;
    }
}
