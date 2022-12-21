#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define ll long long
using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  vector<pair<int, int>> intervals(n);
  for (int i = 0; i < n; i++) {
    cin >> intervals[i].first >> intervals[i].second;
  }
  vector<ll> win_start(2 * m + 1), win_end(2 * m + 1);
  // slow: O(n^2 + m)
  // for (auto [a_i, b_i] : intervals) {
  //   for (auto [a_j, b_j] : intervals) {
  //     win_start.at(a_i + a_j)++;
  //     win_end.at(b_i + b_j)++;
  //   }
  //  }
  //  fast: O(m^2 + n)
  vector<ll> a_freq(m + 1), b_freq(m + 1);
  for (int i = 0; i < n; i++) a_freq.at(intervals[i].first)++, b_freq.at(intervals[i].second)++;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      win_start.at(i + j) += a_freq.at(i) * a_freq.at(j);
      win_end.at(i + j) += b_freq.at(i) * b_freq.at(j);
    }
  }
  ll win_count = 0;
  for (int i = 0; i <= 2 * m; i++) {
    win_count += win_start.at(i);
    cout << win_count << endl;
    win_count -= win_end.at(i);
  }
  return 0;
}
