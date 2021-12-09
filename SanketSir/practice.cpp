#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
   
   public:
   int v;
   list<int> *arr;

  //Constructor
   Graph(int v){
    //    this->v =v;
    v=v;
    arr = new list<int>[v];
   }

   void add_edge(int u, int v, bool bidirec = true){
       arr[v].push_back(u);
       if(bidirec){
       arr[u].push_back(v);
       }
   }
   void display(){
       for(int i=0; i<v; i++){
           cout<<"["<<i<<"]"<<"->";
           for(auto &neighbour : arr[i]){
             cout<<neighbour<<"->";
           }
           cout<<endl;
       }
   }
};

int main(){

    int v;
    cin>>v;
    Graph g(v);
    int  e;
    cin>>e;
    while(e--){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v);
    }
    g.display();
    
    return 0;
}