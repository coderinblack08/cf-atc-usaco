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

vector<vector<int>> adj;
map<pair<int, int>, int> edge;

int dfs(int node, int target, int r = INT_MAX) {
  if (node == target) {
    return r;
  }
  int ans;
  for (int i : adj[node]) {
    ans = min(ans, dfs(i, target, min(r, edge[{i, node}])));
  }
  return ans;
}

int main() {
  int n, q;
  cin >> n >> q;
  adj.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int p, q, r;
    cin >> p >> q >> r;
    adj[p].push_back(q);
    adj[q].push_back(p);
    edge[{p, q}] = r;
    edge[{q, p}] = r;
  }
  for (int i = 0; i < q; i++) {
    int k, v;
    cin >> k >> v;
    cout << dfs(k, v) << endl;
  }
  return 0;
}