#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int last_true(int lo, int hi, function<bool(int)> f) {
  lo--;
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (f(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

int n, k;
vector<int> a;

bool check(int x) {
  auto it = lower_bound(all(a), x);
  auto mid = a.begin() + n / 2;

  if (it - mid < 0) return true;

  ll ops = 0;
  for (auto i = mid; i != it; i++) {
    ops += x - *i;
  }
  return ops <= k;
}

// bool check(int x) {
//   ll ops = 0;
//   for (int i = n / 2; i < n; i++) {
//     ops += max(0, x - a[i]);
//   }
//   return ops <= k;
// }

int main() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  cout << last_true(1, 2e9, check);
  return 0;
}