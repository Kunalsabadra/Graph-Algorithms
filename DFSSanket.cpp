#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v ; //No of vertices
    list<int> *adj;
    Graph(int n){
        this->v = n;
        this->adj = new list<int>[this->v];
  }
  void addEdge(int u , int v , bool bidirec = true) {
     adj [u].push_back(v);
     if(bidirec){
         adj[v].push_back(u);
     } 
}
//DFS Implementation Code
void dfsHelper(int src, unordered_map<int , bool> &visited){
    visited[src] = true;
    cout<<src<<" ";                 //dfs printing statement
    for(auto neighbour: this->adj[src]){
       if (!visited[neighbour]){
           dfsHelper(neighbour, visited);
       } 
    }
}
void dfs (int src){
   unordered_map<int , bool>visited;
   dfsHelper(src, visited);
}
int ConnectedComponent(){
    unordered_map<int , bool> visited;
    int result =0;  //stores the componenets
    for(int i=0; i<v-1; i++){
        if(!visited[i]){
            //call dfs
            dfsHelper(i , visited);
            result++;
        }
    }
    return result;
}
};
int main(){

Graph g(7);              //Graph g(no of vertices)
g.addEdge(0,1);
g.addEdge(2,1);
g.addEdge(3,2) ;
g.addEdge(4,5);

// Graph g(7);
// g.addEdge(11,10);
// g.addEdge(11,6);
// g.addEdge(10,8);
// g.addEdge(10,9);
// g.addEdge(6,5);



// cout<<g.ConnectedComponent();
g.dfs(2);

    return 0;
}           