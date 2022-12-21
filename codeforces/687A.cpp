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

// minimum vertex cover
// Given a graph G, subset A of its vertices are certex covers of the graph
//    If for each uv edge, u is in A or v is in A.

// boils down to checking for bipartite graphs

vector<int> adj[100005];
bool vis[100005];
bool color[100005];

bool possible = true;

void dfs(int v, bool c) {
  if (vis[v])
    return;
  vis[v] = true;
  color[v] = c;
  for (int u : adj[v]) {
    if (!vis[u]) {
      dfs(u, c ^ 1);
    } else {
      if (c == color[u]) {
        possible = false;
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i] && !adj[i].empty()) {
      dfs(i, false);
    }
  }
  if (possible) {
    int count[2] = {0};
    for (int i = 0; i < n; i++)
      count[color[i]]++;
    cout << count[0] << endl;
    for (int i = 0; i < n; i++) {
      if (color[i] == 0)
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << count[1] << endl;
    for (int i = 0; i < n; i++) {
      if (color[i] == 1)
        cout << i + 1 << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
