#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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

int n, k, l;
int c[100001];

bool ok(int h) {
  int count = 0;
  for (int i = 0; i < h; i++) {
    if (h - c[i] > 0) {
      count += h - c[i];
      if (h - c[i] > k) {
        return false;
      }
    }
  }
  if (count > k * l) {
    return false;
  }
  return true;
}

int main() {
  setIO();
  cin >> n >> k >> l;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c, c + n, greater<int>());
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ok(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << endl;
  return 0;
}