#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

const int N = 3e5+5, bits = 20;
vector<int> adj[N];
int depth[N], up[N][bits + 1];


void dfs(int node, int p) {
  depth[node] = depth[p] + 1;
  up[node][0] = p;
  for (auto child : adj[node]) {
    if (child != p) {
      dfs(child, node);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = bits; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = up[u][i];
    }
  }
  if (u == v) return u;
  for (int i = bits; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int get(int node, int dist) {
  for (int i = bits; i >= 0; i--) {
    if (dist & (1 << i)) {
      node = up[node][i];
    }
  }
  return node;
}

int main() {
  setIO();
  int n, u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  auto setup = [&]() {
    dfs(1, 1);
    for (int i = 1; i <= bits; i++) {
      for (int j = 1; j <= n; j++) {
        up[j][i] = up[up[j][i - 1]][i - 1];
      }
    }
  };
  setup();
  int q, a, b, c;
  cin >> q;
  while (q--) {
    cin >> a >> b >> c;
    int ancestor = lca(a, b);
    int d1 = depth[a] - depth[ancestor];
    int d2 = depth[b] - depth[ancestor];
    if (d1 + d2 <= c) {
      cout << b << '\n';
    } else {
      if (c <= d1) {
        cout << get(a, c) << '\n';
      } else {
        cout << get(b, d2 - (c - d1)) << '\n';
      }
    }
  }
  return 0;
}
