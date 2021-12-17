#include<bits/stdc++.h>
using namespace std;

bool isCycle(int N, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(N,0);
    for(int i=0; i<N;i++){
        for(auto it:adj[i]){
          indegree[it]++;
        }
    }

    for(int i=0; i<N;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
         int node = q.front();
         q.pop();
         count++;
         for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                 q.push(it);
            }
         }
    }
if (count == N)return false;
return true;
}


int main(){
    
  int V, E;
  cin>>V>>E;
  vector<int> adj[V];
  for(int i=0; i<E;i++){
      int u, v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  if(isCycle(V, adj)){
      cout<<"Cycle present";
  }
  else{
      cout<<"Cycle not present";
  }

    return 0;
}