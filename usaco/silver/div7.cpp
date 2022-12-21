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
  setIO("div7");
  int n;
  cin >> n;
  vector<ll> A(n + 1, 0);
  for (int i = 1; i < n + 1; i++) {
    ll c;
    cin >> c;
    A[i] = (A[i - 1] + c) % 7;
  }
  // max(n) == 5 * 10 ^ 4
  vector<pair<int, int>> occur(7, {-1, -1});
  for (int i = 1; i <= n; i++) {
    if (occur[A[i]].first == -1) {
      occur[A[i]].first = i;
    } else {
      occur[A[i]].second = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    ans = max(ans, occur[i].second - occur[i].first);
  }
  cout << ans << endl;
  return 0;
}