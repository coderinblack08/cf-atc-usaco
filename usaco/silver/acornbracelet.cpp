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
  string s;
  cin >> s;

  int ans = 0;
  int depth = 0;    // depth = opening - closing
  int closing = 0;  // since last time with depth = 1
  int opening = 0;

  // ()(())()
  // ())(
  // (()()(

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      depth++;
      opening++;
    } else if (s[i] == ')') {
      depth--;
      closing++;
    }
    if (depth <= 1) {
      opening = 0;
    }
    if (depth == -1) {
      ans = closing;
      break;
    }
  }

  if (depth > 0) {
    ans = opening;
  }

  cout << ans;
  return 0;
}