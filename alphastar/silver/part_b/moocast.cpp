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
  int x, y, power;
};

int n;
vector<Cow> cows;
set<int> vis;

void dfs(int i) {
  if (vis.count(i)) return;
  vis.insert(i);
  for (int j = 0; j < n; j++) {
    if (pow(abs(cows[i].x - cows[j].x), 2) + pow(abs(cows[i].y - cows[j].y), 2) <= pow(cows[i].power, 2)) {
      dfs(j);
    }
  }
}

int main() {
  cin >> n;
  assert(n <= 200);
  cows.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> cows[i].x >> cows[i].y >> cows[i].power;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vis.clear();
    dfs(i);
    ans = max(ans, (int)vis.size());
  }
  cout << ans;
  return 0;
}