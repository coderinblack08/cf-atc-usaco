#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
  setIO();
  int n;
  cin >> n;
  vector<ll> M(n);
  ll sum = 0;
  M[sum] = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    M[(sum % n + n) % n]++;
  }
  ll ans = 0;
  for (ll x : M) {
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}