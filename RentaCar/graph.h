#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <node.h>
#include <edge.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
using namespace std;
class graph
{
public:
    graph();
    graph(int);
    vector<vector<int>> Matriz;
    vector<edge> edges;
    vector<char> nodes;

    void createNodes(int);
    void createEdgesAndMatriz(int);
    vector<int> getRelationof(char);
    int getposNode(char );
    char getnodePos(int);
    bool relationNotExist(int, int );


};

#endif // GRAPH_H
