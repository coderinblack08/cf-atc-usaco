#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, vector<int>& d, int l, int r, int cur = 0) {
  if (r < l) {
    return;
  }
  if (l == r) {
    d[l] = cur;
    return;
  }
  int largest_index = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] > a[largest_index]) {
      largest_index = i;
    }
  }
  d[largest_index] = cur;
  solve(a, d, l, largest_index - 1, cur + 1);
  solve(a, d, largest_index + 1, r, cur + 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> d(n);
    solve(a, d, 0, n - 1);
    for (int x : d) cout << x << " ";
    cout << endl;
  }
}