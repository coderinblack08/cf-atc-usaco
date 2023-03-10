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

const int MOD = 998244353;

int mod_inverse(int a) {
  int b = MOD, u = 1, v = 0;
  while (b) {
    int t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}

int main() {
  int q;
  cin >> q;

  queue<pair<ll, ll>> F;
  ll c_factor = 0;
  ll x_factor = 1;

  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      ll a, b;
      cin >> a >> b;

      c_factor = (a * c_factor + b) % MOD;
      x_factor = (a * x_factor) % MOD;

      F.push(mp(a, b));
    }
    if (t == 1) {
      auto [a, b] = F.front();
      x_factor = (x_factor * mod_inverse(a)) % MOD;
      c_factor = (c_factor - b * x_factor) % MOD;
      F.pop();
    }
    if (t == 2) {
      ll x;
      cin >> x;
      if (F.empty()) cout << x << endl;
      else cout << (c_factor + x * x_factor) % MOD << endl;
    }
  }

  return 0;
}
