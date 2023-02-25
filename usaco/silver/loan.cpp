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

ll n, m;

bool check(ll x, ll k) {
  ll g = 0;
  while (k > 0 && g < n) {
    ll y = (n - g) / x;
    if (y < m) {
      // add m-1 beacuse of rounding down
      ll left = (n - g + m - 1) / m;
      return left <= k;
    }
    ll maxmatch = n - x * y; // n minus multiple of x
    ll numdays = (maxmatch - g) / y + 1;
    if (numdays > k) numdays = k;
    g += y * numdays;
    k -= numdays;
  }
  return g >= n;
}

int main() {
  setIO("loan");
  ll k;
  cin >> n >> k >> m;
  ll lo = 0, hi = n + 1;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (check(mid, k)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << lo - 1 << endl;
  return 0;
}
