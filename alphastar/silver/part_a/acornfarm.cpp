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
  int n, a;
  cin >> n >> a;
  map<int, pair<int, int>> mp;
  multiset<int> output;
  map<int, int> track;
  for (int i = 0; i < n; i++) {
    int day, tree, diff;
    cin >> day >> tree >> diff;
    mp[day] = make_pair(tree, diff);
    output.insert(a);
    track[tree] = a;
  }
  int p_max = -1;
  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    // cout << it->first << endl;
    output.erase(output.find(track[it->second.first]));
    track[it->second.first] += it->second.second;
    output.insert(track[it->second.first]);
    auto c_max = *(--output.end());
    // cout << c_max << endl;
    if (p_max == -1 || (c_max >= track[p_max] && p_max != it->second.first)) {
      if (c_max == track[p_max]) {
        p_max = it->second.first;
        ans++;
      } else {
        p_max = it->second.first;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}