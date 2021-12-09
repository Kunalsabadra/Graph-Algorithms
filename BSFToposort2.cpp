#include<bits/stdc++.h> 
using namespace std;


class Solution{     
     public:
     vector<int> topoSort(int N, vector<int> adj[]){  //int N no of Nodes
         queue<int> q;
         vector<int> indegree(N, 0);    //indegree array of size N initialised whole array with zero
   for(int i=0;i<N;i++){
       for(auto it: adj[i]){
           indegree[it]++;
       }
   }

   for(int i=0; i<N;i++){
      if(indegree[i] == 0){
          q.push(i);
      } 
   }

   vector<int> topo;
   while(!q.empty()){
       int node = q.front();
       q.pop();
       topo.push_back(node);
       for(auto it: adj[node]){
           indegree[it]--;
       if(indegree[it] == 0){
           q.push(it);
       }
       }
   }
   return topo;
     }
};