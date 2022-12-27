#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int i = 0; i < n; i++) cin >> a[i];
  b = a;
  map<int, int> mp;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) mp[b[i]] = i;
  for (int i = 0; i < n; i++) a[i] = mp[a[i]];
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != i) {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != i) {
      r = i;
      break;
    }
  }
  if (l == -1 || r == -1) {
    cout << "yes\n1 1\n";
    return 0;
  }
  reverse(a.begin() + l, a.begin() + r + 1);
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != i) {
      ok = false;
      break;
    }
  }
  if (ok) cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
  else cout << "no\n";
  return 0;
}
