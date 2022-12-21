#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  DSU(int N) {
    e = vector<int>(N, -1);
  }
  // collapsing recursive find
  int get(int x) {
    return e[x] < 0 ? x : e[x] = get(e[x]);
  }
  int size(int x) {
    return -e[get(x)];
  }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;  // cycle
    // x has more nodes, we append to it instead of y
    // swap to make sure this is the case
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  DSU dsu(n);

  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      dsu.unite(u, v);
    } else {
      cout << int(dsu.get(u) == dsu.get(v)) << endl;
    }
  }
}