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

struct DSU {
  vector<int> e;
  int p, largest_p;
  DSU(int N) {
    p = N;
    largest_p = 1;
    e = vector<int>(N, -1);
  }
  // collapsing recursive find
  int get(int x) {
    return e[x] < 0 ? x : e[x] = get(e[x]);
  }
  int size(int x) {
    return -e[get(x)];
  }
  bool same_set(int x, int y) {
    return get(x) == get(y);
  }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;  // cycle
    // x has more nodes, we append to it instead of y
    // swap to make sure this is the case
    if (e[x] > e[y]) swap(x, y);
    p--;
    e[x] += e[y];
    e[y] = x;
    largest_p = max(-e[x], largest_p);
    return true;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    dsu.unite(a - 1, b - 1);
    cout << dsu.p << " " << dsu.largest_p << endl;
  }
  return 0;
}