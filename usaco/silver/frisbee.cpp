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

int n;
ll ans = 0;

void add_contribution(const vector<int> &h) {
  vector<int> with_h(n + 1);
  for (int i = 0; i < n; i++) {
    with_h[h[i]] = i;
  }
  set<int> present;
  for (int cur = n; cur > 0; cur--) {
    auto it = present.insert(with_h[cur]).first;
    if (next(it) != end(present)) ans += *next(it) - *it + 1;
  }
}

int main() {
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  add_contribution(h);
  reverse(h.begin(), h.end());
  add_contribution(h);
  cout << ans << endl;
  return 0;
}