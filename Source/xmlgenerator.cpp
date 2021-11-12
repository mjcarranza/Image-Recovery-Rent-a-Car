//
// Created by abner on 12/11/21.
//

#include "xmlgenerator.h"
#include <string>

using namespace std;
void xmlgenerator::newIndividual(int r, int g, int b){

    TiXmlElement* element = new TiXmlElement("Individual");
    population_root->LinkEndChild(element);

    string individual = "r: "+to_string(r)+","+"g: "+to_string(g)+",""b "+to_string(b);
    TiXmlText* text = new TiXmlText(individual.c_str());
    element->LinkEndChild(text);

}
void xmlgenerator::pushPopulation(){
    string directory = "bal.xml";
    //string directory = "population"+to_string(pop_number)+".xml";
    currPopulation.SaveFile(directory.c_str());
    population_root->Clear();
    pop_number++;
}
