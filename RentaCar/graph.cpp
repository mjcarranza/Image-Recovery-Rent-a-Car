#include "graph.h"

graph::graph()
{}
graph::graph(int n){
    createNodes(n);
    createEdgesAndMatriz(n);



}

void graph::createNodes(int n){
    char node = 'a';

    for(int i = 0; i<n ; i++){
        nodes.push_back(node+i);
    }

    for(int k = 0; k<this->nodes.size() ; k++){
       cout<<this->nodes[k]<<"  ";
    } cout<<endl;
}

void graph::createEdgesAndMatriz(int n){


    this->Matriz  = vector<vector<int>>( n , vector<int> (n, 0));
    char node = 'a';
    int r1;
    int r2;
    int v;
    srand (time(NULL));
    for(int i = 0; i<(3*n+3) ; i++){

        r1 = (rand() % ( n ));
        r2 = (rand() % ( n ));
        v = (rand()%(9)) +1 ;
        if(relationNotExist( r1,  r2 )){
            cout<<r1;
            cout<<r2;
            cout<<v;
            cout<<endl;
            Matriz[r1][r2] = v;
            Matriz[r2][r1] = v;
            edges.push_back(edge (node+r1,  node+r2  , v));

        }
    }

    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n; j++){
            cout<<Matriz[i][j];
        }
        cout<<endl;
    }




}



bool graph::relationNotExist(int i, int j ){
    if(Matriz[i][j]>0){
        return false;
    }return true;

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
char graph::getnodePos(int pos){
    for(int i = 0; i<this->nodes.size() ; i++){
        if(i==pos){
            return nodes[i];
        }
    }
    return '?';

}


