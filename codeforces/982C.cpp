#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &sz, int n) {
  vis[node] = 1;
  int ret = 1;
  for (int u : graph[node]) {
    if (vis[u] == 0) {
      int u_sz = dfs(u, graph, vis, sz, n);
      sz[u] = u_sz;
      ret = ret + u_sz;
    }
  }
  return ret;
}

void solve(vector<vector<int>> &graph, vector<pair<int, int>> &edges, int n) {
  vector<int> vis(n + 1, 0);
  vector<int> sz(n + 1);
  int sz_of_parent = dfs(1, graph, vis, sz, n);
  sz[1] = sz_of_parent;
  int ans = 0;
  for (int i = 0; i < edges.size(); i++) {
    int x = min(sz[edges[i].first], sz[edges[i].second]);
    if ((x) % 2 == 0 && (n - x) % 2 == 0) {
      ans++;
    }
  }
  if (ans == 0) {
    if (sz[1] % 2 == 0) {
      cout << ans << endl;
    } else {
      cout << "-1" << endl;
    }
  } else {
    cout << ans << endl;
  }
}

int main() {
  setIO();
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  solve(graph, edges, n);
  return 0;
}