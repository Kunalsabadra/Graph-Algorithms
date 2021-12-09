#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int const N = 1e5+2;
vector<int> graph[N];

void display(){
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<n; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
       
    }  
}

void dfs(){
    int src;
    cin>>src;
    vis[src] = 1;
    
}
int main(){
    
  display();
    
    return 0;
}
