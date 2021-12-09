#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
          //unordered _map pair of (vertex , linked list)
        unordered_map<T , list<T> > adj;
        Graph(){

        }
        void add_edge(T n1 , T n2, bool bidirec = true){
          adj[n1].push_back(n2);
          if(bidirec){
              adj[n2].push_back(n1);
          }
        }
        void print() {
            for(auto row: this->adj){
                cout<<row.first<<"-->";
                for(auto el : row.second){
                    cout<<el<<", ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph<int> g1;
    Graph<string> g2;
    g1.add_edge(1,2);
    g1.add_edge(3,2);
    g1.add_edge(4,2);
    g1.add_edge(1,4);
    g1.add_edge(1,3);
    g1.print();
    g2.add_edge("delhi" , "tn");
    g2.add_edge("delhi" , "blr");
    g2.add_edge("delhi" , "mb");
    g2.add_edge("mb" , "blr");
    g2.add_edge("kol" , "delhi");
    g2.add_edge("guj" , "kol");
    g2.print();
    

    return 0;
}