#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int number_of_sets() {
    int ans = 0;
    for (int x : e) if (x < 0) ans++;
    return ans;
  }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int size(int x) { return -e[get(x)]; }
  bool same_set(int x, int y) { return get(x) == get(y); }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
      return false; // cycle
    // keep x as the largest set
    if (e[x] > e[y])
      swap(x, y);
    // merge y into x
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    DSU dsu(4 * grid.size() * grid.size());
    int n = sz(grid);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char curr = grid[i][j];
        int index = 4 * (i * n + j);
        if (curr == ' ') {
          dsu.unite(index, index + 1);
          dsu.unite(index, index + 2);
          dsu.unite(index, index + 3);
        } else if (curr == '/') {
          dsu.unite(index, index + 3);
          dsu.unite(index + 1, index + 2);
        } else {
          dsu.unite(index, index + 1);
          dsu.unite(index + 2, index + 3);
        }
        if (j != n - 1) {
          dsu.unite(index + 1, (index + 4) + 3);
        }
        if (i != n - 1) {
          dsu.unite(index + 2, (index + 4 * n) + 0);
        }
      }
    }
    return dsu.number_of_sets();
  }
};
