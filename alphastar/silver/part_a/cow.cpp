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
  int n;  // leq 1e5
  string cow_s;
  cin >> n >> cow_s;
  ll cow = 0, co = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (cow_s[i] == 'W') {
      cow += co;
    } else if (cow_s[i] == 'O') {
      co += c;
    } else {
      c++;
    }
  }
  cout << cow;
  return 0;
}