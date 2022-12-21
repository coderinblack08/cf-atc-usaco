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
  vector<int> paw(n + 1, 0), ear(n + 1, 0), tail(n + 1, 0);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    paw[i + 1] = paw[i];
    ear[i + 1] = ear[i];
    tail[i + 1] = tail[i];
    if (c == 'P') paw[i + 1]++;
    if (c == 'E') ear[i + 1]++;
    if (c == 'T') tail[i + 1]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, paw[i] + ear[n] - ear[i]);
    ans = max(ans, paw[i] + tail[n] - tail[i]);
    ans = max(ans, tail[i] + paw[n] - paw[i]);
    ans = max(ans, tail[i] + ear[n] - ear[i]);
    ans = max(ans, ear[i] + paw[n] - paw[i]);
    ans = max(ans, ear[i] + tail[n] - tail[i]);
  }
  cout << ans << endl;
  return 0;
}