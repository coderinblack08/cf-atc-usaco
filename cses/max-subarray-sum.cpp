#include <bits/stdc++.h>
#define LONG_LONG_MIN (-__LONG_LONG_MAX__ - 1LL)
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  int n;
  cin >> n;
  ll A[n + 1];
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    A[i] = x + A[i + 1];
  }
  ll ans = LONG_LONG_MIN;
  ll left = 0;
  for (ll right = 1; right <= n; right++) {
    ans = max(ans, A[right] - left);
    left = min(left, A[right]);
  }
  cout << ans;
  return 0;
}