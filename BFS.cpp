#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
bool vis[N] ;
vector<int> adj[N];



int main(){

//Input of Graph
    for(int i=0; i<N; i++)
        vis[i] =0;

        int n,m;
        cin>>n>>m;

        int u,v;
        for(int i=0; i<n; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
 }
 //BFS Implementation
 
 int src;
 cin>>src ;
 queue<int> q;
 q.push(src);
 vis[src] = true;
 while(!q.empty()){
     int node = q.front();
     q.pop();
     cout<<node<<" ";
 
    vector<int> ::iterator it;
    for(it = adj[node].begin(); it != adj[node].end();it++){
        if(!vis[*it]){
            vis[*it] =true;
          q.push(*it);  
        }
    }
 }
    return 0;
}