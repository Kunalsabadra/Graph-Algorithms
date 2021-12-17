#include<bits/stdc++.h>
using namespace std;


bool checkCycle(int node, vector<int>adj[], int vis[], int dfsvis[]){

    vis[node] =1;
    dfsvis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle(it , adj, vis, dfsvis)) return true;
        }
        else if(dfsvis[it]){ 
        return true;
        }
    }
    dfsvis[node] =0;
    return false;
    }

bool isCycle(int N, vector<int>adj[]){
   int vis[N];
   int dfsvis[N];
   memset(vis , 0, sizeof vis);
   memset(dfsvis , 0, sizeof dfsvis);

   for(int i=0; i<N; i++){
       if(!vis[i]){
           if(checkCycle(i , adj , vis, dfsvis)) return true;
       }
   }
   return false;
}


int main(){


    int N,m;
    cin>>N>>m;
    vector<int> adj[N];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(N, adj)){
        cout<<"Cycle Present";
    }
    else{
        cout<<"Cycle not Present";
    }
    
    return 0;
}