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

int main() {
  int n;
  cin >> n;
  int matrix[n][n];
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> matrix[r][c];
    }
  }
  int max_sum = -1e9;
  int dr[4] = {0, 1, 1, 1};
  int dc[4] = {1, 0, 1, -1};
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      for (int dir = 0; dir < 4; dir++) {
        int walking_sum = 0;
        for (int steps = 0; steps < n; steps++) {
          int next_r = (r + (steps * dr[dir]) + n) % n;
          int next_c = (c + (steps * dc[dir]) + n) % n;
          walking_sum += matrix[next_r][next_c];
          max_sum = max(max_sum, walking_sum);
        }
      }
    }
  }
  cout << max_sum;
  return 0;
}