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

int n, m;
set<int> vis;
vector<int> adj[1001];

int dfs(int u, int path = 0) {
  if (u == 1) return path;
  int ans = 1e9;
  for (int v : adj[u]) {
    if (vis.count(v)) continue;
    vis.insert(v);
    ans = min(ans, dfs(v, path + 1));
    vis.erase(v);
  }
  return ans;
}

int bfs(int x) {
  queue<int> q;
  vector<int> d(n + 1, 0);
  q.push(x);
  vis.insert(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == 1) return d[u];
    for (int v : adj[u]) {
      if (vis.count(v)) continue;
      d[v] = d[u] + 1;
      vis.insert(v);
      q.push(v);
    }
  }
  return -1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int largest_dist = 0, stand, count = 0;
  for (int i = 2; i <= n; i++) {
    vis.clear();
    vis.insert(i);
    auto cache = bfs(i);
    // cout << i << " " << cache << endl;
    if (cache == largest_dist) count++;
    if (cache > largest_dist) {
      largest_dist = cache;
      count = 1;
      stand = i;
    }
  }
  cout << stand << " " << largest_dist << " " << count << endl;
  return 0;
}