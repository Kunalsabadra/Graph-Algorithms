#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
bool vis[N];
vector<int> graph[N];

void dfs(int node){

    vis[node] = 1;
    cout<< node<< " ";

    for(auto it: graph[node]){
      if(vis[it]);
      else dfs(it);  
    }
}

int main(){
int n,m;
cin >>n>>m;

    for(int i=0; i<n; i++)
    vis[i] == false;
    int u,v;
for(int i=0; i<m; i++){
    cin >>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u); 
}
int n;
cin>>n;
dfs(n);
    return 0;
}
