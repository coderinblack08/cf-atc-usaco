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
  map<ll, int> mp;
  mp[0]++;
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    ans += mp[sum - x];
    mp[sum]++;
  }
  std::cout << ans << endl;
  return 0;
}