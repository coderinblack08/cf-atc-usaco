#include <bits/stdc++.h>
using namespace std;

// O(N log N)

struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  // collapsing recursive find
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int size(int x) { return -e[get(x)]; }
  bool same_set(int x, int y) { return get(x) == get(y); }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
      return false; // cycle
    if (e[x] > e[y])
      swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
