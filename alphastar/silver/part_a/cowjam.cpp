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

struct Cow {
  int pos, speed;
  bool operator<(const Cow &c) const {
    if (speed == c.speed) return pos < c.pos;
    return speed < c.speed;
  }
};

int main() {
  int n;
  cin >> n;
  vector<Cow> cows(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].pos >> cows[i].speed;
  }
  sort(cows.begin(), cows.end());
  set<int> jams;
  for (int i = 0; i < n; i++) {
    if (jams.empty() || cows[i].pos > *jams.rbegin()) {
      jams.insert(cows[i].pos);
    }
  }
  cout << jams.size() << endl;
  return 0;
}