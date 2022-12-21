#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  int R, C;
  cin >> R >> C;
  bool pasture[R][C];  // rocks denoted by true
  pair<int, int> bessie, barn;
  for (int r = 0; r < R; r++) {
    string s;
    cin >> s;
    for (int c = 0; c < C; c++) {
      pasture[r][c] = false;
      if (s[c] == '*') {
        pasture[r][c] = true;
      } else if (s[c] == '.') {
      } else if (s[c] == 'C') {
        bessie = {r, c};
      } else if (s[c] == 'B') {
        barn = {r, c};
      }
    }
  }
  queue<pair<int, int>> q;
  map<pair<int, int>, int> dist;
  set<pair<int, int>> vis;
  q.push(bessie);
  vis.insert(bessie);
  dist[bessie] = 0;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (v.first == barn.first && v.second == barn.second) {
      cout << dist[v] << endl;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int nr = v.first + dx[i];
      int nc = v.second + dy[i];
      auto p = make_pair(nr, nc);
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
        continue;
      }
      if (pasture[nr][nc]) {
        continue;
      }
      if (vis.count(p)) {
        continue;
      }
      vis.insert(p);
      dist[p] = dist[v] + 1;
      q.push(p);
    }
  }
  return 0;
}