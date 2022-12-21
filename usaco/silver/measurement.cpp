
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

struct Measurement {
  int day;
  int cow;
  int change;
};

int main() {
  setIO("measurement");
  int n, a;
  cin >> n >> a;
  vector<Measurement> measurements(n);
  for (auto &m : measurements) {
    cin >> m.day >> m.cow >> m.change;
  }
  sort(all(measurements), [](const Measurement &a, const Measurement &b) { return a.day < b.day; });
  map<int, int, greater<int>> counts;
  counts[0] = n + 1;
  int ans = 0;
  map<int, int> mp;
  for (auto &m : measurements) {
    int &curr = mp[m.cow];

    bool was_leader = curr == counts.begin()->first;
    int old_count = counts[curr]--;
    if (old_count) counts.erase(curr);

    curr += m.change;

    int new_count = ++counts[curr];
    bool is_still_leader = curr == counts.begin()->first;

    if (was_leader) {
      // ignore if current case is a tie between multiple cows
      if (!is_still_leader || old_count != 1 || new_count != 1) {
        ans++;
      }
    } else if (is_still_leader) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}