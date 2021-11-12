#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H
#include "tinyxml.h"

class xmlGenerator
{
public:
    xmlGenerator(){
        TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","","");
        currPopulation.LinkEndChild(decl);
    }
    void newIndividual(int r, int g, int b);
    void pushPopulation();

private:
    int pop_number;
    TiXmlDocument currPopulation;
};

#endif // XMLGENERATOR_H
