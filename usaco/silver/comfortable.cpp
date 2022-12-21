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

int pasture[2000][2000];

int main() {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int n;
  cin >> n;
  queue<pair<int, int>> q;
  int cow_count = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    q.push({x + 500, y + 500});
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (pasture[curr.first][curr.second]) continue;
      cow_count++;
      pasture[curr.first][curr.second] = true;
      for (int i = 0; i < 4; i++) {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];
        if (!pasture[nx][ny]) continue;
        int adj_count = 0;
        for (int j = 0; j < 4; j++) {
          int nnx = nx + dx[j];
          int nny = ny + dy[j];
          adj_count += pasture[nnx][nny];
        }
        if (adj_count == 3) {
          for (int j = 0; j < 4; j++) {
            int nnx = nx + dx[j];
            int nny = ny + dy[j];
            if (!pasture[nnx][nny]) {
              q.push({nnx, nny});
            }
          }
        }
      }
    }
    cout << cow_count - (i + 1) << endl;
  }
  return 0;
}