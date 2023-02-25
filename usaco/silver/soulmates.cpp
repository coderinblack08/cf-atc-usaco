#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
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

// intuition for solution?

int solve() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    return 0;
  }
  vector<ll> div1 = {a}, div2 = {b};
  while (a > 1) {
    if (a % 2) a++;
    else a /= 2;
    div1.pb(a);
  }
  div1.pb(1);
  while (b > 1) {
    if (b % 2) b--;
    else b /= 2;
    div2.pb(b);
  }
  div2.pb(1);
  ll ans = LLONG_MAX;
  for (int i = 0; i < sz(div1); i++) {
    for (int j = 0; j < sz(div2); j++) {
      if (div1[i] < div2[j]) {
        ans = min(ans, div2[j] - div1[i] + i + j);
      }
    }
  }
  return ans;
}

int main() {
  setIO();
  int t; cin >> t;
  while (t--) cout << solve() << "\n";
  return 0;
}
