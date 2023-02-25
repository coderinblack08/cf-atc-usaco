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

/*
OW -> WCCO -> WO (you can swap neighborring letters)
you can rearrange the word however you want

we can test based on parity because order doens't matter
*/

int main() {
  setIO();
  string s;
  int q;
  cin >> s >> q;
  int n = sz(s);
  vi c(n + 1, 0), o(n + 1, 0), w(n + 1, 0);
  for (int i = 0; i < n; i++) {
    c[i + 1] = c[i] + (s[i] == 'C');
    o[i + 1] = o[i] + (s[i] == 'O');
    w[i + 1] = w[i] + (s[i] == 'W');
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int C = (c[r] - c[l - 1]) % 2;
    int O = (o[r] - o[l - 1]) % 2;
    int W = (w[r] - w[l - 1]) % 2;

    // (C O W)
    // (0 0 0) -> 0
    // (1 0 0) -> 1
    // (0 1 0) -> 0
    // (0 0 1) -> 0
    // (1 1 0) -> 0
    // (1 0 1) -> 0
    // (0 1 1) -> 1
    // (1 1 1) -> 0

    if ((C == 1 && O == 0 && W == 0) || (C == 0 && O == 1 && W == 1)) {
      cout << "Y";
    } else {
      cout << "N";
    }
  }
  cout << "\n";
  return 0;
}
