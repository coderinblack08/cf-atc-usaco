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

int n;
vector<int> gifts[501];
bitset<501> reachable[501];

void dfs(int src, int curr) {
  if (reachable[src][curr]) return;
  reachable[src][curr] = true;
  for (int g : gifts[curr]) dfs(src, g);
}

void calc_reachable() {
  for (int i = 1; i <= n; i++) dfs(i, i);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    gifts[i].resize(n);
    for (int &g : gifts[i]) cin >> g;
    while (gifts[i].back() != i) gifts[i].pop_back();
  }
  calc_reachable();
  for (int i = 1; i <= n; i++) {
    for (int g : gifts[i]) {
      if (reachable[g][i]) {
        cout << g << endl;
        break;
      }
    }
  }
  return 0;
}