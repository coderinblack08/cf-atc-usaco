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

int dfs(int start, int end) {
  if (end - start == 1) return start * end;
  if (start == end) return 0;
  int mid = (start + end) / 2;
  return dfs(start, mid) + dfs(mid + 1, end);
}

int main() {
  int n;
  cin >> n;
  cout << dfs(1, n);
  return 0;
}