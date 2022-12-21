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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++) {
    grid[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> mn(n), mx(n);
  for (int i = 0; i < n; i++) {
    mx[i].resize(m);
    fill(all(mx[i]), 0);
    mn[i].resize(m);
    fill(all(mn[i]), 0);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}