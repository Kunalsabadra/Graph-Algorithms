#include<bits/stdc++.h>
using namespace std;


void ShortPathBFS(int src, vector<int> adj[],int N ){

  int dis[N];
  for(int i=0; i<N;i++){
      dis[i] = INT_MAX;
  }
  queue<int>q;
  dis[src] = 0;
  q.push(src);
  while(!q.empty()){
      int node = q.front();
      q.pop();
      for(auto it: adj[node]){
          if(dis[node]+1 < dis[it]){
              dis[it] = dis[node]+1;
              q.push(it);
          }
      }
  }
  for(int i=0; i<N;i++){
      cout<<dis[i]<<" ";
  } 

}

int main(){
 int V, E;
 cin>>V>>E;
 vector<int>adj[V];
 for(int i=0; i<E; i++){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 ShortPathBFS(0,adj,V);

    
    return 0;
}