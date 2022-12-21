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

int n, a, b, c, d, e, f, g, h, m;

bool comp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first > b.first;
}

int modulo(int a, int b, int n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n; // multiplying with base
    }
    y = (y * y) % n; // squaring the base
    b /= 2;
  }
  return x % n;
}

int main() {
  cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
  pair<int, int> arr[n * 3];
  for (int i = 0; i < 3 * n; i++) {
    ll x = a * (ll)(modulo(i, 5, d)) + b * (ll)(modulo(i, 2, d)) + c;
    int w = x % d;
    x = e * (ll)(modulo(i, 5, h)) + f * (ll)(modulo(i, 3, h)) + g;
    int u = x % h;
    arr[i] = make_pair(u, w);
  }
  sort(arr, arr + 3 * n, comp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + arr[i].second) % m;
    // cout << arr[i].first << " " << arr[i].second << endl;
  }
  cout << ans;
  return 0;
}
