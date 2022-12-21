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

int n, m, r;
const int MAX_N = 1e5 + 1;
vector<int> rental, cow;
vector<pair<int, int>> purchase;

int main() {
  setIO("rental");

  cin >> n >> m >> r;
  cow.resize(n);
  purchase.resize(m);
  rental.resize(r);
  for (int i = 0; i < n; i++) {
    cin >> cow[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> purchase[i].second >> purchase[i].first;
  }
  for (int i = 0; i < r; i++) {
    cin >> rental[i];
  }
  sort(cow.begin(), cow.end(), greater<int>());
  sort(purchase.begin(), purchase.end(), greater<pair<int, int>>());
  sort(rental.begin(), rental.end(), greater<int>());

  vector<ll> f(n + 1, 0), g(n + 1, 0);
  for (int i = 0; i < n; i++) {
    g[i + 1] = g[i] + rental[i];
  }
  for (int i = 0; i < n; i++) {
    f[i + 1] = f[i];
    while (true) {
      if (purchase[0].second > cow[i]) {
        f[i + 1] += cow[i] * purchase[0].first;
        purchase[0].second -= cow[i];
        cow[i] = 0;
        break;
      } else {
        f[i + 1] += purchase[0].second * purchase[0].first;
        cow[i] -= purchase[0].second;
        purchase.erase(purchase.begin());
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    // cout << f[i] << " " << g[n - i] << endl;
    ans = max(ans, (ll)f[i] + g[n - i]);
  }
  cout << ans << endl;
  return 0;
}