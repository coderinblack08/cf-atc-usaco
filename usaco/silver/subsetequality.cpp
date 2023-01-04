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
  setIO();
  string s, t;
  cin >> s >> t;
  map<char, int> s_freq, t_freq;
  for (char c : s)
    s_freq[c]++;
  for (char c : t)
    t_freq[c]++;
  vector<vector<bool>> works(18, vector<bool>(18, false));
  for (char i = 'a'; i <= 'r'; i++) {
    for (char j = i + 1; j <= 'r'; j++) {
      string new_s = "", new_t = "";
      for (char c : s) {
        if (c == i || c == j) {
          new_s += c;
        }
      }
      for (char c : t) {
        if (c == i || c == j) {
          new_t += c;
        }
      }
      if (new_t == new_s) {
        works[i - 'a'][j - 'a'] = true;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string subset;
    cin >> subset;
    if (sz(subset) == 1) {
      int s_sum = 0, t_sum = 0;
      for (char c : subset) {
        s_sum += s_freq[c];
        t_sum += t_freq[c];
      }
      if (s_sum != t_sum) {
        cout << 'N';
        continue;
      }
    }
    bool fails = false;
    for (int i = 0; i < sz(subset); i++) {
      for (int j = i + 1; j < sz(subset); j++) {
        if (!works[subset[i] - 'a'][subset[j] - 'a']) {
          fails = true;
          break;
        }
      }
    }
    if (!fails)
      cout << 'Y';
    else
      cout << 'N';
  }
  cout << endl;
  return 0;
}
