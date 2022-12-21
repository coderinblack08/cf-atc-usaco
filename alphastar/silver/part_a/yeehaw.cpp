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

int interesting_numbers(ll start, ll end, int x) {
  int ans = 0;
  // base 1-9
  for (int b = 1; b <= 9; b++) {
    for (int i = 1; i <= 9; i++) {
      if (b == i) continue;
      for (int j = 0; j < x; j++) {
        string s = "";
        for (int k = 0; k < x; k++) s += to_string(b);
        s[j] = i + '0';
        if (atoll(s.c_str()) >= start && atoll(s.c_str()) <= end) {
          ans++;
        }
      }
    }
  }
  // base 0
  for (int i = 1; i <= 9; i++) {
    string s = "";
    s += to_string(i);
    for (int k = 0; k < x - 1; k++) s += '0';
    if (atoll(s.c_str()) >= start && atoll(s.c_str()) <= end) {
      ans++;
    }
  }
  // interesting 0
  for (int b = 1; b <= 9; b++) {
    for (int j = 1; j < x; j++) {
      string s = "";
      for (int k = 0; k < x; k++) s += to_string(b);
      s[j] = '0';
      if (atoll(s.c_str()) >= start && atoll(s.c_str()) <= end) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  string x, y;
  cin >> x >> y;
  int ans = 0;
  for (int i = x.size(); i <= y.size(); i++) {
    ans += interesting_numbers(atoll(x.c_str()), atoll(y.c_str()), i);
  }
  cout << ans << endl;
  return 0;
}