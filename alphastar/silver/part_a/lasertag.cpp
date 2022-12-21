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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  int w, h;
  cin >> w >> h;
  vector<vector<char>> grid;
  vector<pair<int, int>> cows;
  grid.resize(h);
  for (int i = 0; i < h; i++) {
    grid[i].resize(w);
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'C') {
        cows.push_back(make_pair(i, j));
      }
    }
  }
  queue<pair<int, int>> q;
  map<pair<int, int>, int> dist;
  q.push(cows[0]);
  dist[cows[0]] = 0;
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    if (curr.first == cows[1].first && curr.second == cows[1].second) {
      cout << dist[curr] - 1 << endl;
      return 0;
    }
    for (int k = 0; k < 4; k++) {
      int travel = 0;
      while (true) {
        int nx = curr.first + dx[k] * travel;
        int ny = curr.second + dy[k] * travel;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] == '*') {
          break;
        }
        if (!dist.count(make_pair(nx, ny))) {
          dist[make_pair(nx, ny)] = dist[curr] + 1;
          q.push(make_pair(nx, ny));
        }
        travel++;
      }
    }
  }
}