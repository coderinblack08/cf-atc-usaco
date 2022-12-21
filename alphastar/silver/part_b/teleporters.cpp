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

int n, m;
vector<pair<int, int>> adj[(int)1e5 + 1];
vector<int> p;
int comp[(int)1e5 + 1];

void dfs(int v, int color, int min_h) {
  comp[v] = color;
  for (auto [u, w] : adj[v]) {
    if (w >= min_h && comp[u] == -1) {
      dfs(u, color, min_h);
    }
  }
}

bool check(int min_h) {
  fill(all(comp), -1);
  int color = -1;
  for (int i = 1; i <= n; i++) {
    if (comp[i] == -1) {
      dfs(i, ++color, min_h);
    }
  }
  for (int i = 0; i < n; i++) {
    if (comp[i] != comp[p[i]]) return false;
  }
  return true;
}

int main() {
  cin >> n >> m;
  p.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 0; i < m; i++) {
    int a, b, h;
    cin >> a >> b >> h;
    adj[a].push_back(make_pair(b, h));
    adj[b].push_back(make_pair(a, h));
  }
  int lo = 0, hi = 1e9;
  while (lo != hi) {
    int mid = (lo + hi + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  if (lo == 1e9)
    cout << -1;
  else
    cout << lo << endl;
  return 0;
}