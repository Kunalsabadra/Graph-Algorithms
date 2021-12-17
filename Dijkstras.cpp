#include<bits/stdc++.h>
using namespace std;

int main(){

int n,m , source;
cin>>n>>m;
vector<pair<int, int>> adj[n+1];
int a, b, wt;
for(int i=0; i<m; i++){
  cin>>a>>b>>wt;
  adj[a].push_back({b,wt});
  adj[b].push_back({a,wt});

}
cin>>source;

priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int,int>>> pq;
vector<int> distto(n+1,INT_MAX);

distto[source] =0;
pq.push({0, source});

while(!pq.empty()){

  int dist = pq.top().first;
  int prev = pq.top().second;
  pq.pop();

     for(auto it: adj[prev]){ 
    int next = it.first;
    int nextDist = it.second;
    if(distto[next] > distto[prev] + nextDist){
      distto[next]  = distto[prev] + nextDist;
      pq.push({distto[next], next});
    }
  }

}
cout<<"The distances from source "<<source<<" are: "<<endl;
for(int i =1; i<n; i++) cout<< distto[i]<<" ";

  
  return 0;

}