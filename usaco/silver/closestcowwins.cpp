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
  setIO();
  int n, m, k;
  cin >> k >> m >> n;
  vector<pair<int, int>> patches(k);
  vector<int> nhoj(m), vals;
  for (int i = 0; i < k; i++) {
    cin >> patches[i].first >> patches[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> nhoj[i];
  }
  sort(all(patches));
  sort(all(nhoj));

  // leftmost interval
  vals.push_back(0);
  int i = 0;
  while (i < k) {
    if (patches[i].first > nhoj[0]) break;
    vals[0] += patches[i].second;
    i++;
  }

  // m - 1 intervals
  for (int j = 0; j < m - 1; j++) {
    vals.push_back(0);
    // first-half of interval (j, j + 1)
    while (i < k && patches[i].first < (nhoj[j + 1] + nhoj[j]) / 2) {
      vals[size(vals) - 1] += patches[i].second;
      i++;
    }
    // second-half of interval (j, j + 1)
    vals.push_back(0);
    while (i < k && patches[i].first < nhoj[j + 1]) {
      vals[size(vals) - 1] += patches[i].second;
      i++;
    }
  }

  // rightmost intervals
  vals.push_back(0);
  while (i < k) {
    vals[size(vals) - 1] += patches[i].second;
    i++;
  }

  sort(all(vals), greater<ll>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += vals[i];
  }

  cout << ans << endl;
  return 0;
}