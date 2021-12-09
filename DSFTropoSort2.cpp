#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph 
{ 
    int V; 

	list<int> *adj; 


	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); 
	void addEdge(int u, int v); 

	
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V;

	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v);  
} 
 
void Graph::topologicalSortUtil(int u, bool visited[], 
								stack<int> &Stack) 
{ 
	
	visited[u] = true; 
	// list<int>::iterator i; 
	// for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	for(auto i:adj[u]){ 
		if (!visited[i]) 
			topologicalSortUtil(i, visited, Stack); 
	}
	Stack.push(u); 
} 


void Graph::topologicalSort() 
{ 
	stack<int> Stack; 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
 
	for (int i = 0; i < V; i++) 
	if (visited[i] == false) 
    topologicalSortUtil(i, visited, Stack); 

	
	while (!Stack.empty()) 
	{ 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
} 

 
int main() 
{ 
	
   Graph g(6);
   g.addEdge(5,0);
   g.addEdge(4,0);
   g.addEdge(4,1);
   g.addEdge(5,2);
   g.addEdge(2,3);
   g.addEdge(3,1);

//    Graph g(8);
//    g.addEdge(7,11);
//    g.addEdge(7,8);
//    g.addEdge(5,11);
//    g.addEdge(3,8);
//    g.addEdge(8,9);
//    g.addEdge(11,2);
//    g.addEdge(11,9);
//    g.addEdge(11,10);





	cout << " Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
}