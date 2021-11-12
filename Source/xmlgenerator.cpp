#include "xmlgenerator.h"
#include <string>

using namespace std;
void xmlGenerator::newIndividual(int r, int g, int b){
    TiXmlElement * element = new TiXmlElement("Individual");
    string individual = "r: "+to_string(r)+","+"g: "+to_string(g)+",""b "+to_string(b);
    TiXmlText * text = new TiXmlText(individual.c_str());
    element->LinkEndChild(text);
    currPopulation.RootElement()->LinkEndChild(element);
}
void xmlGenerator::pushPopulation(){
    string directory = "generations/population"+to_string(pop_number)+".xml";
    currPopulation.SaveFile(directory.c_str());
    currPopulation.RootElement()->Clear();
    pop_number++;
}
    

