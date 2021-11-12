#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H


class xmlGenerator
{
public:
    xmlGenerator();
    void newIndividual(int r, int g, int b);
    void pushPopulation();

private:
    int ind_number;
    int pop_number;
};

#endif // XMLGENERATOR_H
