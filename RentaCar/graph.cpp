#include "graph.h"

graph::graph()
{


}
graph::graph(int n){
    createNodes(n);
    createEdges(n);
    generateMatriz(n);


}

void graph::createNodes(int n){
    char node = 'a';


  //  this->nodes.push_back();
    for(int i = 0; i<n ; i++){
        nodes.push_back(node+i);

    }

//        srand (time(NULL));
//    random = rand() % ( n );


}

void graph::createEdges(int n){
    char node = 'a';
    for(int i = 0; i<(3*n+3) ; i++){


        srand (time(NULL));
        edges.push_back(edge (node+(rand() % ( n )),  node+(rand() % ( n ))  ,rand() % ( 3*n )+1)  );

    }

}

void graph::generateMatriz(int n){

    this->Matriz  = vector<vector<int>>( n , vector<int> (n, 0));

    int source;
    int target;
    for(int i = 0; i<this->edges.size() ; i++){
        source = getposNode(edges[i].SnodeName);
        target = getposNode(edges[i].TnodeName);
        Matriz[source][target] = edges[i].value;




     }


}

vector<int> graph::getRelationof(char node){
    int pos = getposNode(node);
    return Matriz[pos];
}

int graph::getposNode(char node){
    for(int i = 0; i<this->nodes.size() ; i++){
        if(nodes[i]==node){
            return i;
        }
    }
    return -1;

}



