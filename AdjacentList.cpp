#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    //n-> no of nodes , m->no of edges
    // int n, m;
    // cin>>n>>m;
    // vector<int> adj[n+1]; //it is 1 based graph index so n+1
    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin>>u>>v;

    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
//--------------------------------------------------------------
//If wighted graph
   int n ,m ;
   cin>>n>>m;
  vector<pair<int , int> > adj[n+1];
    for(int i=0; i<m; i++){
        int u,v, wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v , wt});
        adj[v].push_back({u,wt});
        
    }    
    return 0;
}