#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
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

int curr;
vector<vector<int>> sets;

// only keeps unique values between two vectors
vector<int> vec_union(vector<int> &a, vector<int> &b) {
  int i = 0, j = 0;
  vector<int> res;
  while (true) {
    while (i < sz(a) && j < sz(b) && a[i] == b[j])
      j++;
    if (j >= sz(b) && i >= sz(a))
      break;
    if (i == sz(a)) {
      res.pb(b[j++]);
    } else if (j == sz(b)) {
      res.pb(a[i++]);
    } else if (a[i] < b[j]) {
      res.pb(a[i++]);
    } else {
      res.pb(b[j++]);
    }
  }
  return res;
}

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v])
      dfs(v, vis, adj);
  }
  sets[u] = {++curr};
  for (int v : adj[u]) {
    sets[u] = vec_union(sets[u], sets[v]);
  }
}

int main() {
  setIO();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> b(n);
    vector<vector<int>> adj(n);
    // case might have multiple trees, use src to store their roots
    vector<bool> src(n, true);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      for (int j = 0; j < n; j++) {
        if (b[i][j] == '1') {
          adj[j].pb(i);
          src[i] = false;
        }
      }
    }
    sets = vector<vector<int>>(n);
    vector<bool> vis(n);
    curr = 0;
    for (int i = 0; i < n; i++) {
      if (src[i]) {
        dfs(i, vis, adj);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << sz(sets[i]);
      for (int j = 0; j < sz(sets[i]); j++) {
        cout << " " << sets[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
