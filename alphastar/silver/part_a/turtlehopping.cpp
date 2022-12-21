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
  int m, n, m1, m2;
  cin >> m >> n >> m1 >> m2;
  int lake[m][n];
  pair<int, int> start;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> lake[i][j];
      if (lake[i][j] == 3) start = make_pair(i, j);
    }
  }

  queue<pair<int, int>> q;
  set<pair<int, int>> used;
  map<pair<int, int>, int> d;

  q.push(start);
  used.insert(start);
  d[start] = 0;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (lake[(v.first)][(v.second)] == 4) {
      cout << d[v];
      break;
    }
    int dr[8] = {m1, -m1, m1, -m1, m2, -m2, m2, -m2};
    int dc[8] = {m2, m2, -m2, -m2, m1, m1, -m1, -m1};
    for (int k = 0; k < 8; k++) {
      auto r = (v.first) + dr[k];
      auto c = (v.second) + dc[k];
      auto p = make_pair(r, c);
      if (r >= 0 && r < m && c >= 0 && c < n && !used.count(p) && lake[r][c] == 1 || lake[r][c] == 4) {
        used.insert(p);
        q.push(p);
        d[p] = d[v] + 1;
      }
    }
  }
  return 0;
}