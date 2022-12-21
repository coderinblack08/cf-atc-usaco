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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> john(n), jane(m);
  for (int i = 0; i < n; i++) {
    cin >> john[i].first >> john[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> jane[i].first >> jane[i].second;
  }
  int ans = 0;
  int john_count = 0, jane_count = 0;
  bool started = false;
  while (true) {
    if (john.size() == 0 || jane.size() == 0) {
      break;
    }
    if (john[0].second == 0) {
      john.erase(john.begin());
      john_count++;
    }
    if (jane[0].second == 0) {
      jane.erase(jane.begin());
      jane_count++;
    }
    john[0].second--;
    jane[0].second--;
    bool john_faster = john_count > jane_count;
    john_count += john[0].first;
    jane_count += jane[0].first;
    if (started && ((john_faster && jane_count > john_count) || (!john_faster && jane_count < john_count))) {
      ans++;
    }
    started = true;
  }
  cout << ans;
  return 0;
}