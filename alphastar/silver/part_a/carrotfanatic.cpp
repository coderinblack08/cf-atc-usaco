// same as silver diamond collector i believe

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
  int n, k;
  cin >> n >> k;
  vector<int> carrots(n);
  for (int i = 0; i < n; i++) cin >> carrots[i];
  sort(all(carrots));
  // left max, right max arrays
  // define low
  // high 0 -> N
  //  update low such that it stays within K
  //  find new size
  //  compare to  left max [high - 1]
  vector<int> l_max(n);
  for (int l = 0, r = 0; r < n; r++) {
    while (l < r && carrots[r] - carrots[l] > k) l++;
    l_max[r] = max(r - l + 1, l_max[r - 1]);
  }
  vector<int> r_max(n + 1);
  r_max[n] = 0;
  for (int l = n - 1, r = n - 1; l >= 0; l--) {
    while (r > l && carrots[r] - carrots[l] > k) r--;
    r_max[l] = max(r - l + 1, r_max[l + 1]);
  }
  int ans = 0;
  for (int div = 0; div < n - 1; div++) {
    // cout << l_max[div] << " " << r_max[div + 1] << endl;
    ans = max(ans, l_max[div] + r_max[div + 1]);
  }
  cout << ans;
  return 0;
}
