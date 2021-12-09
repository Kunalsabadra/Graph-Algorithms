#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];            //vector of adjacent elements to be stored
int vis[100005];                    //array of visited

 
void dfs(int node){
  
  vis[node] = 1;          //If node gets visited
cout<<node<<" ";
  //Traverse for all adjacent nodes and go in depth for search
  //using iterator
  for(auto it: adj[node]){
      if(vis[it] == 0){         
//If node is not visited then visit it and store in dfs 
dfs(it);
}
  }
  }
  void dfsSolve(){
      //n-> no of nodes , m->no of edges
      int n , m;
      cin>>n>>m;
      for(int i=0; i<=n; i++){
          int u , v;
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      for(int  i=0; i<=n; i++){
        if(vis[i] == 0){ 
         dfs(i);
        }
      }
  }


int main(){
     
     dfsSolve();
    dfs(1);
   

    
    return 0;
}