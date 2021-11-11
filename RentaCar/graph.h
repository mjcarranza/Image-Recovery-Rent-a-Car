#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <node.h>
#include <edge.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
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
    void createEdges( int);
    void generateMatriz( int);
    vector<int> getRelationof(char);
    int getposNode(char );


};

#endif // GRAPH_H
