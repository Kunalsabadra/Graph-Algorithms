#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=a, i<b, i++)

int main(){
    //n->no of nodes //m->no of edges
int n , m;
cin>>n>>m;

//Declare the adjacent matrix
int adj[n+1][n+1];

//take edges as input
for(int i=0; i<n;i++){
    int u , v;
    cin>>u>>v;
    adj[u][v] = 1;
    adj[v][u] = 1;
}
cout<<"Adjency representation of graph is : "<<endl;



    return 0;
}
