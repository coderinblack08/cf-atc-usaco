#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x % m]++;
    }
    int ans = 0;
    for (auto &c : cnt) {
      if (c.first == 0) {
        ans++;
      } else if (2 * c.second == m) {
        ans++;
      } else if (2 * c.first < m || cnt.find(m - c.first) == cnt.end()) {
        int x = c.second;
        int y = cnt[m - c.first];
        ans += 1 + max(0, abs(x - y) - 1);
      }
    }
    cout << ans << endl;
  }
}