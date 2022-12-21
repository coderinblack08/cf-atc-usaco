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

const int MX = 400;
int A[2 * MX - 1][2 * MX - 1];

int main() {
  setIO("lazy");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i + j][n - i + j - 1];
    }
  }
  int t = (n + 1) % 2, best = 0;
  n = n * 2 - 1;
  for (int i = 0; i < n; i++, t = 1 - t) {
    int sum = 0;
    for (int a = max(i - k, 0); a < n && a <= i + k; a++) {
      for (int b = max(t - k, 0); b < n && b <= t + k; b++) {
        sum += A[a][b];
      }
    }
    best = max(sum, best);
    // slide the region
    for (int j = t + 1; j + k < n; j++) {
      for (int a = max(i - k, 0); a < n && a <= i + k; a++) {
        // there is a left column to delete
        if (j - k - 1 >= 0) sum -= A[a][j - k - 1];
        // add right column
        sum += A[a][j + k];
      }
      // update only in lattice points
      if (j % 2 == t && best < sum) best = sum;
    }
  }
  cout << best << endl;
  return 0;
}