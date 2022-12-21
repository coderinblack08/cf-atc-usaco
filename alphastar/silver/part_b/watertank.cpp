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

int n, b;
int f[250], d[250], s[250];
bool vis[250][250];
int ans = 1e9;

void dfs(int loc, int boot) {
  if (vis[loc][boot]) return;
  vis[loc][boot] = true;

  if (loc == n - 1) {
    ans = min(ans, boot);
    return;
  }

  for (int next_loc = loc + 1; next_loc < n && next_loc - loc <= d[boot]; next_loc++) {
    if (f[next_loc] <= s[boot]) {
      dfs(next_loc, boot);
    }
  }

  for (int next_boot = boot + 1; next_boot < b; next_boot++) {
    if (f[loc] <= s[next_boot]) {
      dfs(loc, next_boot);
    }
  }
}

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < b; i++) {
    cin >> s[i] >> d[i];
  }
  dfs(0, 0);
  cout << ans;
  return 0;
}