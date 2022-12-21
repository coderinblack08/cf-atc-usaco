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
  setIO("maxcross");
  int n, k, b;
  cin >> n >> k >> b;
  vector<int> road(n + 1, 0);
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    road[x]++;
  }
  for (int i = 1; i <= n; i++) road[i] += road[i - 1];
  int ans = INT_MAX;
  for (int i = 0; i <= n - k; i++) {
    ans = min(ans, road[i + k] - road[i]);
  }
  cout << ans << endl;
  return 0;
}