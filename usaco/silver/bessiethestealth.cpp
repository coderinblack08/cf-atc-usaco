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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)                                                            \
  cerr << "[" << #x << "] = [";                                                \
  _print(x)
#else
#define debug(x...)
#endif

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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  // binary search for kth pair's sum
  int lo = a[0] * 2, hi = a[n - 1] * 2 + 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    // pairs above or equal
    int cnt = 0;
    for (int l = 0, r = n - 1; l < n; l++) {
      while (r >= 0 && a[l] + a[r] >= mid) {
        r--;
      }
      cnt += n - r - 1;
    }
    debug(lo, hi, mid, cnt);
    if (cnt >= k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  int target = lo - 1;
  debug(target);
  ll total = 0;
  int found = 0;

  vector<int> p(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    p[i] = p[i + 1] + a[i];
  }

  // sums that are greater than target
  for (int  l = 0, r = n - 1; l < n; l++) {
    while (r >= 0 && a[l] + a[r] > target) {
      r--;
    }
    total += p[r + 1] + ((n - 1) - r) * a[l];
    found += n - r - 1;
  }

  // sums that are equal to target
  int remaining = k - found;
  for (int  l = 0, r = n - 1; l < n; l++) {
    while (r >= 0 && a[l] + a[r] > target) {
      r--;
    }
    for (int temp = r; temp >= 0; temp--) {
      if (a[l] + a[temp] == target) {
        total += target;
        remaining--;
        if (remaining == 0) {
          cout << total << endl;
          return 0;
        }
      }
    }
  }

  cout << total << endl;
  return 0;
}
