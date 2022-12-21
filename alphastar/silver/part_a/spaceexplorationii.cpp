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
  int n;
  cin >> n;
  char space[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> space[i][j];
    }
  }
  int ans = 0;
  queue<pair<int, int>> q;
  set<pair<int, int>> vis;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (space[i][j] == '*' && !vis.count(make_pair(i, j))) {
        ans++;
        q.push(make_pair(i, j));
        while (!q.empty()) {
          auto v = q.front();
          q.pop();
          int dx[4] = {1, 0, -1, 0};
          int dy[4] = {0, 1, 0, -1};
          for (int k = 0; k < 4; k++) {
            int new_i = v.first + dx[k];
            int new_j = v.second + dy[k];
            auto p = make_pair(new_i, new_j);
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && space[new_i][new_j] == '*' && !vis.count(p)) {
              vis.insert(p);
              q.push(p);
            }
          }
        }
      }
    }
  }
  cout << ans;
}

int main() {
  solve();
  return 0;
}