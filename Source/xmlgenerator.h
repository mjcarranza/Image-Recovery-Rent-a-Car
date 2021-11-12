#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H
#include "tinyxml.h"

/**
 * @brief Class for generating XML with the data of the populations
 * 
 */
class xmlGenerator
{
public:
    xmlGenerator(){
        TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","","");
        currPopulation.LinkEndChild(decl);
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
    TiXmlDocument currPopulation;
};

#endif // XMLGENERATOR_H
