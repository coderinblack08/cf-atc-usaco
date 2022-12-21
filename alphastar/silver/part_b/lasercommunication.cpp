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

struct Laser {
  int x, y;
  char type;
};

int n, a, b;
vector<Laser> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool vis[200][4];

/*
DIR:
0: up
1: down
2: right
3: left

INPUT:
5 6 1
2 0 / (0)
1 2 / (1)
2 3 \ (2)
6 3 \ (3)
3 2 \ (4)

SAMPLE:
3 ../...\
2 ./.\...
1 ......A
0 H./....
  0123456
*/

int find_next_laser(int x, int y, int dir, set<tuple<int, int, int>> seen) {
  for (int i = 0; i < v.size(); i++) {
    if ((dx[dir] == 0 ? v[i].x == x : dx[dir] == -1 ? v[i].x < x
                                                    : v[i].x > x) &&
        (dy[dir] == 0 ? v[i].y == y : dy[dir] == -1 ? v[i].y < y
                                                    : v[i].y > y) &&
        !seen.count(make_tuple(x, y, dir))) {
      return i;
    }
  }
  return -1;
}

bool target_in_view(int x, int y, int dir) {
  // 0, -1    6, 3    6, 1
  if ((dx[dir] == 0 ? x == a : dx[dir] == -1 ? x > a
                                             : x < a) &&
      (dy[dir] == 0 ? y == b : dy[dir] == -1 ? y > b
                                             : y < b)) {
    return true;
  }
  return false;
}

int get_dir(int curr_dir, char type) {
  if (type == '/') {
    int new_dir[4] = {2, 3, 0, 1};
    return new_dir[curr_dir];
  } else {
    int new_dir[4] = {3, 2, 1, 0};
    return new_dir[curr_dir];
  }
}

bool ok() {
  int x = 0, y = 0, dir = 2;
  set<tuple<int, int, int>> seen;
  while (true) {
    if (seen.count(make_tuple(x, y, dir))) return false;
    int next = find_next_laser(x, y, dir, seen);
    cerr << "node: " << x << ", " << y << "  dir: " << dir << " next: " << next << endl;
    if (target_in_view(x, y, dir)) return true;
    if (next == -1) return false;
    seen.insert(make_tuple(x, y, dir));
    x = v[next].x;
    y = v[next].y;
    dir = get_dir(dir, v[next].type);
  }
}

int main() {
  cin >> n >> a >> b;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y >> v[i].type;
  }
  if (ok()) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    v[i].type = v[i].type == '/' ? '\\' : '/';
    cerr << "Switched laser " << i << " to " << v[i].type << endl;
    if (ok()) {
      cout << i + 1;
      return 0;
    }
    v[i].type = v[i].type == '/' ? '\\' : '/';
  }
  cout << -1;
  return 0;
}
