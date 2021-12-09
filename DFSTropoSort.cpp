#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5+2;
// vector<int> adj[N];

//TC: O(N +E)
//SC: O(N) + O(N)

//Topological sort using DFS
void findSort(int node , vector<int> &vis, stack<int> &st , vector<int> adj[]){
    vis[node] = 1;  //vsisted node marked as 1

    for(auto it : adj[node]){            //loop for traversing all adjacent nodes in graph
        if(!vis[it]){
            findSort(it , vis , st , adj);
        }
    }
    st.push(node);
}


vector<int>toposort(int N, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(N, 0);
    for(int i=0;i<N;i++){
 
        //check if node is visited previously
        if(vis[i] == 0){
            findSort(i, vis, st , adj);
        }
    }
    //vector for pushing entire stack elements in vector ans
    vector<int> Topo;
    while(!st.empty()){
        Topo.push_back(st.top());
        st.pop();
    }
    return Topo;
}

int main(){

    int N,M;
    cin>>N>>M; 
    vector<int> adj[N];
    for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<int> sort;
    // sort = toposort(N, adj);
    // for(auto i=sort.begin(); i!= sort.end();i++){
    //     cout<<" "<<*i;
    // }
    findSort();

    return 0;
} 