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
  int n, k, b;
  cin >> n >> k >> b;
  vector<int> bridges(n + 1, 0);
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    bridges[x]++;
  }
  vector<int> p_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    p_sum[i] = p_sum[i - 1] + bridges[i];
  }
  int ans = 1e9;
  for (int i = 1; i <= n - k; i++) {
    ans = min(ans, p_sum[i + k] - p_sum[i]);
  }
  cout << ans;
  return 0;
}