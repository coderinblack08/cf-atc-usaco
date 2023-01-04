#include <bits/stdc++.h>
#include <climits>
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

const int N = 5e6+1;
bool is_prime[N];
int great_mod[4][N];

void sieve_of_eratosthenes(int n) {
  for (int i = 2; i <= n; i++) {
    is_prime[i] = true;
  }
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll john = LONG_LONG_MAX;
  ll nhoj = LONG_LONG_MAX;
  for (int i = 0; i < n; i++) {
    if (is_prime[a[i]]) {
      john = i;
      break;
    }
    if (a[i] % 4 == 0) {
      nhoj = min(nhoj, (a[i] / 4) * n + i);
      continue;
    }
    if (a[i] % 2 == 0) {
      john = min(john, (a[i] / 4) * n + i);
      continue;
    }
    // greatest prime <= a[i] such that same mod 4
    int gp = great_mod[a[i] % 4][a[i]];
    int new_cows = a[i] - gp;
    john = min(john, (ll) new_cows / 4 * n + i);
  }
  if (john <= nhoj) {
    cout << "Farmer John" << endl;
  } else {
    cout << "Farmer Nhoj" << endl;
  }
}

int main() { 
  setIO();
  sieve_of_eratosthenes(N);

  // greatest prime below that has same mod 4
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      great_mod[j][i] = great_mod[j][i - 1];
    }
    if (is_prime[i]) great_mod[i % 4][i] = i;
  }

  int t;
  cin >> t;
  while(t--) solve();

  return 0; }
