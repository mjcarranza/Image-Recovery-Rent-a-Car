#include "Genetic.h"
/**
 * @brief Genetic::Genetic Genetic algorithm constructor
 */
Genetic::Genetic(){}

/**
 * @brief Genetic::GeneratePopulation function to create a generation
 * @param w X dimention of the needed population
 * @param h Y dimention of the needed population
 */
void Genetic::GeneratePopulation(int w, int h)
{
    int random = randomNumber();
}
/**
 * @brief Genetic::Fitness function to calculate how good is a population
 */
void Genetic::Fitness(int w, int h)
{

}
/**
 * @brief Genetic::Select function to select the best individuals of the population
 */
void Genetic::Select(int w, int h)
{

}
/**
 * @brief Genetic::Cross function to cross the selected individuals
 */
void Genetic::Cross(int w, int h)
{

}
/**
 * @brief Genetic::mutate function to randomly mutate the crossed individuals
 */
void Genetic::mutate(int w, int h)
{

}
/**
 * @brief Genetic::Ivert function to randomly invert the genetic code of the idividuals
 */
void Genetic::Ivert(int w, int h)
{

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
   return 1 + rand() % (( 5 + 1 ) - 1);
}
