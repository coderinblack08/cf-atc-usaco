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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  int l = 0, sum = 0;
  int ans = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > x) {
      sum -= a[l];
      l++;
    }
    if (sum == x) ans++;
  }
  cout << ans << endl;
  return 0;
}