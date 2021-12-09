#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//vector of list globally
vector<list<int> > graph;

void display(){
    for(int i =0 ; i<graph.size();i++){
        cout<<"["<<i<<"]"<<"->";
    for(auto &el : graph[i]){
        cout<<el<<"->";
    }
    cout<<endl;    
    }
}

int main(){

    int v;
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    display();
    
    return 0;
}