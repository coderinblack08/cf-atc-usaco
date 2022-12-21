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

int city_count[1001];
vector<int> adj[10001];
set<int> vis;

void dfs(int u) {
  if (vis.count(u)) return;
  city_count[u]++;
  vis.insert(u);
  for (auto v : adj[u]) {
    dfs(v);
  }
}

int main() {
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> friends(k);
  for (int i = 0; i < k; i++) {
    cin >> friends[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for (auto f : friends) {
    vis.clear();
    dfs(f);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (city_count[i] == k) ans++;
  }
  cout << ans;
  return 0;
}