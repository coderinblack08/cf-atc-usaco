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

struct Order {
  int from, to;
  ll amount; 
};

vector<vector<int>> adj;
vector<ll> h, sum;
vector<Order> orders;

void dfs_subtree(int x, int p) {
  ll curr = h[x];
  for (int u : adj[x]) {
    if (u != p) {
      dfs_subtree(u, x);
      curr += sum[u];
    }
  }
  sum[x] = curr;
}

void dfs_orders(int x, int p) {
  // move up the tree (positive)
  for (int u : adj[x]) {
    if (u != p) {
      if (sum[u] >= 0) dfs_orders(u, x);
      if (sum[u] > 0) orders.pb({u, x, sum[u]});
    }
  }
  // move down tree tree (negative)
  for (int u : adj[x]) {
    if (u != p && sum[u] < 0) {
      orders.pb({x, u, -sum[u]});
      dfs_orders(u, x);
    }
  }
}

/* void dfs_orders(int x, int p) { */
/*   // 1. dfs over net positive subtrees */
/*   for (int u : adj[x]) { */
/*     if (u != p && sum[u] > 0) { */
/*       dfs_orders(u, x); */
/*     } */
/*   } */
/*  */
/*   // 2. dfs over net negative subtrees, and give them haybales */
/*   for (int u : adj[x]) { */
/*     if (u != p && sum[u] <= 0) { */
/*       if (sum[u] < 0) orders.pb({u, x, -sum[u]}); */
/*       dfs_orders(u, x); */
/*     } */
/*   } */
/*  */
/*   // 3. move extra haybales to parent */
/*    if (x != 1 && sum[x] > 0) { */
/*      orders.pb({x, p, sum[x]}); */
/*    } */
/* } */



int main() {
  ll n, avg = 0;
  cin >> n;
  adj.resize(n + 1);
  h.resize(n + 1);
  sum.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    avg += h[i];
  }
  avg /= n;
  for (int i = 1; i <= n; i++) {
    h[i] -= avg;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs_subtree(1, 1);
  dfs_orders(1, 1);
  cout << sz(orders) << endl;
  for (Order o : orders) {
    cout << o.from << " " << o.to << " " << o.amount << endl;
  }
  return 0;
}
