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

struct Coord {
  int pos;
  int index;
  bool ending;
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<Coord> unfriendly_pairs;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    unfriendly_pairs.push_back({a, i, false});
    unfriendly_pairs.push_back({b, i, true});
  }
  sort(unfriendly_pairs.begin(), unfriendly_pairs.end(), [](Coord a, Coord b) {
    if (a.pos == b.pos) {
      return a.ending > b.ending;
    }
    return a.pos < b.pos;
  });
  set<int> curr_range;
  int ans = 1;
  for (auto p : unfriendly_pairs) {
    if (curr_range.count(p.index)) {
      curr_range.clear();
      curr_range.insert(p.index);
      ans++;
    } else {
      curr_range.insert(p.index);
    }
  }
  cout << ans;
  return 0;
}