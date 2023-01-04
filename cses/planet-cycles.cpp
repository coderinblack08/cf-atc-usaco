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

vi t;
vector<vi> parents, comp;
vector<bool> vis;

void dfs(int x, int c) { vis[x] = true;
  comp[c].pb(x);
  if (!vis[t[x]]) {
    dfs(t[x], c);
  }
  for (auto p : parents[x]) {
    if (!vis[p]) dfs(p, c);
  }
}

int main() {
  int n;
  cin >> n;
  t.resize(n + 1);
  comp.resize(n);
  parents.resize(n + 1);
  vis.assign(n + 1, false);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    parents[t[i]].pb(i);
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, c++);
    }
  }
  vi ans(n + 1);
  vector<bool> cycle(n + 1, false);
  for (int i = 0; i < c; i++) {
    if (comp[i].empty()) continue;
    int root = comp[i][0];
    for (auto j : comp[i]) {
      if (parents[j].empty()) {
        root = j;
        break;
      }
    }
    int len = 0;
    int x = root, y = root;
    do {
      x = t[x];
      y = t[t[y]];
    } while (x != y);
    do {
      x = t[x];
      len++;
      cycle[x] = true;
    } while (x != y);
    x = root;
    while (x != y) {
      x = t[x];
      y = t[y];
    }
    vis.assign(n + 1, false);
    for (auto j : comp[i]) {
      if (cycle[j]) {
        ans[j] = len;
      } else {
        if (parents[j].empty()) {
          int x = j;
          vi tail;
          while (!cycle[x]) {
            vis[x] = true;
            tail.pb(x);
            x = t[x];
          }
          for (int k = 0; k < tail.size(); k++) {
            ans[tail[k]] = len + (tail.size() - k);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
