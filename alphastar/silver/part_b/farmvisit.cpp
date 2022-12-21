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

char type[(int)1e5 + 1];
vector<int> comp;
vector<int> adj[(int)1e5 + 1];

void dfs(int node, int color) {
  if (comp[node] != -1) return;
  comp[node] = color;
  for (int u : adj[node]) {
    if (type[node] == type[u]) {
      dfs(u, color);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  comp.resize(n + 1);
  fill(all(comp), -1);
  for (int i = 0; i < n; i++) cin >> type[i + 1];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int color = -1;
  for (int i = 0; i < n; i++) {
    if (comp[i + 1] == -1) {
      dfs(i + 1, ++color);
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    if ((comp[a] == comp[b] && type[a] == c) || (comp[a] != comp[b])) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
  return 0;
}