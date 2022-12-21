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

int len_of_s(int k) {
  int x;
  if (k == -1) return 0;
  return 2 * len_of_s(k - 1) + (k + 3);
}

char solve(int n, int k) {
  if (n > len_of_s(k)) return solve(n, k + 1);
  if (n <= len_of_s(k - 1)) return solve(n, k - 1);
  n -= len_of_s(k - 1);
  if (n <= k + 3) {
    if (n == 1)
      return 'm';
    else
      return 'o';
  }
  n -= k + 3;
  return solve(n, k - 1);
}

int main() {
  int n;
  cin >> n;
  cout << solve(n, 0);
  return 0;
}