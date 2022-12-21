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

void dfs(const vector<vector<int>>& edges, vector<int>& comps, int node, int color) {
  for (int child : edges[node]) {
    if (comps[child] != color) {
      comps[child] = color;
      dfs(edges, comps, child, color);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<int> comps(n);
  iota(all(comps), 0);
  for (int i = 0; i < n; i++) {
    if (comps[i] == i) {
      dfs(edges, comps, i, i);
    }
  }
  if (comps[0] == comps[n - 1]) {
    cout << 0 << endl;
    return;
  }
  vector<vector<int>> comp_to_vert(n);
  for (int i = 0; i < n; i++) {
    comp_to_vert[comps[i]].push_back(i);
  }
  vector<ll> src_cost(n, 1e9), dst_cost(n, 1e9);
  int src_idx = 0, dst_idx = 0;
  for (int i = 0; i < n; i++) {
    while (src_idx < comp_to_vert[comps[0]].size()) {
      src_cost[comps[i]] = min(src_cost[comps[i]], (ll)abs(i - comp_to_vert[comps[0]][src_idx]));
      if (comp_to_vert[comps[0]][src_idx] < i) {
        src_idx++;
      } else {
        break;
      }
    }
    if (src_idx) src_idx--;
    while (dst_idx < comp_to_vert[comps[n - 1]].size()) {
      dst_cost[comps[i]] = min(dst_cost[comps[i]], (ll)abs(i - comp_to_vert[comps[n - 1]][dst_idx]));
      if (comp_to_vert[comps[n - 1]][dst_idx] < i) {
        dst_idx++;
      } else {
        break;
      }
      if (dst_idx) dst_idx--;
    }
  }
  // this approach works with 1 -> n and 1 -> ? -> n
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    ans = min(ans, src_cost[i] * src_cost[i] + dst_cost[i] * dst_cost[i]);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}