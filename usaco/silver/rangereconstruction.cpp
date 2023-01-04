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

const int N = 300 + 1;
int diff[N][N];

int main() {
  setIO();
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cin >> diff[i][j];
    }
  }

  a[0] = 0;
  a[1] = diff[0][1];

  for (int i = 2; i < n; i++) {
    if (diff[i - 1][i] == 0) {
      a[i] = a[i - 1];
      continue;
    }
    int hi = a[i - 1] + diff[i - 1][i];
    int lo = a[i - 1] - diff[i - 1][i];
    bool found_diff = false;
    for (int p = i - 2; p >= 0; p--) {
      if (a[p] != a[p + 1]) {
        int range_hi = max(max(a[p], a[p + 1]), hi) - min(min(a[p], a[p + 1]), hi);
        int range_lo = max(max(a[p], a[p + 1]), lo) - min(min(a[p], a[p + 1]), lo);
        if (range_hi == diff[p][i]) {
          a[i] = hi;
        } else {
          a[i] = lo;
        }
        found_diff = true;
        break;
      }
    }
    if (!found_diff) {
      // all elements before are equal
      a[i] = hi;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i != n - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
