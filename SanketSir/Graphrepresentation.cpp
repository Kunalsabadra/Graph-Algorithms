#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Adjacency list

class Graph{

public:
int v;              //v->no of vertices
list<int> *arr;     //array of list

//Constructor
Graph(int v){
    this->v = v;
    arr = new list<int>[v];

}
void add_edge(int u, int v, bool bidirec = true){
    this->arr[u].push_back(v);
    if(bidirec){
        this->arr[v].push_back(u);
    }
}

void display(){
    for(int i=0; i < this->v; i++){
        cout<<"["<<i<<"]"<<"->";
        for(auto &neighbour : this->arr[i]){
            cout<<neighbour<<"->";
        }
        cout<<"\n";
   }
}
};
int main(){
    
    
    int v;
    cin>>v;
    Graph g(v);
    int e;
    cin>>e;
    while(e--){
        int u, v;
        cin>>u>>v;
        g.add_edge(u,v);
    }
    g.display();
    
    return 0;
}