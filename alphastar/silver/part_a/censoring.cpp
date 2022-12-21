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

int main() {
  string s, t;
  cin >> s >> t;
  string a = "";
  for (int i = 0; i < s.size(); i++) {
    a += s[i];
    if (a.size() >= t.size()) {
      // cerr << i << " "
      //      << " " << a << " " << a.substr(a.size() - t.size(), t.size()) << endl;
      if (a.substr(a.size() - t.size(), t.size()) == t) {
        a.erase((a.size() - t.size()), t.size());
      }
    }
  }
  cout << a;
  return 0;
}