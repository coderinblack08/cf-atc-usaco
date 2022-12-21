#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("paintbarn");
  int n, k, ans = 0;
  cin >> n >> k;

  vector<vector<int>> dp(1001, vector<int>(1001, 0));
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dp[x1][y1]++;
    dp[x1][y2]--;
    dp[x2][y1]--;
    dp[x2][y2]++;
  }

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (i) dp[i][j] += dp[i - 1][j];
      if (j) dp[i][j] += dp[i][j - 1];
      if (i && j) dp[i][j] -= dp[i - 1][j - 1];
      if (dp[i][j] == k) ans++;
    }
  }

  cout << ans;

  return 0;
}