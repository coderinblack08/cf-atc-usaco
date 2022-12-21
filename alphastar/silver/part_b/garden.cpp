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

void rotate(vector<string> &a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j >= n - 1) continue;
      char t = a[i][j];
      a[i][j] = a[n - 1 - j][n - 1 - i];
      a[n - 1 - j][n - 1 - i] = t;
    }
  }
}

void dfs(vector<string> &a, int x, int y, vector<set<string>> &sets, string path) {
  if (x + y == n - 1) {
    sets[x].insert(path + a[x][y]);
    return;
  }
  dfs(a, x + 1, y, sets, path + a[x][y]);
  dfs(a, x, y + 1, sets, path + a[x][y]);
}

int main() {
  cin >> n;
  vector<string> grid(n);
  vector<set<string>> rows_1(n), rows_2(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  dfs(grid, 0, 0, rows_1, "");
  rotate(grid);
  dfs(grid, 0, 0, rows_2, "");
  set<string> ans;
  for (int i = 0; i < n; i++) {
    for (string s : rows_1[i]) {
      if (rows_2[i].count(s)) {
        ans.insert(s);
      }
    }
  }
  cout << ans.size();
  return 0;
}