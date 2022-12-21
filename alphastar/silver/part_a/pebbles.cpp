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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  auto solve_min = [&]() {
    // if only one pebble is away from a group of n-1 pebbles, then only 2 operations are used
    if (a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) return 2;
    if (a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) return 2;
    // otherwise, use two-pointers where i is the start of the n-sized window
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < n - 1 && a[j + 1] - a[i] <= n - 1) j++;
      ans = max(ans, j - i + 1);
    }
    return n - ans;
  };
  auto solve_max = [&]() {
    // get number of gaps (maximum achieved by swapping)
    return max(a[n - 2] - a[0], a[n - 1] - a[1]) - (n - 2);
  };
  cout << solve_min() << endl
       << solve_max();
  return 0;
}