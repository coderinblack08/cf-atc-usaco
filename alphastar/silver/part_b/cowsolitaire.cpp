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

int n;
vector<vector<pair<int, char>>> v;

int dfs(int r, int c, int value) {
  if (r < 0 || r >= n || c < 0 || c >= n) return 0;
  if (c == n - 1 && r == 0) return value + v[0][n - 1].first;
  return max(dfs(r - 1, c, value + v[r][c].first), dfs(r, c + 1, value + v[r][c].first));
}

int main() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(n);
    for (int j = 0; j < n; j++) {
      char value;
      cin >> value >> v[i][j].second;
      if (value >= '2' && value <= '9') {
        v[i][j].first = value - '0';
      } else if (value == 'A') {
        v[i][j].first = 1;
      } else if (value == 'T') {
        v[i][j].first = 10;
      } else if (value == 'J') {
        v[i][j].first = 11;
      } else if (value == 'Q') {
        v[i][j].first = 12;
      } else if (value == 'K') {
        v[i][j].first = 13;
      }
    }
  }
  cout << dfs(n - 1, 0, 0);
  return 0;
}