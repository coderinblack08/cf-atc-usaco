// Time complexity of O(E log E) or O(E log V).
// Basic application of DSU to find MST (minimum spanning tree)

#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int size(int x) { return -e[get(x)]; }
  bool same_set(int x, int y) { return get(x) == get(y); }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
      return false;
    if (e[x] > e[y])
      swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

struct Edge {
  int u, v, w;
  bool operator<(Edge const &other) { return w < other.w; }
};

int kruskal(int n, vector<Edge> edges) {
  int cost = 0;
  DSU dsu(n);
  sort(edges.begin(), edges.end());
  for (Edge e : edges) {
    if (dsu.unite(e.u, e.v)) {
      cost += e.w;
    }
    // stop early if we already include all vertices
    if (dsu.size(0) == n)
      break;
  }
  if (dsu.size(0) != n)
    return -1;
  return cost;
}

int main() {
  vector<Edge> edges = {{1, 2, 1}, {1, 3, 3}, {1, 4, 10}, {2, 3, 5},
                        {2, 5, 7}, {3, 4, 2}, {3, 5, 8},  {4, 5, 4}};

  int cost = kruskal(5, edges);
  cout << cost << endl;

  return 0;
}
