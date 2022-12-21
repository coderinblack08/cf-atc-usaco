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

int main() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < n - 1; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    adj[p].push_back({q, r});
    adj[q].push_back({p, r});
  }
  while (q--) {
    int k, v_i;
    cin >> k >> v_i;
    int ans = -1;
    queue<int> queue;
    vector<bool> vis(n + 1, false);
    vector<int> dist(n + 1, 1e9);
    queue.push(v_i);
    vis[v_i] = true;
    while (!queue.empty()) {
      auto u = queue.front();
      queue.pop();
      if (dist[u] < k) {
        continue;
      } else {
        ans++;
      }
      for (auto [v, w] : adj[u]) {
        if (!vis[v]) {
          vis[v] = true;
          dist[v] = min(dist[u], w);
          queue.push(v);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}