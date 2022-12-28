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

struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int size(int x) { return -e[get(x)]; }
  bool same_set(int x, int y) { return get(x) == get(y); }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
      return false;
    if (e[x] > e[y])
      swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

int main() {
  setIO();
  int n, k;
  cin >> n >> k;
  vector<set<int>> trav(n + 1);
  vi p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    trav[p[i]].insert(i);
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    trav[p[a]].insert(b);
    trav[p[b]].insert(a);
    swap(p[a], p[b]);
  }
  DSU dsu(n + 1);
  for (int i = 1; i <= n; i++)
    dsu.unite(i, p[i]);
  vector<set<int>> components(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int u : trav[i]) {
      components[dsu.get(i)].insert(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << sz(components[dsu.get(i)]) << "\n";
  }
  return 0;
}
