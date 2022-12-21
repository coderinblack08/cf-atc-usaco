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
  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; i++) {
    cin >> coords[i].first >> coords[i].second;
  }
  // 3H
  set<int> y_set;
  for (int i = 0; i < n; i++) {
    y_set.insert(coords[i].second);
  }
  if (y_set.size() <= 3) {
    cout << 1 << endl;
    return 0;
  }
  // 3V
  set<int> x_set;
  for (int i = 0; i < n; i++) {
    x_set.insert(coords[i].first);
  }
  if (x_set.size() <= 3) {
    cout << 1 << endl;
    return 0;
  }
  // 2H 1V
  map<int, int> y_mp, x_mp;
  for (int i = 0; i < n; i++) {
    x_mp[coords[i].first]++;
    y_mp[coords[i].second]++;
  }
  std::sort(coords.begin(), coords.end());
  int pr = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0 && coords[i].first != coords[i - 1].first) {
      for (int j = pr; j < i; j++) {
        y_mp[coords[j].second]--;
      }
      int lines = 0;
      for (auto &p : y_mp) {
        if (p.second > 0) lines++;
      }
      if (lines <= 2) {
        cout << 1 << endl;
        return 0;
      }
      for (int j = pr; j < i; j++) {
        y_mp[coords[j].second]++;
      }
      pr = i;
    }
  }
  // 2V 1H
  std::sort(coords.begin(), coords.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  });
  pr = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0 && coords[i].second != coords[i - 1].second) {
      for (int j = pr; j < i; j++) {
        x_mp[coords[j].first]--;
      }
      int lines = 0;
      for (auto &p : x_mp) {
        if (p.second > 0) lines++;
      }
      if (lines <= 2) {
        cout << 1 << endl;
        return 0;
      }
      for (int j = pr; j < i; j++) {
        x_mp[coords[j].first]++;
      }
      pr = i;
    }
  }
  cout << 0 << endl;
  return 0;
}
