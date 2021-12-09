 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int>graph[N];

void display(){
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
//TC: O(N)
 void bfs(){
     int src;
     cin>>src;
     bool vis[N];
     queue<int> q;
     q.push(src);
     vis[src] = true;
     while(!q.empty()){
         int node = q.front();
         q.pop();
         cout<<node<<" ";
         for(auto it: graph[node]){
             if(!vis[it]){
                 vis[it] = true;
                 q.push(it);
             }
         }
     }
 }


int main(){

  display(); 
 bfs();

    
    
    return 0;
}
