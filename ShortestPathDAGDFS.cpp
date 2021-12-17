#include<bits/stdc++.h>
using namespace std;


void  toposort(int node , vector<pair<int, int>>adj[], stack<int> st, int vis[]){

    vis[node] =1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            toposort(it.first , adj,st,vis );
        }
    }
st.push(node);

}

void shortestpath(int src, vector<pair<int ,int> >adj[],int N) {
     int vis[N] ={0};
     stack<int> st;
     for(int i=0; i<N;i++){
         if(!vis[i])
         toposort(i, adj,st,vis);
     }
      int dis[N];
      for(int i=0; i<N;i++){
          dis[i] = INT_MAX;
      }
      dis[src] =0;
     while(!st.empty()){
     int node = st.top();
     st.pop();           

//If node is visited already
     if(dis[node] != INT_MAX){
         for(auto it: adj[node]){
             if(dis[node] + it.second < dis[it.first]){
                 dis[it.first] = dis[node] + it.second;
             }
         }
     }
     }
     for(int i=0; i<N; i++){
         (dis[i] = INT_MIN)? cout<<"Infinity": cout << dis[i]<<" ";
     }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int , int>> adj[n];
    for(int i=0; i<m;i++){
        int u, v , wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    shortestpath(0,adj, n); 
    
    return 0;
}
