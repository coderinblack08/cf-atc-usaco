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

vector<int> adj[int(5e5 + 1)];

int dfs(int u, int p = -1) {
  int sz = 1;
  for (auto v : adj[u]) {
    if (v == p) continue;
    sz += dfs(v, u);
  }
  return sz;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int _ = 0; _ < m; _++) {
    int k;
    cin >> k;
    vector<int> friends(k);
    for (int i = 0; i < k; i++) {
      cin >> friends[i];
      friends[i]--;
    }
    for (int i = 0; i < k - 1; i++) {
      adj[friends[i]].push_back(friends[i + 1]);
      adj[friends[i + 1]].push_back(friends[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dfs(i) << " ";
  }
  return 0;
}