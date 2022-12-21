#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> G;
vector<int> colors;

int main() {
  cin >> n >> m;
  colors.assign(n + 1, -1);
  G.assign(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
}
