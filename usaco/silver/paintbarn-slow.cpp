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

// remember, the problem is talking about coordinates, not side lengths!
// the coordinates are not 1-indexed

const int MAX_N = 1e3;
int barn[MAX_N][MAX_N + 1];

int main() {
  setIO("paintbarn");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j < x2; j++) {
      barn[j][y1]++;
      barn[j][y2]--;
    }
  }
  int ans = 0;
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      if (barn[i][j] == k) {
        ans++;
      }
      barn[i][j + 1] += barn[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}