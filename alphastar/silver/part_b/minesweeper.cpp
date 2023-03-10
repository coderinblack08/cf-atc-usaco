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

int field[30][30];
bool mine[30][30];

void dfs(pair<int, int> node) {
  mine[node.first][node.second] = true;
  dfs({node.first, node.second + 1});
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
    }
  }
  return 0;
}