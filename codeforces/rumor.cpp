#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

vector<int> cost;
vector<vector<int>> adj;
vector<int> lowest_comp_cost;

set<int> vis;
void dfs(int x) {
  if (vis.count(x)) {
    return;
  }
  lowest_comp_cost.back() = min(lowest_comp_cost.back(), cost[x - 1]);
  vis.insert(x);
  for (int y : adj[x]) {
    dfs(y);
  }
}

std::int32_t main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  cost.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis.count(i)) {
      lowest_comp_cost.push_back(INT_MAX);
      dfs(i);
    }
  }
  int total_cost = 0;
  for (int c : lowest_comp_cost) {
    cerr << c << endl;
    total_cost += c;
  }
  cout << total_cost << endl;
  return 0;
}
