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

const int MAX_N = 1e3;
int forest[MAX_N + 1][MAX_N + 1];

int main() {
  setIO();
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      forest[i][j] += forest[i - 1][j] + forest[i][j - 1] - forest[i - 1][j - 1] + (c == '*');
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << forest[x2][y2] - forest[x1 - 1][y2] - forest[x2][y1 - 1] + forest[x1 - 1][y1 - 1] << endl;
  }
  return 0;
}
