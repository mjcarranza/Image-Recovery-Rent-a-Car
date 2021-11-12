//
// Created by abner on 12/11/21.
//
#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H
#include "tinyxml.h"

/**
 * @brief Class for generating XML with the data of the populations
 *
 */
class xmlgenerator
{
public:
    xmlgenerator(){
        TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","UTF-8","");
        currPopulation.LinkEndChild(decl);

        TiXmlElement* population = new TiXmlElement("Population");
        currPopulation.LinkEndChild(population);

        population_root = population;
    }
    /**
     * @brief adds an individual to the population element in the xml document
     *
     * @param r red value
     * @param g green value
     * @param b blue value
     */
    void newIndividual(int r, int g, int b);

    /**
     * @brief loads the xml document into an xml file with the population number
     *
     */
    void pushPopulation();

private:
    int pop_number;
    TiXmlElement* population_root;
    TiXmlDocument currPopulation;
};

#endif // XMLGENERATOR_H
