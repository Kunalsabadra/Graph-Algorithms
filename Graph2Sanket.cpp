#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int , int> > > graph;

void addEdge(int u, int v, bool bidir = true , int wt =0){
    graph[u].push_back({v, wt});
    if(bidir){
        graph[v].push_back(make_pair(u, wt));
    }
}

void display(){
    for(auto i: graph){
    //i->vector of pair
    if(i.size() == 0){
        cout<<"empty";
    }
        for(auto j : i){
            //j is a pair
          cout<<"{"<<j.first<<","<<j.second<<"} ";
        }
        cout<<endl;
    }
}
void bfs(int src , int vertices){
    queue<int> q;
    vector<bool> visited(vertices, false);

    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(auto neighbour : graph[node]){
            if(!visited[neighbour.first]){
                q.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
}

int main(){

    int vertices , edges;
    //Input of no of nodes and edges
    cin>>vertices>>edges;

    graph.resize(vertices);
    while(edges--){
        int u,v, wt;
        cin>>u>>v>>wt;
        addEdge(u , v, true , wt);
    }
    // display();
    bfs(1, 7);

    return 0;
}