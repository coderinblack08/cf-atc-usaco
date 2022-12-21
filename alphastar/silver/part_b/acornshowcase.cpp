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

vector<int> adj[(int)1e5 + 1];
bool vis[(int)1e5 + 1];
map<int, vector<int>> comp;

void dfs(int node, int color) {
  if (vis[node]) return;
  vis[node] = true;
  comp[color].push_back(node);
  for (auto u : adj[node]) {
    dfs(u, color);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> acorns(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> acorns[i].first >> acorns[i].second;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int color = -1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, ++color);
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i <= color; i++) {
    int left = INT_MAX, right = 0, top = 0, bottom = INT_MAX;
    for (auto u : comp[i]) {
      left = min(left, acorns[u].first);
      right = max(right, acorns[u].first);
      top = max(top, acorns[u].second);
      bottom = min(bottom, acorns[u].second);
    }
    ans = min(ans, 2 * ((right - left) + (top - bottom)));
  }
  cout << ans;
  return 0;
}