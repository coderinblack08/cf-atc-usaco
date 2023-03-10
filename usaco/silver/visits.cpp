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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int n;
vector<bool> seen;
vector<vector<int>> in_edges;
vector<int> a, v;


void mark_seen(int x) {
  if (seen[x]) return;
  seen[x] = true;
  for (int y : in_edges[x]) {
    mark_seen(y);
  }
}

int min_cycle_edge(int node) {
  // we dont have to be at the "head" of the graph
  // modified version of floyd's hare and tortoise algorithm
  int x = node, y = node;
  do {
    x = a[x];
    y = a[a[y]];
  } while (x != y);
  // move first pointer until we encounter the second
  // to iterate through the entire cycle
  int min_edge = INT_MAX;
  do {
    min_edge = min(min_edge, v[x]);
    x = a[x];
  } while (x != y);
  // has to be within the cycle
  // otherwise, doesn't bubble up to every node in the component
  mark_seen(x);
  return min_edge;
}

int main() {
  setIO();
  cin >> n;
  ll ans = 0;
  seen.assign(n + 1, false);
  a.resize(n + 1);
  v.resize(n + 1);
  in_edges.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> v[i];
    ans += v[i];
    in_edges[a[i]].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) ans -= min_cycle_edge(i);
  }
  cout << ans << endl;
  return 0;
}
