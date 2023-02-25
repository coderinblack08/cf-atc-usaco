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

struct DSU {
  vector<int> e;
  void init(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool sameSet(int a, int b) { return get(a) == get(b); }
  vector<int> sameSetElements(int x) {
    vector<int> res;
    for (int i = 0; i < e.size(); i++) {
      if (sameSet(x, i)) res.push_back(i);
    }
    return res;
  }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y]; e[y] = x;
    return 1;
  }
};

int n;
DSU dsu;
const int N = 1505;
int grid[N + 1][N + 1];
int comp[N + 1][N + 1];
bool vis[N + 1][N + 1] = {false};

void floodfill(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= n || vis[r][c]) return;
  vis[r][c] = true;
  if ((char)grid[r][c] == 'R') {
    dsu.unite(r * (n + 1) + c, r * (n + 1) + c + 1);
    floodfill(r, c + 1);
  }
  if ((char)grid[r][c] == 'D') {
    dsu.unite(r * (n + 1) + c, (r + 1) * (n + 1) + c);
    floodfill(r + 1, c);
  } 
}

void solve() {
  ll cost = 0;
  for (int i = 0; i < n; i++) {
    cost += (dsu.size(n * (n + 1) + i) - 1) * grid[n][i];
    cost += (dsu.size(i * (n + 1) + n) - 1) * grid[i][n];
  }
  cout << cost << endl;
}

int main() {
  cin >> n;
  dsu.init((n + 1) * (n + 1));
  for (int i = 0; i < n; i++) {
    string s; int c;
    cin >> s >> c;
    for (int j = 0; j < s.size(); j++) {
      grid[i][j] = s[j];
    }
    grid[i][n] = c;
  }
  for (int i = 0; i < n; i++) {
    cin >> grid[n][i];
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (!vis[r][c]) {
        floodfill(r, c);
      }
    }
  }
  solve();
  int q;
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    i--; j--;
    if (grid[i][j] == 'R') {
      grid[i][j] = 'D';
    } else {
      grid[i][j] = 'R';
    }
    auto elems = dsu.sameSetElements(i * (n + 1) + j);
    for (auto x : elems) {
      vis[x / (n + 1)][x % (n + 1)] = false;
      dsu.e[x] = -1;
    }
    for (auto x : elems) {
      if (!vis[x / (n + 1)][x % (n + 1)]) {
        floodfill(x / (n + 1), x % (n + 1));
      }
    }
    solve();
  }
  return 0;
}
