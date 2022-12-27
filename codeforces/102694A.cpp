#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dist;
vector<vector<int>> adj;

int dfs(int u, int p) {
  for (auto &c: adj[u]) {
    if (c != p) {
      dist[c] = dist[u] + 1;
      dfs(c, u);
    }
  }
}

void dfs(int x) {
  dist.assign(n + 1, 0);
  dfs(x, -1);
}

int diameter() {
  // first take dfs from arbitrary node to farthest node
  dfs(1);
  int best = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[best]) {
      best = i;
    }
  }
  // from fartest node find it's farthest node, take the distance
  dfs(best);
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[best]) {
      best = i;
    }
  }
  return dist[best];
}

int main() {
  cin >> n;
  adj.resize(n + 1, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << diameter() * 3 << endl;
  return 0;
}
