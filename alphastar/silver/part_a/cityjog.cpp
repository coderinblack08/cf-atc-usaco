#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((ll)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("reststops");
  ll l, n, rf, rb;
  cin >> l >> n >> rf >> rb;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
  }
  sort(all(v), greater<pair<ll, ll>>());
  ll curr_x = 0, total_t = 0;
  for (auto curr : v) {
    if (curr.second > curr_x) {
      total_t += (curr.second - curr_x) * (rf - rb) * curr.first;
      curr_x = curr.second;
    }
  }
  cout << total_t;
  return 0;
}