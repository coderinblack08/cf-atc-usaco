#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n;
const int MAX_N = 1e3;
int grid[MAX_N][MAX_N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  ll horz_ans = 0, vert_ans = 0;
  for (int y = 0; y < n; y++) {
    ll sums[2] = {0, 0};
    for (int x = 0; x < n; x++) {
      sums[x % 2] += grid[y][x];
    }
    horz_ans += max(sums[0], sums[1]);
  }
  for (int x = 0; x < n; x++) {
    ll sums[2] = {0, 0};
    for (int y = 0; y < n; y++) {
      sums[y % 2] += grid[y][x];
    }
    vert_ans += max(sums[0], sums[1]);
  }
  cout << max(horz_ans, vert_ans) << endl;
  return 0;
}