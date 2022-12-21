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

set<int> vis;

int dfs(int x, vector<int> adj[]) {
  int res = 1;
  vis.insert(x);
  for (int y : adj[x]) {
    if (!vis.count(y)) res += dfs(y, adj);
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj_1[n + 1], adj_2[n + 1];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj_1[a].push_back(b);
    adj_2[b].push_back(a);
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": ";
  //   for (int j : adj_2[i]) {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int total = 0;
    total += dfs(i, adj_1);
    vis.clear();
    total += dfs(i, adj_2);
    vis.clear();
    ans += total == n + 1;
  }
  cout << ans;
  return 0;
}