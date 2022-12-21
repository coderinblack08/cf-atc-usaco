#include <bits/stdc++.h>
#include <vector>
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid;
  grid.resize(n);
  pair<int, int> start, end;
  map<char, vector<pair<int, int>>> portal_endpoints;
  for (int i = 0; i < n; i++) {
    grid[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '@') {
        start = make_pair(i, j);
      } else if (grid[i][j] == '=') {
        end = make_pair(i, j);
      } else if (grid[i][j] != '#' && grid[i][j] != '.') {
        portal_endpoints[grid[i][j]].push_back(make_pair(i, j));
      }
    }
  }
  queue<pair<int, int>> q;
  map<pair<int, int>, int> dist;
  set<pair<int, int>> vis;
  q.push(start);
  dist[start] = 0;
  vis.insert(start);
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    if (top == end) {
      cout << dist[top] << endl;
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = top.first + dx[dir];
      int ny = top.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }
      if (grid[nx][ny] == '#') {
        continue;
      }
      pair<int, int> new_pos = make_pair(nx, ny);
      if (portal_endpoints.count(grid[nx][ny])) {
        auto endpoints = portal_endpoints[grid[nx][ny]];
        if (endpoints[0] == new_pos) {
          new_pos = endpoints[1];
        } else {
          new_pos = endpoints[0];
        }
      }
      if (vis.count(new_pos)) {
        continue;
      }
      q.push(new_pos);
      dist[new_pos] = dist[top] + 1;
      vis.insert(new_pos);
    }
  }
}
