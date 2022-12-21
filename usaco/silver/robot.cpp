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

string set_to_string(set<int>& s) {
  string res;
  for (auto const& e : s) {
    res += e + ",";
  }
  res.pop_back();
  return res;
}

int n;
int xg, yg;
vector<pair<int, int>> A;
map<pair<ll, ll>, set<pair<string, int>>> V;

void solve(int x, int y, set<int> path) {
  V[{x, y}].insert({set_to_string(path), path.size()});
  for (int i = 0; i < n; i++) {
    if (path.count(i)) continue;
    path.insert(i);
    solve(x + A[i].first, y + A[i].second, path);
    path.erase(i);
  }
}

int main() {
  cin >> n;
  cin >> xg >> yg;
  A.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
  }
  solve(0, 0, {});
  for (auto const& s : V[{xg, yg}]) {
    // cout << s.first.first << "," << s.first.second << " " << s.second.size() << endl;
    cout << s.first << " " << s.second << endl;
  }
  return 0;
}