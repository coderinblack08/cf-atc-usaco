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
  int n, t;
  cin >> n >> t;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> a[i];
  int curr = 0;
  while (curr < t - 1) {
    curr += a[curr];
  }
  if (curr == t - 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
