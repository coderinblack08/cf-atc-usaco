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
  setIO("fairphoto");
  int n;
  cin >> n;
  // case 1: only one breed
  // case 2: both breeds
  // observation: prefix sum of left and right endpoint must be equal for a
  // valid photograph O(n) sweep that matches the leftmost value and righmost
  // value using a map
  vector<pair<int, char>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v));
  vector<int> p_sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    p_sum[i + 1] = p_sum[i] + (v[i].second == 'H' ? 1 : -1);
  }
  // case 1:
  char curr_type = v[0].second;
  int left_pos = v[0].first;
  int best_picture = -1;
  for (int i = 1; i < n; i++) {
    if (v[i].second != curr_type) {
      best_picture = max(best_picture, v[i - 1].first - left_pos);
      curr_type = v[i].second;
      left_pos = v[i].first;
    }
  }
  // all cows have the same breed
  if (best_picture == -1) {
    best_picture = v[n - 1].first - v[0].first;
  }
  // case 2:
  map<int, int> first_seen;
  for (int i = 0; i < n; i++) {
    if (!first_seen.count(p_sum[i])) {
      first_seen[p_sum[i]] = v[i].first;
    }
    if (first_seen.count(p_sum[i + 1])) {
      auto prev = first_seen[p_sum[i + 1]];
      // cerr << "Bounds from " << v[i].first << " " << prev << endl;
      best_picture = max(best_picture, v[i].first - prev);
    }
  }
  cout << best_picture;
  return 0;
}
