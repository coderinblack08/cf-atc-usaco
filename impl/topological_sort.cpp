// https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/

#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<int> *adj;
  void dfs(int v, bool visited[], stack<int> &s);

public:
  Graph(int V);
  void addEdge(int v, int w);
  stack<int> topologicalSort();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::dfs(int v, bool visited[], stack<int> &s) {
  // Mark the current node as visited.
  visited[v] = true;

  // Recurse for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      dfs(*i, visited, s);

  // Push current vertex to stack which stores result
  s.push(v);
}

stack<int> Graph::topologicalSort() {
  stack<int> s;

  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Call the recursive helper function to store Topological
  // Sort starting from all vertices one by one
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      dfs(i, visited, s);

  return s;
}

int main() {}
